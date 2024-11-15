#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), raceStarted(false), isPaused(false)
{
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    raceTrack = new RaceTrack(800, 400, 700);
    canvas = new RaceCanvas(raceTrack, this);

    connect(canvas, &RaceCanvas::winnerDeclared, this, &MainWindow::onWinnerDeclared);


    layout->addWidget(canvas);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    startButton = new QPushButton("Iniciar", this);
    pauseButton = new QPushButton("Pausar", this);
    resetButton = new QPushButton("Reiniciar", this);

    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(pauseButton);
    buttonLayout->addWidget(resetButton);
    layout->addLayout(buttonLayout);

    setCentralWidget(centralWidget);

    Car* car1 = new Car(0, Qt::blue, "Carro Azul");
    Car* car2 = new Car(80, Qt::green, "Carro Verde");
    Car* car3 = new Car(160, Qt::red, "Carro Vermelho");
    Car* car4 = new Car(240, Qt::yellow, "Carro Amarelo");

    canvas->addCar(car1);
    canvas->addCar(car2);
    canvas->addCar(car3);
    canvas->addCar(car4);

    setupThreads();

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startRace);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::togglePause);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetRace);

    pauseButton->setEnabled(false);
    resetButton->setEnabled(false);
    setWindowTitle("Corrida de Carros");
}

MainWindow::~MainWindow()
{

    for(auto thread : threads)
    {
        thread->stop();
        thread->wait();
        delete thread;
    }

    delete raceTrack;
}

void MainWindow::onWinnerDeclared(const QString& winnerName)
{
    (void)winnerName;
//    QMessageBox::information(this, "Vencedor", QString("O vencedor é: %1!").arg(winnerName));
    /*
    for (auto thread : threads)
{
        thread->pause();
    }
    isPaused = true;

 pauseButton->setText("Continuar");
*/

            pauseButton->setEnabled(false);

}

void MainWindow::startRace()
{
    if(!raceStarted)
    {
        for(auto car : canvas->getCars())
        {
           car->randomizeSpeed();
        }
        for(auto thread : threads)
        {
            thread->start();
        }
        raceStarted = true;
        startButton->setEnabled(false);
        pauseButton->setEnabled(true);
        resetButton->setEnabled(true);
    }
}

void MainWindow::togglePause()
{
    isPaused = !isPaused;
    for(auto thread : threads)
    {
        if(isPaused)
        {
            thread->pause();
            pauseButton->setText("Continuar");
        } else
        {
            thread->resume();
            pauseButton->setText("Pausar");
        }
    }
}

void MainWindow::resetRace()
{
    for(auto thread : threads)
    {
        thread->stop();
        thread->wait();
        delete thread;
    }
    threads.clear();

    canvas->reset();
    setupThreads();

    raceStarted = false;
    isPaused = false;
    startButton->setEnabled(true);
    pauseButton->setEnabled(false);
    pauseButton->setText("Pausar");
}

void MainWindow::setupThreads()
{
    for(auto car : canvas->getCars())
    {
        CarThread* thread = new CarThread(car);
        connect(thread, &CarThread::updateRequired, canvas, QOverload<>::of(&RaceCanvas::update));
        threads.append(thread);
    }
}
