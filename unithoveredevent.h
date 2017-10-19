#ifndef UNITHOVEREDEVENT_H
#define UNITHOVEREDEVENT_H

#include "card.h"
#include <QEvent>
//#include <QGraphicsItem>

//static const QEvent::Type unitHovered = static_cast<QEvent::Type>(1100);

class UnitHoveredEvent : public QEvent
{
public:
    Unitold *pSender;
    Card *pReceiver;

    explicit UnitHoveredEvent(Unitold *pUnit);
    static const QEvent::Type unitHovered = static_cast<QEvent::Type>(1109);

private:
//    static QEvent::Type registeredType();
};

#endif // UNITHOVEREDEVENT_H
