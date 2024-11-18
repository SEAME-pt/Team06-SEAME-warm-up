#ifndef _CAR_HPP_
#define _CAR_HPP_

#include "AVehicle.hpp"

class Car : public AVehicle
{
public:
    Car();
    Car(const Car& other);
    ~Car();

    Car&                operator=(const Car& other);

    virtual AVehicle*   build() const;
    void                setSpeed(int speed);
    int                 getSpeed() const;


private:
    int _topSpeed;

};

#endif
