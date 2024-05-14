#ifndef WIN_H
#define WIN_H

#include <QWidget>

class win : public QWidget
{
    Q_OBJECT
public:
    explicit win(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);

signals:
};

#endif // WIN_H
