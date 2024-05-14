#include "mywidget.h"
#include "ui_mywidget.h"
#include<QPainter>
#include<QPushButton>
#include<QIcon>
#include<QToolBar>


myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);

    //设置界面的大小
    resize(1700,900);

    //设置开始按钮
    QPushButton* start=new QPushButton();
    start->setParent(this);
    start->setFixedSize(180,50);
    start->move(800,800);
    QIcon temp(":/kaishi.png");
    start->setIcon(temp);
    start->setIconSize(QSize(200,50));

    //开始按钮的实现(结束登录界面，并打开游戏界面）
    mymainwindow* that=new mymainwindow;
    connect(start,&QPushButton::clicked,this,&QWidget::close);
    connect(start,&QPushButton::clicked,that,&mymainwindow::show);


}

//登录界面的绘制
void myWidget::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.drawPixmap(0,0,1700,900,QPixmap(":/denglu.png"));

}

myWidget::~myWidget()
{
    delete ui;
}
