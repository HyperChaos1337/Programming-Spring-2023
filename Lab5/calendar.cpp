#include "calendar.h"
#include "ui_calendar.h"

Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_time()));
    timer->start();

}

void Calendar::update_time(){
    ui->label->setText(QTime::currentTime().toString("hh::mm::ss"));
}

Calendar::~Calendar()
{
    delete ui;
    delete timer;
}
