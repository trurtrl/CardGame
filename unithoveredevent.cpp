#include "unithoveredevent.h"

UnitHoveredEvent::UnitHoveredEvent(Unitold *pUnit)
    :QEvent(UnitHoveredEvent::unitHovered), pSender{pUnit}
{}

