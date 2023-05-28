#ifndef STUDENT_H
#define STUDENT_H

#include "subject.h"
#include <QList>

class Student{
private:
    QString FIO;
    QList<Subject> subjects;
    QString group_number;
    int gender;
public:

    Student(const QString& FIO, QString group_number, int gender, QList<Subject> subjects);
    Student(const QString& FIO, QString group_number, int gender);
    Student();

    void set_fio(const QString& FIO);
    const QString& get_fio();

    void set_subjects(const QList<Subject>& subjects);
    QList<Subject>& get_subjects();

    void set_group_number(const QString& group_number);
    const QString& get_group_number();

    void set_gender(int gender);
    int get_gender();

};

#endif // STUDENT_H
