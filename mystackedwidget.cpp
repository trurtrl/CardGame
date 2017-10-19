#include "mystackedwidget.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QPaintEvent>

MyStackedWidget::MyStackedWidget(QWidget *parent) : QStackedWidget(parent)
{
    int screenWidth = (QApplication::desktop()->screenGeometry()).width();
    int screenHeight = (QApplication::desktop()->screenGeometry()).height();
    scaleX = screenWidth/1920;
    scaleY = screenHeight/1080;
//    resize(screenWidth, screenHeight);
}

void MyStackedWidget::paintEvent(QPaintEvent *pEvent)
{
    QStackedWidget::paintEvent(pEvent);
    QPainter painter(this);
    painter.scale(scaleX, scaleY);
//    qDebug() << "paint" ;
//    event(pEvent);
}
