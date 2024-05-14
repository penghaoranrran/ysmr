#ifndef MONITOR_H
#define MONITOR_H

#include <QObject>
#include<QPoint>
#include<waypoint.h>
#include<wayline.h>

class monitor : public QObject
{
    Q_OBJECT
public:
    int mx=300;
    int my=300;
    QPoint mp;
    int blood;
    int m_speed=1;
    QString ImgPath;
    explicit monitor(int x,int y,int bl,QString im);
    void move(wayline& temp);

signals:
};

#endif // MONITOR_H
