#include "wayline.h"
#include<mymainwindow.h>
#include<QPainter>

wayline::wayline()
{
    head=nullptr;
}

void wayline::linking(QPoint pos){
        waypoint* newpoint = new waypoint(pos);
        newpoint->next = nullptr;
        if(head == nullptr)
        {
            head = newpoint;
        }
        else
        {
            waypoint* cur = head;
            for (; cur->next != nullptr;) {
                cur = cur->next;
            }
            cur->next = newpoint;
        }
}















