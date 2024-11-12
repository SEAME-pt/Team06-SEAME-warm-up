#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QRandomGenerator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    m_raceWidget =new RaceWidget(this);
    m_raceTrack  =new RaceTrack();

    m_isPause =false;

    setupUI();
    setupConnections();
    //QBrush color, int x, int y,int speed = 1, int direction = 1);

    QBrush colors[] = {Qt::red,Qt::green,Qt::blue,Qt::yellow,Qt::magenta,Qt::white};

    for (int i = 0; i < 5; ++i)
    {

        int y = 10 + TRACK_OFFSET+(i * TRACK_SIZE);

        int speed = QRandomGenerator::global()->bounded(5, 10);

        Car *car = new Car(this,colors[i], 14, y,speed);
         m_carList.append(car);

       CarThread *carThread = new CarThread(car, m_raceTrack, this);
       m_threadList.append(carThread);
    }

    m_raceWidget->addCars(m_carList);

   // connect(m_raceWidget, &RaceWidget::carFinished, this, &MainWindow::onCarFinished);


}


MainWindow::~MainWindow()
{

    stopRace();



    qDeleteAll(m_carList);
    qDeleteAll(m_threadList);
    delete m_raceTrack;
    qDebug()<<"Exit Application !";
}

/*
void MainWindow::onCarFinished(int carIndex)
{
    QMessageBox::information(this, "Car Finished", QString("Car %1 has reached the finish line!").arg(carIndex + 1));
    stopRace();
}
*/

void MainWindow::stopRace()
{
    m_raceWidget->raceOver();
    for (CarThread *thread : m_threadList)
    {
        thread->doAbort();
        if (thread->isRunning())
        {
            thread->doAbort();
            thread->wait();
        }
    }
}

void MainWindow::setupUI()
{

    this->setFixedSize(800,400);

    m_startButton = new QPushButton("Start Race", this);
    m_pauseButton = new QPushButton("Pause", this);
    m_exitButton = new QPushButton("Exit", this);

    // Configuração do layout principal
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Adiciona o RaceWidget (painel de desenho) ao layout
    mainLayout->addWidget(m_raceWidget);

    // Layout para os botões
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(m_startButton);
    buttonLayout->addWidget(m_pauseButton);
    buttonLayout->addWidget(m_exitButton);

    m_pauseButton->setDisabled(true);

    // Adiciona o layout dos botões ao layout principal
    mainLayout->addLayout(buttonLayout);

    setCentralWidget(centralWidget);
}

void MainWindow::setupConnections()
{
    connect(m_startButton, &QPushButton::clicked, this, &MainWindow::startRace);
    connect(m_pauseButton, &QPushButton::clicked, this, &MainWindow::pauseRace);
    connect(m_exitButton, &QPushButton::clicked, this, &MainWindow::exitGame);
}

void MainWindow::startRace()
{
    m_isPause=false;
    m_startButton->setDisabled(true);
    m_pauseButton->setDisabled(false);

    for (CarThread *carThread : m_threadList)
    {
        if (!carThread->isRunning())
        {
            carThread->start();

        }
    }
    m_raceWidget->startRace();

}

void MainWindow::pauseRace()
{

    if (m_isPause)
    {
        m_pauseButton->setDisabled(true);
        m_startButton->setDisabled(false);
        m_startButton->setText("Start");
        m_isPause=false;
    } else
    {
        m_isPause=true;
        m_startButton->setDisabled(false);
        m_pauseButton->setDisabled(true);
        m_startButton->setText("Resume");
        m_raceWidget->pauseRace();

    }

  //  QMessageBox::information(this, "Pause", "Race paused!");




}

void MainWindow::exitGame()
{
    close();
}
