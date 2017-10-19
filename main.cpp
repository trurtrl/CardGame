//#include "mymainwidget.h"
//#include "fightingview.h"
#include "kernel.h"

//#include <QtWidgets/QApplication>

//#include <QSizePolicy>
//#include <QDebug>

//#include <QSize>
//#include <QtWidgets/QStackedWidget>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    Kernel kernel = Kernel();
//    kernel.pStackedWidget->show();

    Kernel *pKernel = new Kernel();
    pKernel->pStackedWidget->setWindowFlags(Qt::FramelessWindowHint);
#ifdef Q_OS_LINUX
//    pKernel->pStackedWidget->show();
    pKernel->pStackedWidget->show();
#endif
#ifdef Q_OS_ANDROID
    pKernel->pStackedWidget->showFullScreen();
#endif
    app.exec();
}
