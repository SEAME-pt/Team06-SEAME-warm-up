#ifndef CAR_HPP
#define CAR_HPP

#include <QString>
#include <QColor>
#include <QRandomGenerator>

class Car
{
public:
    int x;
    int y;
    double speed;
    QColor color;
    bool finished;
    QString name;

    Car(int startY, QColor c, QString n);

    void randomizeSpeed();
};

#endif // CAR_HPP
