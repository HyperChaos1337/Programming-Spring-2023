#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(950, 500);
    show_widgets();
    call_widget();
    setCentralWidget(tabWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete calendar;
    delete search;
    delete result;

}

void MainWindow::tab_enable(bool flag){
    tabWidget->setTabEnabled(1, flag);
}

void MainWindow::show_widgets(){

    tabWidget = new QTabWidget(this);
    tabWidget->setTabPosition(QTabWidget::North);

    calendar = new Calendar(this);
    search = new Search(this);
    result = new Result(this);

    tabWidget->addTab(search, "Поиск");
    tabWidget->addTab(result, "Результат");
    tabWidget->addTab(calendar, "Календарь");
    tabWidget->setTabEnabled(1, false);

}

void MainWindow::call_widget(){
    connect(search, SIGNAL(insert(bool)), this, SLOT(tab_enable(bool)));
    connect(tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(tab_number(int)));
    connect(search, SIGNAL(show_data(QString,QString,int)), this, SLOT(send_data(QString,QString,int)));
}

void MainWindow::tab_number(int num){
    if(num == 1) search->prepare();
}

void MainWindow::send_data(QString FIO, QString group_number, int gender){
    result->find_data(std::move(FIO), std::move(group_number), gender);
}
