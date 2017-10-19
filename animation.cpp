#include "animation.h"

#include <QDebug>

#include <QtGui/QPixmap>
#include <QtWidgets/QApplication>
#include <QDesktopWidget>

#include <QImage>
#include <QPainter>

/*QT_BEGIN_NAMESPACE
  extern Q_WIDGETS_EXPORT void qt_blurImage( QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0 );
QT_END_NAMESPACE*/

Animation::Animation(QString &type, QObject *parent)
    : QObject(parent), type{type}
{
    setSprites();
//    setActiveSprites();
    pTimeLine = new QTimeLine (1000);
    pTimeLine->setCurveShape(QTimeLine::LinearCurve);
    pTimeLine->start();
}

void Animation::setSprites()
{
    QDir dir = QDir(":/IMAGES/UNITS/"+type);
//    qDebug(dir.currentPath().toLatin1());
    listFiles = dir.entryList();

    scaledWidth = newWidth();
    scaledHeight = newHeight();
    for (QStringList::iterator i=listFiles.begin(); i!= listFiles.end(); ++i)
    {
//        if (*i==nullptr) qDebug() << "Here is 0";


//        vectorSprites.push_back(new QPixmap(":/"+type+"/"+*i));
//        float scaleX = ((QApplication::desktop()->screenGeometry()).width())/1920;
//        float scaleY = ((QApplication::desktop()->screenGeometry()).height())/1080;


        vectorSprites.push_back( (QPixmap(":/IMAGES/UNITS/"+type+"/"+*i)).scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio));
//        vectorSprites.push_back( (QPixmap(":/"+type+"/"+*i)));
    }
    qDebug() << vectorSprites.count();
//    if (getMultiplierY() != 1.0) vectorSprites = scaledSprites(vectorSprites);
//    qDebug() << vectorSprites.count();


    //  ActiveSprites
/*
    for (QStringList::iterator i=listFiles.begin(); i!= listFiles.end(); ++i)
    {
        QImage im = (QImage(":/"+type+"/"+*i)).scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio);
        int backWidth = im.width()*1.1;
        int backHeight = im.height()*1.1;
        QImage result = QImage(backWidth, backHeight, QImage::Format_ARGB32_Premultiplied);
        QPainter painter(&result);
        QImage imBack = im.scaled(backWidth, backHeight);
//        imBack.set;
        painter.setOpacity(0.3);

        painter.drawImage(-0.05, -0.05, imBack);
        painter.setOpacity(1);
        painter.drawImage(0, 0, im);
        vectorActiveSprites.push_back(QPixmap::fromImage(result));
        painter.end();
    }
*/
/*    for (QStringList::iterator i=listFiles.begin(); i!= listFiles.end(); ++i)
    {
        QImage im = (QImage(":/"+type+"/"+*i)).scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio);
        int backWidth = im.width();
        int backHeight = im.height();
        QImage result = QImage(backWidth, backHeight, QImage::Format_ARGB32_Premultiplied);
        QPainter painter(&result);
        QImage imBack = im;

//        painter.setOpacity(0.3);

//        qt_blurImage(&painter, imBack, 3, true, false);
        painter.drawImage(0, 0, imBack);
//        painter.setOpacity(1);

//        painter.drawImage(0, 0, im);
        vectorActiveSprites.push_back(QPixmap::fromImage(result));
        painter.end();
    }

    qDebug() << vectorActiveSprites.count();*/
}


float Animation::getMultiplierY()
{
    int screenHeight = 480;
//    int screenHeight = (QApplication::desktop()->screenGeometry()).height();
    return screenHeight/1080;
}

QVector<QPixmap > Animation::scaledSprites(QVector<QPixmap > &oldVec)
{}
/*
{
    scaledWidth = newWidth();
    scaledHeight = newHeight();
    QVector<QPixmap*> newVec;
    for (QVector<QPixmap*>::iterator i=oldVec.begin(); i!=oldVec.end(); ++i)
    {
//        i = &((*i)->scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio));
//        vec.push_back(&((*i)->scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio)));
        QPixmap *p = *i;
        QPixmap q = p->scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio);
         &q;
        newVec.push_back(&q);
        *i = nullptr;
    }
    oldVec.clear();
    return newVec;
}*/

int Animation::newWidth()
{
    int screenWidth = (QApplication::desktop()->screenGeometry()).width();
//    int screenWidth = 800;
    int width = (QPixmap(":/IMAGES/UNITS/"+type+"/"+listFiles.at(0))).width();
    return width*screenWidth/1920;
}

int Animation::newHeight()
{
//    int screenHeight = 480;
    int screenHeight = (QApplication::desktop()->screenGeometry()).height();
    int height = (QPixmap(":/IMAGES/UNITS/"+type+"/"+listFiles.at(0))).height();
    return height*screenHeight/1080;
}

void Animation::playAll()
{
    pTimeLine->setDuration(600);
    int ssize = vectorSprites.count();
    qDebug() << "sprites.size() = " << ssize;
    pTimeLine->setFrameRange(0, ssize-1);
//    pTimeLine->setCurveShape(QTimeLine::LinearCurve);
//    pTimeLine->setUpdateInterval(5);
    qDebug() << "update interval = " << pTimeLine->updateInterval();
    qDebug() << "loop Count = " << pTimeLine->loopCount();
//    QGraphicsItemAnimation* pAnimation = new QGraphicsItemAnimation(this);
//    pAnimation->setTimeLine(pTimeLine);
    connect(pTimeLine, SIGNAL(frameChanged(int)), parent(), SLOT(nextFrame(int)) );
}
void Animation::idleAnimate()
{
    pTimeLine->setFrameRange(0, 4);
//    pTimeLine->setUpdateInterval(5);
    pTimeLine->setLoopCount(0);
//    qDebug() << "update interval = " << pTimeLine->updateInterval();
//    qDebug() << "loop Count = " << pTimeLine->loopCount();
    connect(pTimeLine, SIGNAL(frameChanged(int)),parent(),  SLOT(nextFrame(int)) );
}



void Animation::setActiveSprites()
{
    for (int i=0; i!=7; ++i)
    {
        QPixmap im = vectorSprites[i];
        int backWidth = im.width()*1.1;
        int backHeight = im.height()*1.1;
//        QImage result = QImage(backWidth, backHeight, QImage::Format_ARGB32_Premultiplied);
        QPixmap result = QPixmap(backWidth, backHeight);
        QPainter painter(&result);
        painter.drawPixmap(0, 0, im.scaled(backWidth, backHeight));
        painter.drawPixmap(0, 0, im);
        vectorActiveSprites.push_back(result);
    }
}
