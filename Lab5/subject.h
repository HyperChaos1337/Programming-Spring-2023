#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>

class Subject
{
private:

    QString subject_name;
    int mark;

public:

    Subject();
    Subject(const QString& subject_name, int mark);
    int get_mark();
    void set_mark(int mark);
    const QString& get_name();
    void set_name(const QString& subject_name);

};

#endif // SUBJECT_H
