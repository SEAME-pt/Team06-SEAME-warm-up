#include <QMutexLocker>
#include <QDebug>

#include "carthread.h"

CarThread::CarThread(Car *car, RaceTrack *track, QObject *parent)
    : QThread(parent), m_car(car), m_raceTrack(track) {}

void CarThread::run()
{
    while (m_car->position() < m_raceTrack->finishLine())
    {
        m_mutex.lock();
        if (m_abort)
        {
            m_mutex.unlock();
            break;
        }
        m_mutex.unlock();
        if (!m_pause)
            m_car->move();
        msleep(50);
    }
    m_car->setFinish();
    qDebug()<<"Finished !";
}

void CarThread::doAbort()
{
    QMutexLocker locker(&m_mutex);
    m_abort=true;
}

void CarThread::doPause(bool pause)
{
    QMutexLocker locker(&m_mutex);
    m_pause=pause;
}
