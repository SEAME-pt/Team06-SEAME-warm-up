#ifndef RACECANVAS_HPP
#define RACECANVAS_HPP

#include <QWidget>
#include <QList>
#include "Car.hpp"
#include "RaceTrack.hpp"

class RaceCanvas : public QWidget
{
    Q_OBJECT
public:
    RaceCanvas(RaceTrack* track, QWidget *parent = nullptr);
    ~RaceCanvas();

    void addCar(Car* car);
    void reset();
    QList<Car*>& getCars();
    Car* getWinner() const;

signals:
    void winnerDeclared(const QString& winnerName);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QList<Car*> cars;
    int laneHeight;
    Car* winner;
    RaceTrack* raceTrack;
};

#endif // RACECANVAS_HPP
