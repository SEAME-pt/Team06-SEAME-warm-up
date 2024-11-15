#include "RaceTrack.hpp"

RaceTrack::RaceTrack(int width, int height, int finishLineX)
    : width(width), height(height), finishLineX(finishLineX) {}

int RaceTrack::getWidth() const
{
    return width;
}

int RaceTrack::getHeight() const
{
    return height;
}

int RaceTrack::getFinishLineX() const
{
    return finishLineX;
}

void RaceTrack::setWidth(int newWidth)
{
    width = newWidth;
}

void RaceTrack::setHeight(int newHeight)
{
    height = newHeight;
}

void RaceTrack::setFinishLineX(int newFinishLineX)
{
    finishLineX = newFinishLineX;
}
