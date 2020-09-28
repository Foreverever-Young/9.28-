#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Budget.h"

#include <QMainWindow>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QString>
#include <QDialog>
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include<QDataStream>
#include<QFile>

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
//    struct M{
//        double moneyType=0;
//        QString TYPE;
//        double percentage;
//    }m[100];
    QString InType;

    double budgetMoney;

    struct Bill{
        QString money;
        QString type;
        QDate date;
        QString remarks;
        bool moneyplus=false;
    }bill[100];

    QString Type[100];

    //Ui::MainWindow *ui;
    //QAction *action;
    //QMenu *menu;

    //void actions();

    Budget win;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QDialog dlg;

    void getMoney();

    void getType();

    void getInType();

    void getbill();

    void DouStr();

    void save_monthMoney(double);

    void cancel();

    void writeData();

    void readData();

    void writeType();

    void readType();

private slots:
    void on_book_2_clicked();

    void on_detail_clicked();

    void on_statistics_clicked();

    void on_button_addtype_clicked();

    void on_book_clicked();

    void show_bill();

    void on_clear_onetype_clicked();

    void on_Price_Sort_clicked();

    void on_Time_Sort_clicked();

    //void contextMenuEvent(QContextMenuEvent *event);

    //void actionClick();

    //void changeWin();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
