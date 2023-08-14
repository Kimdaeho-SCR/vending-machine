#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    if(money<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbmilk->setEnabled(false);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::checkMoeny(){
    if(money >= 200){
        ui->pbmilk->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }else if(money >= 150){
        ui->pbmilk->setEnabled(false);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }else if(money >= 100){
        ui->pbmilk->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(true);
    }else{
        ui->pbmilk->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    checkMoeny();
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
    checkMoeny();
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
    checkMoeny();
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
    checkMoeny();
}



void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    checkMoeny();
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    checkMoeny();
}


void Widget::on_pbmilk_clicked()
{
    changeMoney(-200);
    checkMoeny();
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    int coin_500=0;
    int coin_100=0;
    int coin_50=0;
    int coin_10=0;
    char ad[50];
    coin_500=money/500;
    money %= 500;
    coin_100=money/100;
    money %= 100;
    coin_50=money/50;
    money %= 50;
    coin_10=money/10;
    sprintf(ad, "500 : %d, 100 : %d, 50 : %d, 10 : %d",coin_500, coin_100, coin_50, coin_10);
    changeMoney(-money);
    mb.information(this,"Title",ad);
}

