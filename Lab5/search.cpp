#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    connection();
}

Search::~Search()
{
    delete ui;
}

void Search::connection(){
    connect(ui->FIO_String, SIGNAL(textEdited(QString)), this, SLOT(InsertionSignal()));
    connect(ui->Group_String, SIGNAL(textEdited(QString)), this, SLOT(InsertionSignal()));
    connect(ui->isMen, SIGNAL(clicked(bool)), this, SLOT(InsertionSignal()));
    connect(ui->isWomen, SIGNAL(clicked(bool)), this, SLOT(InsertionSignal()));
}

void Search::InsertionSignal(){
    if(!ui->FIO_String->text().isEmpty() || !ui->Group_String->text().isEmpty()
        || ui->isWomen->isChecked() || ui->isMen->isChecked()) emit insert(true);
    else emit insert(false);
}

void Search::prepare(){
    int gender = 0;
    if(ui->isMen->isChecked()) gender = 1;
    if(ui->isWomen->isChecked()) gender = 2;
    emit show_data(ui->FIO_String->text(), ui->Group_String->text(), gender);
}
