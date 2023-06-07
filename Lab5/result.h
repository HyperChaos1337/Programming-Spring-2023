#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QTabWidget>
#include "student.h"

namespace Ui {
class Result;
}

class Result : public QWidget
{
    Q_OBJECT

public:

    explicit Result(QWidget *parent = nullptr);
    ~Result();

public slots:

    void save_data();

    void find_data(QString FIO, QString group_number, int gender);


private:

    Ui::Result *ui;
    QList<Student> students;
    void table();
    void create_student_list();
    void connection();

};

#endif // RESULT_H
