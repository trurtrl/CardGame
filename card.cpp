#include "card.h"
#include "unithoveredevent.h"
#include "cardmoveevent.h"
#include "cardplayevent.h"

#include <QPixmap>
#include <QDebug>
//#include <QDrag>

#include <QGraphicsScene>
#include <QEvent>
#include <QCursor>
#include <QLineF>
#include <QApplication>

Card::Card(QGraphicsPixmapItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    playable = false;
    setPixmap(QPixmap(":/IMAGES/CARDS/CARD_1.PNG"));
//    setPos(baseX, baseY);
    setFlags(QGraphicsItem::ItemIsMovable);
    setCursor(Qt::ClosedHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
//    setDragData();
}

int Card::type() const
{
    return Type;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *pe)
{
    setCursor(Qt::ClosedHandCursor);
    QGraphicsItem::mousePressEvent(pe);
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *pe)
{
    setCursor(Qt::OpenHandCursor);
    if (playable)
    {
        qDebug() << "play Event on card";
        CardPlayEvent *pCardPlayEvent = new CardPlayEvent(this);
        QApplication::sendEvent(scene(), pCardPlayEvent);
        QGraphicsItem::mouseReleaseEvent(pe);

    }
    setOnBasePosition();
    QGraphicsItem::mouseReleaseEvent(pe);
    setScale(1);
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *pe)
{
//    if ( QLineF(pe->screenPos(), pe->buttonDownScreenPos(Qt::LeftButton)).length()
//            < QApplication::startDragDistance())
//    {return;}
    setScale(0.3);

    CardMoveEvent *pCardMoveEvent = new CardMoveEvent(this);
    QApplication::sendEvent(scene(), pCardMoveEvent);

    QGraphicsItem::mouseMoveEvent(pe);

}

void Card::setOnBasePosition()
{
    setPos(baseX, baseY);
}

void Card::setPlayable(bool p)
{
    playable = p;
}
bool Card::isPlayable()
{
    return playable;
}

void Card::checkCard()
{

}

void Card::unitHoveredEvent(UnitHoveredEvent *pe)
{
    qDebug() << "second check";
//    return true;
}

/*
void Card::setDragData()
{
    pUnitFn = &Unit::changeType;
    strPUnitFn = QString::number((int)pUnitFn, 16);
    pMimeData = new QMimeData;
    pMimeData->setText(strPUnitFn);
    QDrag pDrag = new QDrag;
    pDrag.setMimeData(pMimeData);
}*/

//bool Card::event(QGraphicsSceneEvent *pe)
bool Card::event(QEvent *pe)
{
//    if (pe->type() == (QEvent::Type)1100)
    if (pe->type() == UnitHoveredEvent::unitHovered)
    {
//        QEvent::accept();
        qDebug() << "My Event is received";
//        unitHoveredEvent(pe);
//        return true;
    }
//    return QGraphicsScene::event(pe);
    return QGraphicsPixmapItem::sceneEvent(pe);
}


bool Card::sceneEvent(QEvent *pe)
{
    if (pe->type() == UnitHoveredEvent::unitHovered)
    {
//        QEvent::accept();
        qDebug() << "My Event is received in SceneEvent";
//        unitHoveredEvent(pe);
        return true;
    }
    return QGraphicsPixmapItem::sceneEvent(pe);
}
