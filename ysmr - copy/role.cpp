#include "role.h"
#include<mymainwindow.h>
#include<arrow.h>
#include<QList>
#include<QTimer>

role::role(QPoint p,QString im)
{
    role_pos=p;
    mymainwindow* zhu=new mymainwindow();
    target=zhu->guaiwu;
    QList<arrow*> jian;
}

void role::creat_arrow(){
    // QTimer* timer=new QTimer(this);
    // timer->start(1000);
    // connect(timer,&QTimer::timeout,[=](){
        arrow* jian_temp=new arrow(role_pos,target);
        if(!jian.empty()){
            if((jian.last()->vx-jian_temp->vx)*(jian.last()->vx-jian_temp->vx)
                    +(jian.last()->vy-jian_temp->vy)*(jian.last()->vy-jian_temp->vy)>=100*100)
            jian<<jian_temp;
        }
        else {
            jian<<jian_temp;
        }
        foreach (arrow* arr, jian) {
            arr->move();
        }/*
    });*/
}
