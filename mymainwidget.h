#ifndef MYMAINWIDGET_H
#define MYMAINWIDGET_H

//#include <QWidget>
//#include "fightwidget.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

#include <QLabel>
class MyMainWidget : public QWidget
{
    Q_OBJECT

public:
    QLabel *pLab;

    QPushButton *pButtonQuit;
    QPushButton *pButtonFight;

    QVBoxLayout *pVBoxLayout;
//    FightWidget *pFightWidget;

//    QPushButton newButton;

    explicit MyMainWidget(QWidget *parent = nullptr);
    ~MyMainWidget();

private slots:
    void fillWidget();
    void clearWidget();
    void newFight();

signals:
    void windowFight();
};

#endif // MYMAINWIDGET_H
