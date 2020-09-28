#include "Budget.h"
#include <QString>
#include <QDebug>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QDate>

Budget::Budget(QWidget *parent) : QMainWindow(parent)
{
    resize(500,300);

    static int isBegin=1;

    if(isBegin==1){

        button_save.setParent(this);
        button_save.setText("保存");
        button_save.move(100,200);
        button_save.resize(100,30);
        button_save.show();

        button_cancel.setParent(this);
        button_cancel.setText("关闭");
        button_cancel.move(300,200);
        button_cancel.resize(100,30);
        button_cancel.show();

        label_prompt.setText("请输入本月支出预算：");
        label_prompt.setParent(this);
        label_prompt.move(100,100);
        label_prompt.resize(150,18);
        label_prompt.show();

        QRegExp double_rx("100|([0-9]{0,6}[.][0-9]{1,3})");// 限定输入值是小于100000的浮点数或整数
        lineEdit_money.setValidator(new QRegExpValidator(double_rx,this));

        lineEdit_money.setParent(this);
        lineEdit_money.move(250,100);
        lineEdit_money.resize(135,21);
        lineEdit_money.show();

        connect(&button_save,&QPushButton::clicked,this,&Budget::sendSlot);
        connect(&button_cancel,&QPushButton::clicked,this,&Budget::sendcancel);
        isBegin=0;
    }
    else{
        QDateTime dateTime = QDateTime::currentDateTime();
        QString date = dateTime.toString("yyyy-MM-dd");
        if(date[9]=='1'&&date[8]=='0'){
            isBegin = 0;
        }
    }
}

void Budget::sendSlot(){
    QString monthMoney;
    monthMoney=lineEdit_money.text();
    double num=monthMoney.toDouble();
    //qDebug()<<num;
    emit mySignal(num);
}

void Budget::sendcancel()
{
    emit CANCEL();
}
