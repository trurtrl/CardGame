#ifndef MYSTACKEDWIDGET_H
#define MYSTACKEDWIDGET_H
#include <QtWidgets/QStackedWidget>
#include <QtGui/QPainter>

class MyStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit MyStackedWidget(QWidget *parent = nullptr);
protected:
    qreal scaleX;
    qreal scaleY;
    void paintEvent(QPaintEvent *pEvent);


};

#endif // MYSTACKEDWIDGET_H
