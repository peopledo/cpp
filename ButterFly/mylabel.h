#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    ~MyLabel();

signals:

public slots:

protected:
    //鼠标进入
    void enterEvent(QEvent*);

    //鼠标出
    void leaveEvent(QEvent*);

    //鼠标点击
    void mousePressEvent(QMouseEvent *ev);


};

#endif // MYLABEL_H
