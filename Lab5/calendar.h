#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QTime>
#include <QTimer>

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void update_time();

private:
    Ui::Calendar *ui;
    QTimer* timer;
};

#endif // CALENDAR_H
