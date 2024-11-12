#ifndef CARTHREAD_H
#define CARTHREAD_H


#include <QThread>
#include <QMutex>
#include "car.h"
#include "racetrack.h"


class CarThread : public QThread
{
    Q_OBJECT

public:
    explicit CarThread(Car *car, RaceTrack *track, QObject *parent = nullptr);
    void run() override;

private:
    Car *m_car;
    RaceTrack *m_raceTrack;
    QMutex mutex;
};;

#endif // CARTHREAD_H
