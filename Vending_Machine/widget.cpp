#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initButton();
}

Widget::~Widget()
{
    checkChange();
    delete ui;
}


void Widget::initButton(){
    ui->pbCoffee->setDisabled(true);
    ui->pbTea->setDisabled(true);
    ui->pbGongcha->setDisabled(true);
}

void Widget::insertCoin(int n){
    money+=n;

    checkScreen();
}
void Widget::payMoney(int n){
    if(ui->pbCoffee->isEnabled()) money+=n;
    else if(ui->pbTea->isEnabled()) money+=n;
    else if(ui->pbGongcha->isEnabled()) money+=n;
    else ;
    checkScreen();
}
void Widget::checkScreen(){
    if(money>=100)ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setDisabled(true);

    if(money>=150)ui->pbTea->setEnabled(true);
    else ui->pbTea->setDisabled(true);

    if(money>=200)ui->pbGongcha->setEnabled(true);
    else ui->pbGongcha->setDisabled(true);

    ui->lcdNumber->display(QString::number(money));
}

void Widget::checkChange(){
    int change500;
    int change100;
    int change50;
    int change10;

    change500=money/500;
    money=money%500;
    change100=money/100;
    money=money%100;
    change50=money/50;
    money=money%50;
    change10=money/10;
    money=money%10;

    QString warning;
    warning.append("500won : "+QString::number(change500)+"\n100won : "+QString::number(change100));
    warning.append("\n50won : "+QString::number(change50)+"\n10won : "+QString::number(change10));

    QMessageBox msg;
    msg.information(nullptr,"Please take your change.",warning);

}

void Widget::on_pb10_clicked()
{
    insertCoin(10);
}
void Widget::on_pb50_clicked()
{
    insertCoin(50);
}
void Widget::on_pb100_clicked()
{
    insertCoin(100);
}
void Widget::on_pb500_clicked()
{
    insertCoin(500);
}

void Widget::on_pbCoffee_clicked()
{
    payMoney(-100);
}
void Widget::on_pbTea_clicked()
{
    payMoney(-150);
}
void Widget::on_pbGongcha_clicked()
{
    payMoney(-200);
}
