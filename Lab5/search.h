#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:

    explicit Search(QWidget *parent = nullptr);
    ~Search();

signals:

    void insert(bool isInserted);
    void show_data(QString FIO, QString group_number, int gender);

public slots:

    void InsertionSignal();

public:

    void prepare();

private:

    Ui::Search *ui;
    void connection();

};

#endif // SEARCH_H
