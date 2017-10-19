#include "cardplayevent.h"

CardPlayEvent::CardPlayEvent(Card *pCard)
    :QEvent(CardPlayEvent::cardPlay), pSender{pCard}
{

}
