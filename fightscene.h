#ifndef FIGHTSCENE_H
#define FIGHTSCENE_H
//#include "unit.h"

#include "data.h"

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtCore/QVector>

#include "animation.h"

#include <QPixmap>
#include <QLabel>
#include "unit.h"

class FightScene : public QGraphicsScene
{
    Q_OBJECT
public:
    Data *data;
    QVector<Unit*> vectorUnits;
    QPixmap *pField;
    Unit *pFriend1;
    Unit *pFriend2;
    Unit *pFriend3;
    Unit *pEnemy1, *pEnemy2, *pEnemy3;

    Card *pCard1;

    Unit *pMyGroup1;
//    QGraphicsItemGroup *pGroup1;
//    QGraphicsPixmapItem *pBack1;
//    QLabel *pLabel1;
//    QLabel *pLabel2;
//    QLabel *pLabel3;

//    QPixmap *pBackground;
//    QGraphicsPixmapItem* pPixmapItemGround;

    FightScene(const QRect &sceneRect, Data *pFightData, QObject *parent = nullptr);
    ~FightScene();

    bool isCardPlayable(Card *pCard);


//    addUnit(QString type);
private:
    Unit *pTempUnit;
//    QLabel pLabel1;
//    QLabel pLabel2;
    void playCard(Card *pc, Unit *pu);

protected:
//    virtual bool event(QEvent *event);
    virtual void customEvent(QEvent *pe);
};

#endif // FIGHTSCENE_H
