#include "mymainwindow.h"
#include<QToolBar>
#include<QPushButton>
#include<QLabel>
#include<QToolButton>
#include<QPainter>
#include<QWidget>
#include<QTimer>
#include<monitor.h>
#include<wayline.h>
#include<role.h>
#include<QVector>
#include<QDebug>
#include<QMouseEvent>
#include<arrow.h>
#include<QPropertyAnimation>
#include<QIcon>
#include<QtMath>


mymainwindow::mymainwindow(QWidget *parent)
    : QMainWindow{parent}
{
    //界面的大小与格式的设置
    resize(1700,900);
    QString styleSheet="QToolButton{min-width:50px;min-height:50px;}";
    QString styleSheet_2="QPushButton{min-width:50px;min-height:50px;}";

    //工具栏的设置
    QToolBar* bar=new QToolBar(this);
    addToolBar(bar);
    bar->setMovable(0);
    bar->setFixedHeight(100);

    //游戏介绍的设置
    QPushButton* intro=new QPushButton();
    // setParent(this);
    intro->setText("游戏介绍");
    intro->setStyleSheet(styleSheet_2);
    bar->addWidget(intro);

    //游戏背景的设置
    QPushButton* back=new QPushButton();
    back->setText("游戏背景");
    back->setStyleSheet(styleSheet_2);
    bar->addWidget(back);

    //空格以美观
    for(int i=0;i<200;i++)
    {
        QLabel* white=new QLabel();
        bar->addWidget(white);
    }

    //货币栏设置（原石数量在painterevent与鼠标点击重写里面实现）
    yuans=new QToolButton();
    QIcon temp(":/yuanshi.png");
    yuans->setIcon(temp);
    // yuans->setText(QString::number(ys));
    yuans->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    yuans->setStyleSheet(styleSheet);
    bar->addWidget(yuans);


    ////////////////////////////////////////游戏的主体设计/////////////////////////////////////////////////////////
    //航线的连接与赋值
    wayline* way_temp=new wayline();
    way_temp->linking(QPoint(350,350));
    way_temp->linking(QPoint(350,750));
    way_temp->linking(QPoint(750,750));
    way_temp->linking(QPoint(750,250));
    way_temp->linking(QPoint(1350,250));
    way_temp->linking(QPoint(1350,850));
    way_temp->linking(QPoint(1550,850));
    way=way_temp;

    //怪物的初始化与赋值
    monitor* guaiwu_temp=new monitor(350,350,400,":/lnl_4.png");
    guaiwu=guaiwu_temp;

    //计时器与怪物的运动（包括游戏的结束）
    QTimer *timer = new QTimer(this);
    timer->start(20000);
    connect(timer,&QTimer::timeout,[=](){
        static waypoint* cur=way->head;
        if(guaiwu->mx==cur->mpos.rx()&&guaiwu->my==cur->mpos.ry()){
            if(cur->next!=nullptr){
                cur=cur->next;
            }
            else{
                //设计一个游戏结束界面
            }
        }
        if(guaiwu->mx<cur->mpos.rx()&&guaiwu->my==cur->mpos.ry()){
            guaiwu->mx+=guaiwu->m_speed;
        }
        if(guaiwu->mx>cur->mpos.rx()&&guaiwu->my==cur->mpos.ry()){
            guaiwu->mx-=guaiwu->m_speed;
        }
        if(guaiwu->mx==cur->mpos.rx()&&guaiwu->my<cur->mpos.ry()){
            guaiwu->my+=guaiwu->m_speed;
        }
        if(guaiwu->mx==cur->mpos.rx()&&guaiwu->my>cur->mpos.ry()){
            guaiwu->my-=guaiwu->m_speed;
        }
    });


    for(int i=0;i<20;i++){
        mouse_x[i]=0;
        mouse_y[i]=0;
    }




}

void mymainwindow::timerEvent(QTimerEvent* ){

}

int mymainwindow::get_press_num(){
    qDebug()<<press_num<<"get";
    return press_num;
}

//重写鼠标点击事件
void mymainwindow::mousePressEvent(QMouseEvent *ev){
    if(ev->button()!=Qt::LeftButton||ys<160){
        return;
    }
    else{
        mouse_x[press_num]=ev->x()-(ev->x()%100);
        mouse_y[press_num]=ev->y()-(ev->y()%100);
        press_num++;
        ys-=160;
    }
}

//游戏背景
void mymainwindow::paintEvent(QPaintEvent*){
    int beijing[9][17]=
        {
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            0,0,1,1,1,1,1,2,2,2,2,2,2,2,1,1,3,
            0,0,1,1,1,1,1,2,1,1,1,1,1,2,1,1,4,
            0,0,1,2,1,1,1,2,1,1,1,1,1,2,1,1,5,
            0,0,1,2,1,1,1,2,1,1,1,1,1,2,1,1,6,
            0,0,1,2,1,1,1,2,1,1,1,1,1,2,1,1,3,
            0,0,1,2,2,2,2,2,1,1,1,1,1,2,1,1,4,
            0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,1,5,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        };
    QPainter painter(this);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<17;j++)
        {
            switch (beijing[i][j]) {
            case 0:
                painter.drawPixmap(100*j,100+100*i,100,100,QPixmap(":/shitou.png"));
                break;
            case 1:
                painter.drawPixmap(100*j,100+100*i,100,100,QPixmap(":/caodi.png"));
                break;
            case 2:
                painter.drawPixmap(100*j,100+100*i,100,100,QPixmap(":/tulu.png"));
                break;
            case 3:
                painter.drawPixmap(100*j,100+100*i,100,100,QPixmap(":/lnl_1.png"));
                break;
            case 4:
                painter.drawPixmap(100*j,100+100*i,100,100,QPixmap(":/lnl_2.png"));
                break;
            case 5:
                painter.drawPixmap(100*j,100+100*i,100,100,QPixmap(":/lnl_3.png"));
                break;
            case 6:
                painter.drawPixmap(100*j,100+100*i,100,100,QPixmap(":/lnl_4.png"));
                break;
            }
        }
    }
    draw_monitor(painter);//绘制航线
    draw_wayline(painter);//画出怪物
    draw_role(painter);//画出炮塔与选择框
    draw_arrow(painter);
    yuans->setText(QString::number(ys));
}

//绘制航线以判断航线是否正确，之后应当隐藏航线（未隐藏）
void mymainwindow::draw_wayline(QPainter& painter){
    painter.setPen(Qt::white);
    wayline way;
    way.linking(QPoint(350,350));
    way.linking(QPoint(350,750));
    way.linking(QPoint(750,750));
    way.linking(QPoint(750,250));
    way.linking(QPoint(1350,250));
    way.linking(QPoint(1350,850));
    way.linking(QPoint(1550,850));
    waypoint* cur=way.head;
    for(;cur->next!=nullptr;){
        painter.drawLine(cur->mpos,cur->next->mpos);
        cur=cur->next;
    }
}

//画出怪物
void mymainwindow::draw_monitor(QPainter& painter)
{
    painter.drawPixmap(guaiwu->mx, guaiwu->my, 100, 100, QPixmap(guaiwu->ImgPath));
}

//判断是否加入炮塔
bool mymainwindow::judge(QList<role*> n,role* m){
    foreach (role* rol, n) {
        if(rol->role_pos==m->role_pos)
            return false;
    }
    return true;
}

void mymainwindow::draw_arrow(QPainter& painter){
    foreach(QList<arrow*> jian, jian_total) {
        foreach (arrow* arr, jian) {
            painter.drawPixmap(arr->m_currentPos.rx(),arr->m_currentPos.ry(),30,30,QPixmap(arr->arrow_photo));
        }
    }
    // if(!jian.empty()){
    //     arrow* arr=jian.last();
    // }
    // foreach (arrow* arr, jian) {
    //     painter.drawPixmap(arr->m_currentPos.rx(),arr->m_currentPos.ry(),30,30,QPixmap(arr->arrow_photo));
    // }
}

//画出炮塔（点击直接生成）
void mymainwindow::draw_role(QPainter& painter){
    //画出炮塔并将其储存
    for(int i=0;i<press_num+1;i++){
        if(mouse_x[i]>=0){
            if(mouse_x[i]!=0){
                painter.drawPixmap(mouse_x[i],mouse_y[i],100,100,QPixmap(":/qidian.png"));
                role* role_temp=new role(QPoint(mouse_x[i],mouse_y[i]),":/qidian.png");
                if(!tower.empty()){
                    if(judge(tower,role_temp)){
                        tower<<role_temp;
                    }
                    // qDebug()<<tower.size();
                    //     for(int i=0;i<tower.size();++i){
                    //         qDebug()<<tower.at(i)->role_pos;
                    //     }
                }
                else{
                    tower<<role_temp;
                }
            }
        }
        update();
    }

    //完成攻击
    foreach (role* role_temp, tower) {
        role_temp->creat_arrow();
        // if(!jian_total.empty()){
        //     if(jian_total.last().last()->start_pos!=role_temp->jian.last()->start_pos)
        //         jian_total<<role_temp->jian;
        // }
        // else{
        // }
        jian_total<<role_temp->jian;
    }

}






// bool mymainwindow::eventFilter(QObject *watched, QEvent *event)
// {
//     QLabel* labal;
//     if(watched == labal && event->type() == QEvent::Paint)
//     {
//         showPaint(labal); //响应函数
//     }
//     return QWidget::eventFilter(watched,event);
// }
// //实现响应函数
// void mymainwindow::showPaint(QLabel* labal)
// {
//     QPainter painter(this);
//     painter.drawPixmap(labal->pos().rx(),labal->pos().ry(),110,10,QPixmap(":/qidian.png"));
//     qDebug()<<"2";
// }

// connect(time, SIGNAL(timeout()), this, SLOT(update()));

// if(!jian.empty()){
//     double rx=jian.last()->vx;
//     double ry=jian.last()->vy;
//     QTimer* time=new QTimer;
//     time->start(2000);
//     connect(time,&QTimer::timeout,jian.last(),[=]()mutable{
//         jian.last()->m_currentPos.rx()+=rx;
//         jian.last()->m_currentPos.ry()+=ry;
//     });
// }
