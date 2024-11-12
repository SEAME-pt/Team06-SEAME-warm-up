#include "Car.hpp"

Car::Car(int startY, QColor c, QString n)
    : x(0), y(startY), speed(1), color(c), finished(false), name(n) {}

void Car::randomizeSpeed()
{
    speed = QRandomGenerator::global()->bounded(5, 10);
}
