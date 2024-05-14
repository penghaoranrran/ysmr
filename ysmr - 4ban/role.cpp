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
            if((jian.last()->m_currentPos.rx()-jian_temp->m_currentPos.rx())*(jian.last()->m_currentPos.rx()-jian_temp->m_currentPos.rx())
                    +(jian.last()->m_currentPos.ry()-jian_temp->m_currentPos.ry())*
                          (jian.last()->m_currentPos.ry()-jian_temp->m_currentPos.ry())
                >=400*400)
            {
                if(jian.size()>=1){
                    arrow* arr=jian.at(0);
                    delete arr;
                    jian.removeAt(0);
                }
                jian<<jian_temp;
                // qDebug()<<"6"<<" "<<jian.size();
            }
        }
        else {
            jian<<jian_temp;
            // qDebug()<<"2"<<"afknd";
        }
        foreach (arrow* arr, jian) {
            arr->move();
        }
        jian_temp=nullptr;
        // qDebug()<<target->mx<<" "<<target->my<<"role";
    // });
}
