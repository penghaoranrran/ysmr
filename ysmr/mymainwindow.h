#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include<role.h>
#include<wayline.h>
#include<waypoint.h>
#include<monitor.h>
#include<QTimer>
#include<QMouseEvent>
#include<qtoolbutton.h>
#include<QList>
#include<QLabel>
#include<arrow.h>
#include<win.h>
#include<fail.h>

class mymainwindow : public QMainWindow
{
    Q_OBJECT
public:
    QLabel* labal;
    QToolButton* yuans;
    QToolButton* yiji;
    QList<role*> tower;
    // QList<arrow*> jian;
    QList<QList<arrow*>> jian_total;
    wayline* way;
    monitor* guaiwu;
    int ys=800;
    int num=0;
    int guaiwu_blood=20;
    win w;
    fail f;

    explicit mymainwindow(QWidget *parent = nullptr);
    void attacked();
    void damage();

    //画出游戏界面、
    void paintEvent(QPaintEvent*);
    void draw_monitor(QPainter& painter);
    void draw_wayline(QPainter& painter);
    void draw_role(QPainter& painter);
    void draw_arrow(QPainter& painter);

    //计时器
    void timerEvent(QTimerEvent* );

    //鼠标点击事件
    void mousePressEvent(QMouseEvent *ev);
    int mouse_x[20];
    int mouse_y[20];
    int press_num=0;
    int get_press_num();

    bool judge(QList<role*> n,role* m);

    bool eventFilter(QObject *watched, QEvent *event);
    void showPaint(QLabel* );
signals:
};

#endif // MYMAINWINDOW_H
