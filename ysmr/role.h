#ifndef ROLE_H
#define ROLE_H


#include <QObject>
#include<QTimer>
#include<monitor.h>
#include<QList>
#include<arrow.h>

class role : public QObject
{
    Q_OBJECT
public:
    QPoint role_pos;
    monitor* target;
    QString imgpath;
    QList<arrow*> jian;
    role(QPoint p,QString im);
    void creat_arrow(monitor* temp);
signals:
};

#endif // ROLE_H
