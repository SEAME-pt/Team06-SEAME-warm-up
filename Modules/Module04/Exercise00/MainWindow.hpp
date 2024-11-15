#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QList>
#include "RaceCanvas.hpp"
#include "CarThread.hpp"
#include "RaceTrack.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startRace();
    void togglePause();
    void resetRace();

private slots:
    void onWinnerDeclared(const QString& winnerName);


private:
    void setupThreads();

    RaceCanvas* canvas;
    RaceTrack*  raceTrack;

    QPushButton* startButton;
    QPushButton* pauseButton;
    QPushButton* resetButton;
    QList<CarThread*> threads;

    bool raceStarted;
    bool isPaused;
};

#endif // MAINWINDOW_HPP
