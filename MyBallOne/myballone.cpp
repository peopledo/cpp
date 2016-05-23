#include "myballone.h"
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

MyBallOne::MyBallOne(QWidget *parent)
    : QWidget(parent)
{
    //
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setFixedSize(64, 64);

    weight = 1;
    a = 1.2; // 9.8 m/s2
    x = 0;
    y = 0;
    speed = 0;
    timeN = 200;
    maxX = QApplication::desktop()->screenGeometry().width();
    maxY = QApplication::desktop()->screenGeometry().height();
    x = maxX / 2;
    this->move(x, y);

    timer.start(timeN);
    connect(&timer, &QTimer::timeout, [=](){
        if (y >= maxY)
        {
            y = 0;
            speed = 0;
        }
        // F = ma   距离 = 时间 * 速度(初速度+加速度*时间)
        //这里是自由落体 y 是不变的
        y += (timeN / timeN) * (speed + a * (timeN / timeN) * weight);
        speed += (timeN / timeN) * a * weight;

        move(x, y);

        update();
    });
}


//
void MyBallOne::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, this->width(), this->height(),
                 QPixmap(":/img/logo.png"));

}

MyBallOne::~MyBallOne()
{

}
