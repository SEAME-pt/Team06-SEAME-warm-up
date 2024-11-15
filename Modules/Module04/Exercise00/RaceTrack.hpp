#ifndef RACETRACK_HPP
#define RACETRACK_HPP

class RaceTrack
{
public:
    RaceTrack(int width, int height, int finishLineX);

    int getWidth() const;
    int getHeight() const;
    int getFinishLineX() const;

    void setWidth(int width);
    void setHeight(int height);
    void setFinishLineX(int finishLineX);

private:
    int width;
    int height;
    int finishLineX;
};

#endif // RACETRACK_HPP
