#ifndef CARD_H
#define CARD_H

#include "unit.h"
#include <QGraphicsSceneMouseEvent>

//#include "unithoveredevent.h"

class UnitHoveredEvent;
//class CardMoveEvent;

#include <QObject>
//#include <QtWidgets/QGraphicsPixmapItem>
//#include <QGraphicsSceneEvent>

//#include <QString>
//#include <QMimeData>

//typedef void (Unit:: *UnitFn)();

class Card : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enum {Type = UserType+1};
    char forWhom;
//    void* func = Unit::changeType;
//    UnitFn pUnitFn;
    QString strPUnitFn;
//    QMimeData *pMimeData;

    explicit Card(QGraphicsPixmapItem *parent = nullptr);

    int type() const;
    void unitHoveredEvent(UnitHoveredEvent *pe);
    void setPlayable(bool);
    bool isPlayable();


signals:

public slots:
    void setOnBasePosition();

protected:
    bool playable;
    qreal baseX;
    qreal baseY;
//    void setDragData();
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *pe) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *pe) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *pe) override;


    void checkCard();
    virtual bool event(QEvent *pe) ;

    virtual bool sceneEvent(QEvent *pe);
};

#endif // CARD_H
