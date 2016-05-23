#ifndef MYBALLONE_H
#define MYBALLONE_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>

class MyBallOne : public QWidget
{
    Q_OBJECT

public:
    MyBallOne(QWidget *parent = 0);
    ~MyBallOne();

protected:
    void paintEvent(QPaintEvent*);

private:
    QTimer timer;
    int maxX;
    int maxY;
    int x;
    int y;
    int weight; //重量
    int timeN; //间隔时间
    double a; //重力加速度
    double speed; //运动速度
};

#endif // MYBALLONE_H
