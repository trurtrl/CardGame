#include "data.h"
#include "cardmoveevent.h"
#include <QDebug>

Data::Data(int field, QObject *parent)
    : QObject(parent)
{
    createField(field);
    createUnits();
    createCards();
}
Data::~Data()
{
    delete pField;
/*    for (int u=0; u!=vectorUnits.size(); ++u)
    {
        delete vectorUnits.takeAt(u);
    };
    for (int c=0; c!=vectorCards.size(); ++c)
    {
        delete vectorCards[c];
    };*/
}

void Data::createField(int f)
{
    pField = new QPixmap(":/IMAGES/FIELDS/SOFTBALL.PNG");
}
void Data::createUnits()
{
    bool companion = true;
    for (int u=0; u!=6; ++u)
    {
        if (u==3) companion = false;
        vectorUnits.push_back(new Unit(companion));
    };
}
void Data::createCards()
{
    for (int c=0; c!=4; ++c)
        vectorCards.push_back(new Card);
}


void Data::customEvent(QEvent *pe)
{
    if (pe->type() == CardMoveEvent::cardMove)
    {
//        qDebug() << "moving on data";
/*        Card *pCard = (reinterpret_cast<CardMoveEvent*>(pe))->pSender;
        if (isCardPlayable(pCard))
        {
            pCard->setPlayable(true);
        }
        pCard->setPlayable(false);  */
    }
}
