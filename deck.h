#ifndef DECK_H
#define DECK_H

#include "card.h"
//#include <QObject>

class Deck : public QObject
{
    Q_OBJECT
public:
    explicit Deck(QObject *parent = nullptr);
    ~Deck();

signals:

public slots:
    void getCard();

private:
    QVector<Card> pack;
    QPoint point1, point2, point3, point4;  // top-left corners's coodinates of cards on the table

    void setCoordinates();                  //set top-left corners's coodinates of cards

};

#endif // DECK_H
