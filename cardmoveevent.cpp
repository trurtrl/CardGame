#include "cardmoveevent.h"

CardMoveEvent::CardMoveEvent(Card *pCard)
    :QEvent(CardMoveEvent::cardMove), pSender{pCard}
{

}
