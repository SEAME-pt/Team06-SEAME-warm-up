#ifndef CARTHREAD_HPP
#define CARTHREAD_HPP

#include <QThread>
#include "Car.hpp"

class CarThread : public QThread
{
    Q_OBJECT
public:
    CarThread(Car* c);

    void pause();
    void resume();
    void stop();

protected:
    void run() override;

signals:
    void updateRequired();

private:
    Car* car;
    bool paused;
    bool finished;
};

#endif // CARTHREAD_HPP
