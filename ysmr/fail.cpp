#include "fail.h"
#include<QPainter>
#include<QPushButton>
#include<QLabel>

fail::fail(QWidget *parent)
    : QWidget{parent}
{
    resize(1700,900);
    QPushButton* btn=new QPushButton(this);
    btn->setParent(this);
    btn->setFixedSize(180,50);
    btn->move(800,800);
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(18);
    font.setBold(true);
    QLabel* lab=new QLabel(this);
    lab->setParent(this);
    lab->setFixedSize(225,50);
    lab->move(775,8);
    lab->setFont(font);
    lab->setStyleSheet("QPushButton{color:black}");
    lab->setStyleSheet("background-color: gold");
    lab->setText("干点正事吧，旅行者");
    // 设置按钮的字体
    btn->setFont(font);
    btn->setStyleSheet("QPushButton{color:black}");
    btn->setStyleSheet("background-color: gold");
    btn->setText("退出游戏");
    connect(btn,&QPushButton::clicked,this,&QWidget::close);
}

void fail::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.drawPixmap(0,0,1700,900,QPixmap(":/fail.png"));
}
