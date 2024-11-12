#include "racewidget.h"

#include <QPainter>
#include <QDebug>



RaceWidget::RaceWidget(QWidget *parent)
    : QWidget(parent), m_raceStarted(false),m_timer(new QTimer(this))
{
   connect(m_timer, &QTimer::timeout, this, QOverload<>::of(&RaceWidget::gameUpdate));

}

void RaceWidget::updateCarPosition(int x, int y)
{
    (void)x;
    (void)y;

}

void RaceWidget::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter painter(this);
    paint(painter);
}

void RaceWidget::gameUpdate()
{
    update();
}

void RaceWidget::startRace()
{
    m_isRaceOver=false;
    m_raceStarted = true;
    m_timer->start(30); // update a cada 30 ms
    update();
}

void RaceWidget::pauseRace()
{
    m_timer->stop();
    m_raceStarted = false;
    update(); // redraw o widget
}

void RaceWidget::raceOver()
{
    m_timer->stop();
    m_isRaceOver =true;
    m_raceStarted = false;
    update(); // redraw o widget
}

void RaceWidget::addCars( const QList<Car*> &lista)
{
    m_carList = lista;
    for (int i=0;i<m_carList.size();i++)
    {
        Car * car = m_carList[i];
        connect(car, &Car::positionChanged, this, &RaceWidget::updateCarPosition);
    }
}

/*
void RaceWidget::carFinished(int carIndex)
{
    setFinishLine(carIndex);
}
*/

void RaceWidget::setFinishLine(int finishLine)
{
    m_finishLine = finishLine;
}

int RaceWidget::getFinishLine()
{
    return m_finishLine;
}

void RaceWidget::paint(QPainter &painter)
{
    drawTrack(painter);
    if (m_raceStarted)
    {
        drawCars(painter);
    }
}

void RaceWidget::drawTrack(QPainter &painter)
{
    //painter.save();
    QPen previousPen = painter.pen();  //para restaurar no fim dos draw

    painter.setBrush(Qt::gray);//cor d efundo
    painter.drawRect(10, 10, width() - 20, height() - 20);

    painter.setBrush(Qt::red);//borda da pista
    painter.drawRect(10, TRACK_OFFSET-5, width() - 20, 5);
    painter.drawRect(10, TRACK_OFFSET+((MAX_LINES-1)*TRACK_SIZE), width() - 20, 5);

    QPen trackPen(Qt::black);   //cor da linha
    trackPen.setWidth(2);
    painter.setPen(trackPen);

    for (int i=0;i<MAX_LINES;i++)
    {
       int y =TRACK_OFFSET+(i * TRACK_SIZE);
       painter.drawLine(10,y,width() - 10,y);
    }

    if (m_isRaceOver)
    {

    }

    painter.setPen(previousPen);
    // painter.restore();
}

void RaceWidget::drawCars(QPainter &painter)
{
    if (m_isRaceOver) return;

    if (m_carList.empty())
    {
        qDebug()  << " No cars in Track!";
        return;
    }
    for (int i=0;i<m_carList.size();i++)
    {
        Car * car = m_carList[i];
        car->paint(painter);
        if (car->isFinish())
        {
            emit carFinished(i);
            raceOver();
        }
    }

}
