#include "RaceCanvas.hpp"
#include <QPainter>

RaceCanvas::RaceCanvas(RaceTrack* track, QWidget *parent)
    : QWidget(parent), laneHeight(80), winner(nullptr), raceTrack(track)
{
    setMinimumSize(raceTrack->getWidth(), raceTrack->getHeight());
}

RaceCanvas::~RaceCanvas()
{
    for (Car* car : cars)
    {
        delete car;
    }
    cars.clear();
}

void RaceCanvas::addCar(Car* car)
{
    cars.append(car);
    update();
}

void RaceCanvas::reset()
{
    for(auto car : cars)
    {
        car->x = 0;
        car->finished = false;
       // car->randomizeSpeed();
    }
    winner = nullptr;
    update();
}

QList<Car*>& RaceCanvas::getCars()
{
    return cars;
}

Car* RaceCanvas::getWinner() const
{
    return winner;
}

void RaceCanvas::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(0, 0, width(), height(), Qt::darkGray);

    painter.setPen(QPen(Qt::white, 2, Qt::DashLine));
    for(int i = 1; i < cars.size(); i++)
    {
        painter.drawLine(0, i * laneHeight, width(), i * laneHeight);
    }

    painter.fillRect(50, 0, 5, height(), Qt::white);

    int finishX = raceTrack->getFinishLineX(); // Posição da linha de chegada

    // Desenha linha de chegada
    for(int y = 0; y < height(); y += 20)
    {
        painter.fillRect(finishX, y, 20, 10, Qt::white);
        painter.fillRect(finishX + 20, y + 10, 20, 10, Qt::white);
    }

    for(const auto& car : cars)
    {
        painter.fillRect(car->x + 50, car->y + laneHeight/4, 40, 30, car->color);
        painter.fillRect(car->x + 70, car->y + laneHeight/4 + 5, 15, 20, Qt::lightGray);

        painter.fillRect(car->x + 55, car->y + laneHeight/4 - 5, 10, 5, Qt::black);
        painter.fillRect(car->x + 75, car->y + laneHeight/4 - 5, 10, 5, Qt::black);
        painter.fillRect(car->x + 55, car->y + laneHeight/4 + 30, 10, 5, Qt::black);
        painter.fillRect(car->x + 75, car->y + laneHeight/4 + 30, 10, 5, Qt::black);

        painter.setPen(Qt::white);
        painter.drawText(car->x + 50, car->y + laneHeight/4 - 10, QString("Speed %1").arg(car->speed));

        if(!car->finished && car->x + 90 >= finishX)
        {
            car->finished = true;
            if (!winner)
            {
                winner = car;
                emit winnerDeclared(winner->name);  // Emite o sinal com o nome do vencedor
            }
        }
    }

    if(winner)
    {
        painter.setPen(Qt::yellow);
        painter.setFont(QFont("Arial", 20, QFont::Bold));
        painter.drawText(width()/2 - 100, 30,QString("VENCEDOR: %1!").arg(winner->name));
        for(auto& car : cars)
        {
           car->speed=0;
        }

    }
}

