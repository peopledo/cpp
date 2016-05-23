#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>
#include <QTimerEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QBrush>
#include <QImage>
#include <QDebug>

int MyWidget::x = 0;
int MyWidget::y = 0;
int MyWidget::flag = 2;

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    timerOneSec = 100;
    timerOne = startTimer(timerOneSec);
    this->move(0, 0);

    this->setAttribute(Qt::WA_TranslucentBackground);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowState(Qt::WindowFullScreen);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

}

//拖动
void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    int ex = ev->globalX() - 80;
    int ey = ev->globalY() - 100;

    this->move(ex, ey);
    x = ex;
    y = ey;
}

//点击鼠标
void MyWidget::mousePressEvent(QMouseEvent *)
{
    killTimer(timerOne);
}

//鼠标放开
void MyWidget::mouseReleaseEvent(QMouseEvent *)
{
    timerOne = startTimer(timerOneSec);
}

//背景图片
void MyWidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    QString imgsrc;

    static int flag = 0;
    if (flag == 0)
    {
        imgsrc = ":/img/up.png";
        flag = 1;
    }
    else
    {
        imgsrc = ":/img/down.png";
        flag = 0;
    }
    QImage image(imgsrc);
    p.drawImage(0, 0, image);

    //QPainter p2(ui->page_2);
    //p2.drawImage(0, 0, image2);
    //p.drawPixmap(0, 0, this->width(), this->height(),
    //             QPixmap("D:\\up.png"));

}

//定时器
void MyWidget::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId() == timerOne)
    {
        int unitN = 20;
        int maxX = this->width();
        int maxY = this->height() - 100;

        //到达边界
        /*
         * 只能向右飞
         */
        if (x >= maxX)
        {
            x = 0;
        }

        //向上或向下
        if (y >= maxY)
        {
            flag = 1; //向上
        }
        else if (y <= 0)
        {
            flag = 2; //向下
        }

        if (flag == 1)
        {
            y -= unitN;
        }
        else
        {
            y += unitN;
        }
        x += unitN;


        this->repaint();

        this->move(x, y);
    }

}

MyWidget::~MyWidget()
{
    delete ui;
}
