#include "result.h"
#include "ui_result.h"

#include <QFileDialog>
#include <QtAxContainer/QAxObject>

Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    create_student_list();
    connection();
}

Result::~Result()
{
    delete ui;
}

void Result::find_data(QString FIO, QString group_number, int gender){
    table();
    bool isAlwaysRightFIO = FIO.isEmpty(),
        isAlwaysRightNumber = group_number.isEmpty(),
        isAlwaysRightGender = gender == 0;
    bool isRightFIO, isRightNumber, isRightGender;
    for (Student &student: students) {
        if (isAlwaysRightFIO) isRightFIO = true;
        else {
            if (student.get_fio().startsWith(FIO)) isRightFIO = true;
            else isRightFIO = false;
        }
        if (isAlwaysRightNumber) isRightNumber = true;
        else {
            if (student.get_group_number() == group_number) isRightNumber = true;
            else isRightNumber = false;
        }
        if (isAlwaysRightGender) isRightGender = true;
        else {
            if (student.get_gender() == gender) isRightGender = true;
            else isRightGender = false;
        }
        if (isRightFIO && isRightNumber && isRightGender) {
            for (Subject &s: student.get_subjects()) {

                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0,
                                         new QTableWidgetItem(student.get_fio()));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1,
                                         new QTableWidgetItem(s.get_name()));
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2,
                                         new QTableWidgetItem(QString::number(s.get_mark())));
            }

        }
    }
}

void Result::save_data(){
    QString filepath = QFileDialog::getSaveFileName(this, tr("Save"), ".", tr(" (*.xlsx)"));
    if (!filepath.isEmpty()) {
        QAxObject *excel = new QAxObject(this);
        excel->setControl("Excel.Application");
        excel->dynamicCall("SetVisible (bool Visible)", "false");
        excel->setProperty("DisplayAlerts", false);
        QAxObject *workbooks = excel->querySubObject("WorkBooks");
        workbooks->dynamicCall("Add");
        QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
        QAxObject *worksheets = workbook->querySubObject("Sheets");
        QAxObject *worksheet = worksheets->querySubObject("Item(int)", 1);
        for (int i = 1; i < ui->tableWidget->columnCount() + 1; i++) {
            QAxObject *Range = worksheet->querySubObject("Cells(int,int)", 1, i);
            Range->dynamicCall("SetValue(const QString &)", ui->tableWidget->horizontalHeaderItem(i - 1)->text());
        }
        for (int i = 1; i < ui->tableWidget->rowCount() + 1; i++) {
            for (int j = 1; j < ui->tableWidget->columnCount() + 1; j++) {
                QAxObject *Range = worksheet->querySubObject("Cells(int,int)", i + 1, j);
                Range->dynamicCall("SetValue(const QString &)",
                                   ui->tableWidget->item(i - 1, j - 1)->data(Qt::DisplayRole).toString());
            }
        }
        workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filepath));
        workbook->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        delete excel;
        excel = nullptr;
    }
}

void Result::table(){
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(
        QStringList() << tr("ФИО") << tr("Дисциплина") << tr("Оценка"));
                                                              ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->setColumnWidth(0, 293);
        ui->tableWidget->setColumnWidth(1, 293);
        ui->tableWidget->setColumnWidth(2, 240);
        ui->tableWidget->setSortingEnabled(true);
        ui->tableWidget->setEditTriggers(static_cast<QFlag>(0));
}

void Result::connection(){
    connect(ui->ExportButton, SIGNAL(clicked(bool)), this, SLOT(save_data()));
}

void Result::create_student_list(){
    students.push_back(*(new Student("Дудко Максим", "1381", 1,
                         *(new QList<Subject>({*(new Subject("МатАн", 2)),
                                              *(new Subject("ВычМат", 2)),
                                              *(new Subject("АиСД", 4))})))));
    students.push_back(*(new Student("Мамин Роман", "1381", 1,
                         *(new QList<Subject>({*(new Subject("МатАн", 3)),
                                              *(new Subject("ВычМат", 4)),
                                              *(new Subject("АиСД", 5))})))));
    students.push_back(*(new Student("Таргонский Михаил", "1381", 1,
                         *(new QList<Subject>({*(new Subject("МатАн", 2)),
                                              *(new Subject("ВычМат", 2)),
                                              *(new Subject("АиСД", 4))})))));
    students.push_back(*(new Student("Новак Полина", "1381", 2,
                         *(new QList<Subject>({*(new Subject("МатАн", 4)),
                                              *(new Subject("ВычМат", 4)),
                                              *(new Subject("АиСД", 5))})))));
    students.push_back(*(new Student("Возмитель Влас", "1381", 1,
                         *(new QList<Subject>({*(new Subject("МатАн", 4)),
                                              *(new Subject("ВычМат", 4)),
                                              *(new Subject("АиСД", 4))})))));
}
