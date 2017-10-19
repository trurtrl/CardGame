#ifndef UNITOLD_H
#define UNITOLD_H
#include "animation.h"

#include <QObject>
#include <QtWidgets/QGraphicsPixmapItem>

//#include <QtCore/QString>



class Unitold : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QString defaultType = "CAELEM";
//    QString defaultType = "CMAGE";
    QString unitType;

//    QGraphicsPixmapItem *pBack;

    explicit Unitold(QGraphicsPixmapItem *parent = nullptr);
    ~Unitold();

    Animation *pAnim;

signals:

public slots:
    void nextFrame(int);
    void changeType();
    void changeType2();

private:


//    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *pe);
//    virtual void dropEvent(QGraphicsSceneDragDropEvent *pe);

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *pe) override;
};

#endif // UNITOLD_H
