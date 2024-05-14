#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <QObject>
#include<QPoint>

class waypoint : public QObject
{
    Q_OBJECT
public:
    QPoint mpos;
    waypoint* next=nullptr;
    waypoint(QPoint pos);


signals:
};

#endif // WAYPOINT_H
