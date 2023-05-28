#include "subject.h"

Subject::Subject(){}

Subject::Subject(const QString &subject_name, int mark):subject_name(subject_name), mark(mark){}

int Subject::get_mark(){
    return mark;
}
const QString& Subject::get_name(){
    return subject_name;
}

void Subject::set_mark(int mark){
    this->mark = mark;
}
void Subject::set_name(const QString &subject_name){
    this->subject_name = subject_name;
}
