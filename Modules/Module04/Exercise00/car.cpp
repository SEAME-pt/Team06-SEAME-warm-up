#include "car.h"
#include <QPainter>

const int CAR_SIZE = 20;

Car::Car(QObject *parent,    QBrush color,int x,int y,int speed, int direction)
    : QObject(parent),m_color(color),m_x(x),m_y(y), m_position(0), m_speed(speed), m_direction(direction),m_isEnd(false) {}

int Car::position() const
{
    return m_position;
}

void Car::move()
{
    m_position += m_speed * m_direction;
    emit  positionChanged(m_position, m_y);



}

void Car::setFinish()
{

    m_isEnd=true;
}

bool Car::isFinish()
{
    return m_isEnd;
}

void Car::paint(QPainter &painter)
{

    if (m_isEnd) return;

    painter.setBrush(m_color);
    painter.drawRect(m_x+ m_position,m_y,CAR_SIZE,CAR_SIZE/2);

     //  qDebug()  << " Paint!"<<m_position;

    //    painter.drawEllipse(m_position, 50, 30, 30);
}
