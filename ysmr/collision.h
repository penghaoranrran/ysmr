#ifndef COLLISION_H
#define COLLISION_H

#include <QObject>
#include<QPoint>

class collision : public QObject
{
    Q_OBJECT
public:
    explicit collision(QObject *parent = nullptr);
    static bool monitor_collision(QPoint p1,int a1,QPoint p2,int a2);
signals:
};

#endif // COLLISION_H
