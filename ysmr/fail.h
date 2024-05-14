#ifndef FAIL_H
#define FAIL_H

#include <QWidget>

class fail : public QWidget
{
    Q_OBJECT
public:
    explicit fail(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:
};

#endif // FAIL_H
