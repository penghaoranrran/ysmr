#ifndef MYWIDGET_H
#define MYWIDGET_H
#include<QPainter>
#include<QPushButton.h>
#include <QWidget>
#include<mymainwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class myWidget;
}
QT_END_NAMESPACE

//登录界面
class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);

    //登录界面的绘制
    void paintEvent(QPaintEvent*);

    ~myWidget();

private:
    Ui::myWidget *ui;
};
#endif // MYWIDGET_H
