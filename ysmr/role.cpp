#include "role.h"
#include<mymainwindow.h>
#include<arrow.h>
#include<QList>
#include<QTimer>

role::role(QPoint p,QString im)
{
    role_pos=p;
}

void role::creat_arrow(monitor* temp){
    arrow* jian_temp=new arrow(role_pos,temp);
    if(!jian.empty()){
        if((jian.last()->m_currentPos.rx()-jian_temp->start_pos.rx())*(jian.last()->m_currentPos.rx()-jian_temp->start_pos.rx())
                +(jian.last()->m_currentPos.ry()-jian_temp->start_pos.ry())*
                      (jian.last()->m_currentPos.ry()-jian_temp->start_pos.ry())
            >=400*400)
        {
            if(jian.size()>=1){
                arrow* arr=jian.at(0);
                delete arr;
                jian.removeAt(0);
            }
            jian<<jian_temp;
        }
    }
    else {
        jian<<jian_temp;
    }
    foreach (arrow* arr, jian) {
        arr->move();
    }
    arrow* clear=jian_temp;
    jian_temp=nullptr;
}
