#include "Car.hpp"

Car::Car(int startY, QColor c, QString n)
    : x(0), y(startY), speed(0), color(c), finished(false), name(n) {}

void Car::move()
{
    x += speed;
}

void Car::randomizeSpeed()
{
    speed = QRandomGenerator::global()->bounded(5, 10);
}
