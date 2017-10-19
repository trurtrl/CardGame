#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDir>
#include <QtCore/QVector>
#include <QtGui/QPixmap>

#include <QtCore/QTimeLine>

class Animation : public QObject
{
    Q_OBJECT
public:
    QString type;
//    QVector<QPixmap*> vectorSprites;
    QVector<QPixmap> vectorSprites;
    QVector<QPixmap> vectorActiveSprites;

    Animation(QString &type, QObject *parent = nullptr);

signals:

public slots:
    void playAll();
    void idleAnimate();

private:
    QStringList listFiles;
    int scaledWidth;
    int scaledHeight;
    QTimeLine* pTimeLine;

    void setSprites();
    QVector<QPixmap> scaledSprites(QVector<QPixmap> & oldVec);
    int newWidth();
    int newHeight();
    void setActiveSprites();

    float getMultiplierY();
};

#endif // ANIMATION_H
