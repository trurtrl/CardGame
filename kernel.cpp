#include "kernel.h"

#include <QtCore/QDebug>



Kernel::Kernel(QObject *parent)
    :QObject(parent)
{
    size = resolution();
//    size = QSize(1920, 1080);
//    pStackedWidget = new MyStackedWidget();
    pStackedWidget = new QStackedWidget();


    createMain();
}

Kernel::~Kernel()
{
    delete pMainWidget;
    delete pStackedWidget;
}

void Kernel::createMain()
{
    pMainWidget = new MyMainWidget();
    pMainWidget->setFixedSize(size);
    QObject::connect(pMainWidget->pButtonQuit, SIGNAL(clicked(bool)), app(), SLOT(quit()));
    QObject::connect(pMainWidget->pButtonFight, SIGNAL(clicked(bool)),  SLOT(createFight()));
    pStackedWidget->addWidget(pMainWidget);
    int w = pMainWidget->width();
    int h = pMainWidget->height();
    pMainWidget->pLab->setText("App resolution :\n" + QString::number(w) + " x " + QString::number(h));
    pStackedWidget->setCurrentWidget(pMainWidget);
//    showMain();
}
void Kernel::showMain()
{
    pStackedWidget->setCurrentWidget(pMainWidget);
}

void Kernel::createFight()
{
    pFightData = new Data(0); // Here will be a function for choosing\randomization Field
    pFightWidget = new FightWidget(size, pFightData);
//    pFightWidget->setFixedSize(size);
    connect(pFightWidget->pButtonEnd, SIGNAL(clicked(bool)), SLOT(removeFight()));
    pStackedWidget->addWidget(pFightWidget);
    pStackedWidget->setCurrentWidget(pFightWidget);
}
void Kernel::removeFight()
{
    pStackedWidget->removeWidget(pFightWidget);
    pStackedWidget->setCurrentWidget(pMainWidget);
    delete pFightWidget;
    delete pFightData;
}

QApplication* Kernel::app()
{
    return static_cast<QApplication *>(QApplication::instance());
}

QSize Kernel::resolution()
{
    int width = (QApplication::desktop()->screenGeometry()).width();
    int height = (QApplication::desktop()->screenGeometry()).height();
    int width_new = (width>=1920) ? 1920 : width;
    int height_new = (height>=1080) ? 1080 : height;
    qDebug() << "App resolution: " << width_new << " x " << height_new;
    return QSize(width_new, height_new);
//    return QSize(width, height);
}


