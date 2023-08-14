#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    money = 0;
    checkButtons();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    checkButtons();
}

void Widget::checkButtons() {
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    int num500 = money / 500; money %= 500;
    int num100 = money / 100; money %= 100;
    int num50 = money / 50; money %= 50;
    int num10 = money / 10; money %= 10;

    QString text = QString("500원: %1개\n100원: %2개\n50원: %3개\n10원: %4개").arg(num500).arg(num100).arg(num50).arg(num10);

    QMessageBox::information(this, "잔돈", text);
    changeMoney(-money); // Reset money
}
