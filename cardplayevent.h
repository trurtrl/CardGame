#ifndef CARDPLAYEVENT_H
#define CARDPLAYEVENT_H

#include "card.h"
#include <QEvent>
#include <QObject>

class CardPlayEvent : public QEvent
{
public:
    Card *pSender;
    QObject *pReceiver;

    explicit CardPlayEvent(Card *pCard);


    static const QEvent::Type cardPlay = static_cast<QEvent::Type>(1110);
//    static const QEvent::Type changeType = static_cast<QEvent::Type>(1111);
};

#endif // CARDPLAYEVENT_H
