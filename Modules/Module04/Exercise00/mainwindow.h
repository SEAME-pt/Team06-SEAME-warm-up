#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QList>
#include <QDebug>
#include "car.h"
#include "racetrack.h"
#include "carthread.h"
#include "racewidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void startRace();
    void pauseRace();
    void exitGame();

    void stopRace();



private:
    RaceWidget *m_raceWidget; // Painel de desenho para a pista e os carros
    QPushButton *m_startButton;
    QPushButton *m_pauseButton;
    QPushButton *m_exitButton;


    RaceTrack *m_raceTrack;
    QList<Car*> m_carList;
    QList<CarThread*> m_threadList;
    bool m_isPause=false;

    void setupUI(); // Configura o layout e os widgets
    void setupConnections(); // Conecta os botões aos slots
    void onCarFinished(int carIndex); // Sinal emitido quando um carro chega ao fim

};
#endif // MAINWINDOW_H
