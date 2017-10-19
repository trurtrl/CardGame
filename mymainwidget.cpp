#include "mymainwidget.h"
//#include "fightwidget.h"

#include <QtWidgets/QLabel>
#include <QtGui/QPixmap>

#include <QDebug>
#include <QLabel>

MyMainWidget::MyMainWidget(QWidget *parent)
    : QWidget(parent)
{
    pVBoxLayout = new QVBoxLayout;
    setLayout(pVBoxLayout);

    int w = width();
    int h = height();

//    setStyleSheet("background-image: url(\":/IMAGES/FIELDS/GRASS_1.PNG\")");
    setStyleSheet("background-color: grey");
    pLab = new QLabel;
//    pLab->setText("App resolution :\n" + QString::number(w) + " x " + QString::number(h));
    pVBoxLayout->addWidget(pLab);

    pButtonFight = new QPushButton("Fight");
//    QObject::connect(pButtonQuit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
//    pButtonFight->setGeometry(0,0, 100, 20);
    pButtonFight->setFixedSize(100, 100);
    pVBoxLayout->addWidget(pButtonFight);

//    QObject::connect(pButtonGame, SIGNAL(clicked(bool)), SLOT(newFight()));
    pButtonQuit = new QPushButton("Exit");
    pButtonQuit->setFixedHeight(100);
    pVBoxLayout->addWidget(pButtonQuit);

    QPushButton *pButtonNew = new QPushButton("-New-");
//    QObject::connect(pButtonNew, SIGNAL(clicked(bool)), SLOT(print_test()));
    pVBoxLayout->addWidget(pButtonNew);
}

MyMainWidget::~MyMainWidget()
{
    delete pVBoxLayout;
    delete pButtonQuit;
    delete pButtonFight;

//    delete pFightWidget;

//    delete pButtonNew;
}


void MyMainWidget::newFight()
{
    qDebug() << "try to create second window";
//    pFightWidget = new FightWidget(size(), this);
//    emit windowFight();
//    pFightWidget->show();
}

void MyMainWidget::fillWidget(){}
void MyMainWidget::clearWidget(){}
