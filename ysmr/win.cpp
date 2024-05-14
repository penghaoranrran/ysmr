#include "win.h"
#include<QPainter>
#include<QPushButton>

win::win(QWidget *parent)
    : QWidget{parent}
{    //设置界面的大小
    resize(1700,900);
    QPushButton* btn=new QPushButton(this);
    btn->setParent(this);
    btn->setFixedSize(180,50);
    btn->move(800,800);
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(18);
    font.setBold(true);

    // 设置按钮的字体
    btn->setFont(font);
    btn->setStyleSheet("QPushButton{color:black}");
    btn->setStyleSheet("background-color: gold");
    btn->setText("退出游戏");
    connect(btn,&QPushButton::clicked,this,&QWidget::close);
}
void win::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.drawPixmap(0,0,1700,900,QPixmap(":/win.png"));
}
