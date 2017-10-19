#include "fightwidget.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>

#include <QtWidgets/QLabel>
#include <QDebug>
#include <QString>


FightWidget::FightWidget(const QSize &sizeWidget, Data *pFightData, QWidget *parent)
    :QWidget(parent)
{
    setFixedSize(sizeWidget);

    //  Left side
    pHBoxLayout = new QHBoxLayout;
    pHBoxLayout->setContentsMargins(0,0,0,0);
//    pHBoxLayout->SetFixedSize(myWidth, myHeight);
    pHBoxLayout->setGeometry(setRectGeometry('m'));
    pVBoxLayoutLeft = new QVBoxLayout;
//    pVBoxLayoutLeft->setFixedSize(0.05*myWidth, myHeight);
    pVBoxLayoutLeft->setGeometry(setRectGeometry('l'));
    pVBoxLayoutLeft->setContentsMargins(0,0,0,0);
    pLabelLeft = new QLabel;
    QPixmap pix(":/IMAGES/BORDERS/GOLD_1.PNG");
    pLabelLeft->setGeometry(setRectGeometry('l'));
    pLabelLeft->setScaledContents(true);
//    label.setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    pLabelLeft->setPixmap(pix.scaled(0.03*width(), height(), Qt::IgnoreAspectRatio, Qt::FastTransformation));
    pHBoxLayout->addWidget(pLabelLeft);


    // Central (Fight)
    pFightScene = new FightScene(setRectGeometry('s'), pFightData);
    pFightScene->setSceneRect(setRectGeometry('s'));
    pFightView = new QGraphicsView(pFightScene);
//    pFightView->fitInView(0, 0, pFightScene->width(), pFightScene->height());
//    pFightView->fitInView(pFightScene->sceneRect(), Qt::KeepAspectRatio);
    pFightView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pFightView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    pFightView->fitInView(setRectGeometry('s'), Qt::KeepAspectRatio);
    pFightView->viewport()->setContentsMargins(0,0,0,0);


    // Right side
    pVBoxLayoutRight = new QVBoxLayout;
//    pVBoxLayoutRight->setFixedSize(0.05*geom.width(), geom.height());
    pVBoxLayoutRight->setGeometry(setRectGeometry('r'));
    pVBoxLayoutRight->setContentsMargins(0,0,0,0);

    pButtonEnd = new QPushButton("Leave fight");
    pButtonEnd->setFixedWidth(0.04*width());
//    connect(pButtonEnd, SIGNAL(clicked(bool)), SLOT(close())); // define closing\changing window!!!
    pVBoxLayoutRight->addWidget(pButtonEnd);

    pButtonAnimateAll = new QPushButton("Animate All");
    pButtonAnimateAll->setFixedWidth(0.04*width());
    pVBoxLayoutRight->addWidget(pButtonAnimateAll);
    connect(pButtonAnimateAll, SIGNAL(clicked(bool)), pFightScene->pFriend1->pAnim, SLOT(playAll()));

    pButtonNewType = new QPushButton("Change type");
    pButtonNewType->setFixedWidth(0.04*width());
    pVBoxLayoutRight->addWidget(pButtonNewType);
    connect(pButtonNewType, SIGNAL(clicked(bool)), pFightScene->pFriend2, SLOT(changeType()));

    pButtonTest = new QPushButton("Test");
    pButtonTest->setFixedWidth(0.04*width());
    pVBoxLayoutRight->addWidget(pButtonTest);
    connect(pButtonTest, SIGNAL(clicked(bool)), pFightData->vectorUnits[0], SLOT(highlight()));

/*    pLabelL = new QLabel;
    pLabelL->setText("Left : \n" + QString::number(pVBoxLayoutLeft->geometry().width())+" x "+ \
                     QString::number(pVBoxLayoutLeft->geometry().height()) + "\n" +\
            QString::number(pVBoxLayoutLeft->geometry().x()) + " x " + QString::number(pVBoxLayoutLeft->geometry().y()));
    pVBoxLayoutRight->addWidget(pLabelL);
*/

    pHBoxLayout->addLayout(pVBoxLayoutLeft);
    pHBoxLayout->addWidget(pFightView);
    pHBoxLayout->addLayout(pVBoxLayoutRight);

    setLayout(pHBoxLayout);
}

FightWidget::~FightWidget()
{
    delete pButtonEnd;
    delete pButtonAnimateAll;
    delete pButtonNewType;

    delete pVBoxLayoutLeft;
    delete pVBoxLayoutRight;
    delete pFightScene;
    delete pFightView;
    delete pHBoxLayout ;
    delete pLabelLeft;
//    delete pLabelL;
}

QRect FightWidget::setRectGeometry(char ch)
{
    int w = width();
    int h = height();
    switch (ch) {
    case 'm':   // for main layout
        return QRect(0, 0, w, h);
        break;
    case 'l':   // for left layout
        return QRect(0, 0, 0.03*w, h);
        break;
    case 's':   //for scene
        return QRect(0.03*w, 0, 0.92*w, h);
        break;
    case 'r':   //for rigth layout
        return QRect(0.95*x(), 0, 0.05*w, h);
        break;
    default:
        break;
    }
}
