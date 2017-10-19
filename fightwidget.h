#ifndef FIGHTWIDGET_H
#define FIGHTWIDGET_H

#include "fightscene.h"

#include <QWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QString>

#include <QtWidgets/QLabel>

class FightWidget : public QWidget
{
    Q_OBJECT
public:
//    QHBoxLayout *pHBoxLayout;
//    QVBoxLayout *pVBoxLayoutLeft;
    QPushButton *pButtonEnd;
    QPushButton *pButtonAnimateAll;
    QPushButton *pButtonNewType;
    QPushButton *pButtonTest;

    FightWidget(const QSize &sizeWidget, Data *pFightData, QWidget *parent = nullptr);
    ~FightWidget();

signals:

public slots:

private:
//    Data *pFightData;
    QHBoxLayout *pHBoxLayout;
    QVBoxLayout *pVBoxLayoutLeft;
    QVBoxLayout *pVBoxLayoutRight;
    FightScene  *pFightScene;
    QGraphicsView *pFightView;

    QLabel *pLabelLeft;

//    QLabel *pLabelL;
//    QLabel *pLabelC;
//    QLabel *pLabelR;

    QRect setRectGeometry(char ch);

};

#endif // FIGHTWIDGET_H
