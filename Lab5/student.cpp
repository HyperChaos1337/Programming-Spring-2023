#include "student.h"

Student::Student(const QString &FIO, QString group_number, int gender, QList<Subject> subjects): FIO(FIO),
    group_number(group_number), gender(gender), subjects(subjects){}

Student::Student(const QString &FIO, QString group_number, int gender): FIO(FIO),
    group_number(group_number), gender(gender){}

Student::Student(){}

void Student::set_fio(const QString &FIO){
    this->FIO = FIO;
}
const QString& Student::get_fio(){
    return FIO;
}

void Student::set_subjects(const QList<Subject> &subjects){
    this->subjects = subjects;
}
QList<Subject>& Student::get_subjects(){
    return subjects;
}

void Student::set_group_number(const QString& group_number){
    this->group_number = group_number;
}
const QString& Student::get_group_number(){
    return group_number;
}

void Student::set_gender(int gender){
    this->gender = gender;
}
int Student::get_gender(){
    return gender;
}
