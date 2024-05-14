#include "collision.h"
#include<QPoint>

collision::collision(QObject *parent)
    : QObject{parent}
{}

bool collision::monitor_collision(QPoint p1,int a1,QPoint p2,int a2){
    int distance=(p1.rx()-p2.rx())*(p1.rx()-p2.rx()) + (p1.ry()-p2.ry())*(p1.ry()-p2.ry());
    if(distance<a1+a2){
        return 1;
    }
    return 0;
}
