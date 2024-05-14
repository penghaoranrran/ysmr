#include "monitor.h"
#include<wayline.h>
#include<waypoint.h>
#include<mymainwindow.h>

monitor::monitor(int x,int y,int bl,QString im)
{
    mx=x;
    my=y;
    QPoint chuan(mx,my);
    mp=chuan;
    blood=bl;
    ImgPath=im;
}


void monitor::move(wayline& temp)
{
    waypoint* cur=temp.head;
    for(;;)
    {
        if(mx==cur->mpos.rx()&&my==cur->mpos.ry()){
            cur=cur->next;
            break;
        }
        if(mx<cur->mpos.rx()&&my==cur->mpos.ry()){
            mx+=m_speed;
            break;
        }
        if(mx>cur->mpos.rx()&&my==cur->mpos.ry()){
            mx-=m_speed;
            break;
        }
        if(mx==cur->mpos.rx()&&my<cur->mpos.ry()){
            my+=m_speed;
            break;
        }
        if(mx==cur->mpos.rx()&&my>cur->mpos.ry()){
            mx-=m_speed;
            break;
        }
    }
}
