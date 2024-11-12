#ifndef CAR_H
#define CAR_H


#include <QObject>
#include <QWidget>

const int MAX_LINES =6;
const int TRACK_SIZE =35;
const int TRACK_OFFSET =100;



class Car : public QObject
{
    Q_OBJECT

public:
    explicit Car(QObject *parent,    QBrush color, int x, int y,int speed = 1, int direction = 1);
    int position() const;
    void move();
    void paint(QPainter &painter);

    void setFinish();
    bool isFinish();


signals:
     void positionChanged(int x, int y);

private:
    QBrush m_color;
    int m_x;
    int m_y;
    int m_position;
    int m_speed;
    int m_direction;
    bool m_isEnd;
    int m_tmpY;
    int m_tmpX;


};


#endif // CAR_H
