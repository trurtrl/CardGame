#include "unitold.h"
#include "unithoveredevent.h"

#include <QDebug>
#include <QApplication>


//#include "animation.h"
//#include <QtWidgets/QGraphicsPixmapItem>
#include <QGraphicsSceneDragDropEvent>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsBlurEffect>
#include <QGraphicsColorizeEffect>

QT_BEGIN_NAMESPACE
    extern Q_WIDGETS_EXPORT void qt_blurImage( QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0 );
QT_END_NAMESPACE

Unitold::Unitold(QGraphicsPixmapItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    unitType = defaultType;

    pAnim = new Animation{unitType};
    pAnim->setParent(this);
//    setPixmap(*(pAnim->vectorSprites[0]));

    pAnim->idleAnimate();

    setAcceptHoverEvents(true);

//        pBack->setPos(0,0);
}
Unitold::~Unitold()
{
//    delete pTimeLine;
    delete pAnim;
}

void Unitold::nextFrame(int i)
{
//    qDebug() << "i = " << i;
//    setPixmap(*(pAnim->vectorSprites[i]));

//    if (UnitoldType == defaultType)
//    {
    setPixmap(pAnim->vectorSprites[i]);

/*    pBack->setPixmap(pAnim->vectorSprites[i]);
    QGraphicsBlurEffect *pBlurEffect = new QGraphicsBlurEffect;
    pBlurEffect->setBlurRadius(15);
    pBack->setGraphicsEffect(pBlurEffect); */
//    return;
//    }
//    setPixmap(pAnim->vectorActiveSprites[i]);
//    QPixmap pix = pAnim->vectorSprites[i];

/*    int backW = pix.width();
    int backH = pix.height();
    QPixmap result = QPixmap(backW, backH);
    QPainter painter(&result);
    painter.save();
    painter.setOpacity(0.3);
    QPixmap back = pix.scaled(1.1, 1.1, Qt::KeepAspectRatio);
    painter.drawPixmap(-5, -5, back.width(), back.height(), back);
    painter.setOpacity(1);
    painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
    painter.restore();
    painter.end();
    setPixmap(result);
*/
/*
        setPixmap(pAnim->vectorSprites[i]);
        QGraphicsBlurEffect *pBlurEffect = new QGraphicsBlurEffect;
        pBlurEffect->setBlurRadius(15);
        setGraphicsEffect(pBlurEffect);
    //    QGraphicsColorizeEffect *pColorizeEffect = new QGraphicsColorizeEffect;
    //    pColorizeEffect->setColor(Qt::green);
    //    setGraphicsEffect(pColorizeEffect);
    //    setActive(true);
    */

    /*
        QPainter painter = QPainter();
        int newWidth = ((pAnim->vectorSprites[i]).width())*1.3;
        int newHeight = ((pAnim->vectorSprites[i]).height())*1.3;
        painter.drawPixmap();
        setPixmap((pAnim->vectorSprites[i]).scaled(newWidth, newHeight, Qt::KeepAspectRatio));
        setPixmap(pAnim->vectorSprites[i]);
        */
}

void Unitold::changeType()
{
    QString newType = "CGDRAG";
    Animation* temp = new Animation(newType);
//    pTimeLine->stop();
    delete pAnim;
    pAnim = temp;
//    pTimeLine->start();
    temp = nullptr;
    unitType = newType;
}

void Unitold::changeType2()
{
    QString newType = "CMAGE";
    Animation* temp = new Animation(newType);
//    pTimeLine->stop();
    delete pAnim;
    pAnim = temp;
//    pTimeLine->start();
    temp = nullptr;
    unitType = newType;
}
    /*
    void Unitold::dragEnterEvent(QGraphicsSceneDragDropEvent* pe)
    {
    //    if (pe->widget()->forWhom == 'f')
        {
            qDebug() << "accepted";
            pe->acceptProposedAction();
        }
            qDebug() << "NOT accepted";
        }
    }

    void Unitold::dropEvent(QGraphicsSceneDragDropEvent *pe)
    {
    //    pe->widget()->UnitoldFn(this);
    }*/

void Unitold::hoverEnterEvent(QGraphicsSceneHoverEvent *pe)
{
    //    QGraphicsItem *pCover = scene()->itemAt(pe->scenePos(), QTransform());
    //    qDebug() << (scene()->itemAt(pe->scenePos(), QTransform()))->type();

        //    qDebug() << pCover->type();
    //    if (pCover->type() == UserType+1)
    //    {
    qDebug() << "HoverEvent";
    //    }

    ///    QGraphicsItem *pItem = (scene()->itemAt(pe->pos(), QTransform()));
    ///    qDebug() << pItem->type();

    //    if ((scene()->itemAt(pe->pos(), QTransform()))->type())
    //    {qDebug()<< (scene()->itemAt(pe->pos(), QTransform()))->type();};

    QPointF point = pe->scenePos();
    //    QGraphicsScene *sc = scene();
    UnitHoveredEvent *pUnitHoveredEvent = new UnitHoveredEvent(this);
    //    QPointF pos = pe->scenePos();
    //    QGraphicsItem *pItem = scene()->itemAt(pe->scenePos(), QTransform());
    QGraphicsItem *pItem = scene()->itemAt(pe->scenePos(), QTransform());
    //    pUnitoldHoveredEvent->pReceiver = dynamic_cast<Card *>(scene()->itemAt(pe->scenePos(), QTransform()));
    QApplication::sendEvent(scene(), pUnitHoveredEvent);
}
