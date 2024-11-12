#include "carthread.h"
#include <QMutexLocker>

CarThread::CarThread(Car *car, RaceTrack *track, QObject *parent)
    : QThread(parent), m_car(car), m_raceTrack(track) {}

void CarThread::run()
{
    while (m_car->position() < m_raceTrack->finishLine())
    {
        QMutexLocker locker(&mutex);
        m_car->move();
        locker.unlock();
        msleep(50);
    }
}
