#include "unit.h"
#include <QGraphicsColorizeEffect>
#include <QGraphicsBlurEffect>
#include <QDebug>
//#include <QPainter>


QT_BEGIN_NAMESPACE
    extern Q_WIDGETS_EXPORT void qt_blurImage( QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0 );
QT_END_NAMESPACE

Unit::Unit(bool companion, QGraphicsItemGroup *parent)
    : QObject(),
      QGraphicsItemGroup(parent),
      companion{companion}
{
    unitType = "BOY";

    pBack = new QGraphicsPixmapItem;
    pFront = new QGraphicsPixmapItem;
    QGraphicsColorizeEffect *pColorize = new QGraphicsColorizeEffect;
    pColorize->setColor(Qt::yellow);
    pBack->setGraphicsEffect(pColorize);
    pInternalGroup = new QGraphicsItemGroup;
    pInternalGroup->addToGroup(pBack);
    QGraphicsBlurEffect *pBlur = new QGraphicsBlurEffect;
    pBlur->setBlurRadius(15);
    pInternalGroup->setGraphicsEffect(pBlur);
    addToGroup(pInternalGroup);
    pInternalGroup->hide();

    pAnim = new Animation{unitType};

    addToGroup(pFront);
    pAnim->setParent(this);
//    setPixmap(*(pAnim->vectorSprites[0]));
    pAnim->idleAnimate();

    if (!companion) reflectPixmap();
}
Unit::~Unit()
{
    delete pAnim;
    delete pBack;
    delete pInternalGroup;
}

void Unit::reflectPixmap()
{
    pScale = new QGraphicsScale;
    pScale->setXScale(-1);
    setTransformations(QList<QGraphicsTransform*>() << pScale);
}

void Unit::nextFrame(int i)
{

    QPixmap pix = (pAnim->vectorSprites[i]);
//    qreal xTr= pix.width()/2;
//    pScale->setOrigin(QVector3D(xTr, 0, 0));
//    setTransformations(QList<QGraphicsTransform*>() << pScale);
    if (!companion)
    {
        qreal xTr= pix.width()/2;
        pScale->setOrigin(QVector3D(xTr, 0, 0));
    }

    pBack->setPixmap(pix);
    pFront->setPixmap(pix);
}

void Unit::changeType()
{
    QString newType = "ZOMBY4";
    Animation* temp = new Animation(newType);
//    pTimeLine->stop();
    delete pAnim;
    pAnim = temp;
//    pTimeLine->start();
    temp = nullptr;
    unitType = newType;
}

void Unit::highlight()
{
    pInternalGroup->show();
}
