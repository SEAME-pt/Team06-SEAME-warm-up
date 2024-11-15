#include "CarThread.hpp"
#include <QMutex>

CarThread::CarThread(Car* c)
    : car(c), paused(false), finished(false) {}

void CarThread::pause() { paused = true; }
void CarThread::resume() { paused = false; }
void CarThread::stop() { finished = true; }

void CarThread::run()
{
    while(!finished && !car->finished)
    {
        if(!paused)
        {
            msleep(20);
            car->x += car->speed;
            emit updateRequired();
        }
        msleep(10);
    }
}
