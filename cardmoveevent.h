#ifndef CARDMOVEEVENT_H
#define CARDMOVEEVENT_H

#include "card.h"
#include <QEvent>
#include <QObject>

class CardMoveEvent : public QEvent
{
public:
    Card *pSender;
    QObject *pReceiver;

    explicit CardMoveEvent(Card *pCard);


    static const QEvent::Type cardMove = static_cast<QEvent::Type>(1100);
    static const QEvent::Type changeType = static_cast<QEvent::Type>(1101);
};

#endif // CARDMOVEEVENT_H
