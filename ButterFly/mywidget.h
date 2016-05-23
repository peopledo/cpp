#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();


protected:
    //事件
    void paintEvent(QPaintEvent*);

    //拖动
    void mouseMoveEvent(QMouseEvent*);

    //点击鼠标
    void mousePressEvent(QMouseEvent*);

    //鼠标放开
    void mouseReleaseEvent(QMouseEvent*);

    //定时器
    void timerEvent(QTimerEvent*);



private:
    Ui::MyWidget *ui;
    int timerOne;
    unsigned int timerOneSec;
    static int x;
    static int y;
    static int flag;
};

#endif // MYWIDGET_H
