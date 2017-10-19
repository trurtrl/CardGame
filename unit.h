#ifndef UNIT_H
#define UNIT_H

//#include <QObject>
//#include <QGraphicsItemGroup>

#include "unitold.h"
#include <QGraphicsItemGroup>
#include <QGraphicsScale>

// QGraphicsItemGroup is used just for achieving highlight effect
class Unit : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    bool companion;
    QString defaultType = "CAELEM";
//    QString defaultType = "CMAGE";
    QString unitType;


    Unit(bool companion, QGraphicsItemGroup *parent = nullptr);
    ~Unit();

    Animation *pAnim;

signals:

public slots:
    void nextFrame(int i);
    void changeType();
    void highlight();

protected:
    QGraphicsScale *pScale;
    QGraphicsPixmapItem *pBack;
    QGraphicsPixmapItem *pFront;
    QGraphicsItemGroup *pInternalGroup;

    void reflectPixmap();
};

#endif // UNIT_H
