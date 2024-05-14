#include "arrow.h"
#include<QPropertyAnimation>
#include<collision.h>
#include<QPainter>
#include<QDebug>
#include<QtMath>
#include<QTimer>
#include<mymainwindow.h>

arrow::arrow(QPoint p1,monitor* b){
    start_pos=p1;
    m_currentPos=start_pos;
    guaiwu=b;
    int sx=p1.rx()+50;
    int sy=p1.ry()+50;
    int ex=b->mx+50;
    int ey=b->my+50;
    double s_e=sqrt((ex-sx)*(ex-sx)+(ey-sy)*(ey-sy));
    vx=(ex-sx)/s_e*speed;
    vy=(ey-sy)/s_e*speed;
}
void arrow::move(){
    QTimer* time=new QTimer;
    time->start(20);
    connect(time,&QTimer::timeout,[=]()mutable{
        m_currentPos.rx()+=vx;
        m_currentPos.ry()+=vy;
    });
}
