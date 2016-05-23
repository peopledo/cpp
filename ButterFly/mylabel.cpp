#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //setFont(0);
}

//
void MyLabel::enterEvent(QEvent *)
{
    setText("enter");
}

//
void MyLabel::leaveEvent(QEvent *)
{
    setText("leave");
}

//QMousePress
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    QString button;
    if (ev->button() == Qt::LeftButton)
    {
        button = "LeftButton";
    }
    else if (ev->button() == Qt::RightButton)
    {
        button = "RightButton";
    }
    else if (ev->button() == Qt::MidButton)
    {
        button = "MiddleButton";
    }

    QString temp = QString("Press [%1]").arg(button);
    setText(temp);
}

MyLabel::~MyLabel()
{

}

