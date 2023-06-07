#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

#include "calendar.h"
#include "search.h"
#include "result.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void tab_enable(bool flag);
    void tab_number(int num);
    void send_data(QString FIO, QString group_number, int gender);
private:

    Ui::MainWindow *ui;
    QTabWidget* tabWidget;
    Calendar* calendar;
    Search* search;
    Result* result;

    void show_widgets();
    void call_widget();

};
#endif // MAINWINDOW_H
