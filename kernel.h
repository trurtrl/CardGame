#ifndef KERNEL_H
#define KERNEL_H

#include "data.h"
#include "mymainwidget.h"
#include "fightwidget.h"

#include "mystackedwidget.h"

#include <QDesktopWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QApplication>
#include <QtCore/QObject>
#include <QtCore/QSize>

class Kernel : public QObject
{
    Q_OBJECT
public:
//    MyStackedWidget *pStackedWidget;
    QStackedWidget *pStackedWidget;
    Data *pFightData;

    explicit Kernel(QObject *parent = nullptr);
    ~Kernel() override;
    void createMain();


public slots:
    void showMain();
    void createFight();
    void removeFight();


private:
    QSize size;
    MyMainWidget *pMainWidget;
    FightWidget  *pFightWidget;

    QSize resolution();
    QApplication* app();

};

#endif // KERNEL_H
