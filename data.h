#ifndef DATA_H
#define DATA_H

#include "unit.h"
#include "card.h"
#include <QVector>

class Data : public QObject
{
public:
    QPixmap *pField;
    QVector<Unit*> vectorUnits;
    QVector<Card*> vectorCards;

    Data(int field, QObject *parent = nullptr);
    ~Data();



private:
    void createField(int f);
    void createUnits();
    void createCards();

protected:
    virtual void customEvent(QEvent *pe);
};

#endif // DATA_H
