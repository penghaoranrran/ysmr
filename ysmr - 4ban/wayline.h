#ifndef WAYLINE_H
#define WAYLINE_H

#include <QObject>
#include<QMainWindow>
#include<waypoint.h>
#include<QPainter>

class wayline : public QObject
{
    Q_OBJECT
public:
    waypoint* head;
    wayline();
    void linking(QPoint pos);


signals:
};

#endif // WAYLINE_H
