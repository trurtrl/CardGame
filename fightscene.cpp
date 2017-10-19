#include "fightscene.h"

#include "unithoveredevent.h"
#include "cardmoveevent.h"
#include "cardplayevent.h"
#include <QEvent>
//#include "card.h"
#include <QtWidgets/QGraphicsPixmapItem>

#include <QApplication>
#include <QDebug>
//#include "myitemgroup.h"
//#include <QGraphicsBlurEffect>

FightScene::FightScene(const QRect &sceneRect, Data *pFightData, QObject *parent)
    : QGraphicsScene(parent),
    data{pFightData},

/*      pField{data->pField},
      pFriend1{data->vectorUnits[0]},
      pFriend2{data->vectorUnits[1]},
      pFriend3{data->vectorUnits[2]},

      pCard1{data->vectorCards[0]}
*/
    pField{pFightData->pField},
    pFriend1{pFightData->vectorUnits[0]},
    pFriend2{pFightData->vectorUnits[1]},
    pFriend3{pFightData->vectorUnits[2]},
    pEnemy1{pFightData->vectorUnits[3]},
    pEnemy2{pFightData->vectorUnits[4]},
    pEnemy3{pFightData->vectorUnits[5]},

    pCard1{pFightData->vectorCards[0]},
    vectorUnits{pFightData->vectorUnits}

{
    setSceneRect(sceneRect);
    int w = width();
    int h = height();

    qDebug() << "Scene: " << w << " x " << h;

//    QGraphicsPixmapItem* pPixmapItemGround = this->addPixmap(QPixmap(":/FIELDS/CMBKDES.DDS"));
//    pPixmapItemGround = addPixmap(pBackground->scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::FastTransformation));
//    pPixmapItemGround = new QGraphicsPixmapItem(pBackground->scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::FastTransformation));

//    pBackground = new QPixmap(":/FIELDS/CMBKDES.DDS");
//    pPixmapItemGround = new QGraphicsPixmapItem(*pBackground);


//    QPixmap pix = QPixmap(":/FIELDS/CMBKDES.DDS");

//    qDebug() << "Pixmap: " << pix.width() << " x " << pix.height();
//    pBackground = new QPixmap;
//    *pBackground = pix.scaledToWidth(w);
//    *pBackground = pix.scaled(w ,h);
//    QGraphicsPixmapItem* pPixmapItemGround = this->addPixmap(*pBackground);
//    QPixmap pixx = pix.scaled(w, h , Qt::KeepAspectRatio);

//    setBackgroundBrush(pBackground->scaled(this->width(), this->height(), Qt::KeepAspectRatio, Qt::FastTransformation));
//    setBackgroundBrush(pBackground->scaled(w, h));
    setBackgroundBrush(*pField);

//    pFriend1 = new Unit();    
    addItem(pFriend1);
    pFriend1->setPos(w/10, h/20);

//    pFriend2 = new Unit();
    addItem(pFriend2);
    pFriend2->setPos(w/5, h/3);

//    pFriend3 = new Unit();
    addItem(pFriend3);
    pFriend3->setPos(w/10, 0.55*h);

    addItem(pEnemy1);
    pEnemy1->setPos(9*w/10, h/40);

    addItem(pEnemy2);
    pEnemy2->setPos(4*w/5, h/3);

    addItem(pEnemy3);
    pEnemy3->setPos(9*w/10, 0.6*h);

//    pAnim = new Animation(str);
//    pItem = new QGraphicsPixmapItem(QPixmap(*(pAnim->vectorSprites[5])));
//    pItem->setPos(500,500);

//    pCard1 = new Card(w/4, 7*h/8);
    pCard1->setPos(w/4, 7*h/8);
    addItem(pCard1);

//    pCard1->setPixmap(QPixmap(":/CARDS/CARD_BLUE.DDS"));
//    pCard1->setPos();

//    pBack1 = new QGraphicsPixmapItem;
//    pGroup1 = new QGraphicsItemGroup;
//    addItem(pGroup1);
//    pGroup1->addToGroup(pFriend1);

//    pMyGroup1 = new Unit();
//    pMyGroup1->setPos(3*w/4, h/5);
//    addItem(pMyGroup1);

//    QGraphicsBlurEffect *pBlur = new QGraphicsBlurEffect;
//    pBlur->setBlurRadius(10);
//    pMyGroup1->setGraphicsEffect(pBlur);
/*    QGraphicsPixmapItem *pBack1 = new QGraphicsPixmapItem;
    addItem(pBack1);
    pBack1->setPos(w/7, h/6);
*////

}

FightScene::~FightScene()
{
/*    delete pFriend1;
    delete pFriend2;
    delete pFriend3;

    delete pCard1;
*/


//    delete pPixmapItemGround;
//    delete pBackground;
}

/*
bool FightScene::event(QEvent *event)
{
    if (event->type() == UnitHoveredEvent::unitHovered)
    {
        qDebug() << "My Event is received by Scene";
    }
    return QWidget::event(event);
}*/

void FightScene::customEvent(QEvent *pe)
{
    if (pe->type() == CardMoveEvent::cardMove)
    {
//        qDebug() << "moving on scene";
        Card *pCard = (reinterpret_cast<CardMoveEvent*>(pe))->pSender;
        if (isCardPlayable(pCard))
        {
            pCard->setPlayable(true);
        }
        pCard->setPlayable(false);
//        QApplication::sendEvent(data, pe);
    }
    if (pe->type() == CardPlayEvent::cardPlay)
    {
        qDebug() << "play Event on scene";
        Card *pCard = (reinterpret_cast<CardMoveEvent*>(pe))->pSender;
        playCard(pCard, pTempUnit);
    }
    if (pe->type() == UnitHoveredEvent::unitHovered)
    {
        qDebug() << "My Event is received by Scene";
//        return;
//        return QGraphicsScene::customEvent(pe);
        UnitHoveredEvent *pUnitHoverEvent = reinterpret_cast<UnitHoveredEvent *>(pe);
        Card *rec1 = pUnitHoverEvent->pReceiver;
        Card *rec = (reinterpret_cast<UnitHoveredEvent *>(pe))->pReceiver;
//        Card *rec = (dynamic_cast<UnitHoveredEvent *>(pe))->pReceiver;
//        Card::unitHoveredEvent((static_cast<UnitHoveredEvent *>(pe))->pReceiver, static_cast<UnitHoveredEvent *>(pe));
        rec->unitHoveredEvent(dynamic_cast<UnitHoveredEvent *>(pe));
//(static_cast<UnitHoveredEvent *>(pe))->pReceiver,
    }
    return QGraphicsScene::customEvent(pe);
}

bool FightScene::isCardPlayable(Card *pCard)
{
    for (Unit *pUnit : vectorUnits)
    {
        if (pCard->collidesWithItem(pUnit))
        {
            if (pUnit->unitType == pUnit->defaultType)
            {
//                qDebug() << "card's playable";
                pTempUnit = pUnit;
                return true;
            }
//            qDebug() << "card's NOT playable";
//            return false;
        }
    }
}

void FightScene::playCard(Card *pc, Unit *pu)
{
    pu->changeType();
}
