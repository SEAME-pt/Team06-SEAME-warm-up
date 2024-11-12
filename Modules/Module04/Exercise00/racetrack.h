#ifndef RACETRACK_H
#define RACETRACK_H


class RaceTrack
{
public:
    explicit RaceTrack(int size = 1000, int finishLine = 950);
    int size() const;
    int finishLine() const;

private:
    int m_size;
    int m_finishLine;
};


#endif // RACETRACK_H
