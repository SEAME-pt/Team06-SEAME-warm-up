#ifndef RACEWIDGET_H
#define RACEWIDGET_H


#include <QWidget>
#include <QTimer>
#include <QList>
#include "car.h"

class RaceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RaceWidget(QWidget *parent);
    void startRace();
    void pauseRace();

    void addCars(const QList<Car*> &lista);


    void paint(QPainter &painter);


public slots:
    void updateCarPosition(int x, int y); // Atualiza a posição do carro

protected:
    void paintEvent(QPaintEvent *event) override; // Evento de desenho

private:
    void drawTrack(QPainter &painter);

    void drawCars(QPainter &painter);

    void gameUpdate();

    QList<Car*> m_carList;
    bool m_raceStarted;
    QTimer *m_timer;
};

#endif // RACEWIDGET_H
