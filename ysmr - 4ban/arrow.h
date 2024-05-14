#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include<monitor.h>

class arrow : public QObject
{
    Q_OBJECT
public:
    QPoint start_pos;
    QPoint m_currentPos;
    monitor* guaiwu;
    double delta;
    const int speed=1;
    double vx;
    double vy;
    const int dama=20;
    const QString arrow_photo=":/lnl_1.png";
    arrow(QPoint p1,monitor* b);
    void move();
signals:
};

#endif // ARROW_H
