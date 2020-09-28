#ifndef BUDGET_H
#define BUDGET_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>


class Budget : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton button_save;
    QPushButton button_cancel;
    QLabel label_prompt;
    QLineEdit lineEdit_money;

public:
    explicit Budget(QWidget *parent = nullptr);
    void sendSlot();

    void sendcancel();

signals:
    void mySignal();
    void mySignal(double);
    void CANCEL();

public slots:
    //void changeWin();

};

#endif // BUDGET_H
