#ifndef _SPORTSCAR_HPP_
#define _SPORTSCAR_HPP_

#include "Car.hpp"

class Sportscar : public Car {
public:
    Sportscar();
    Sportscar(const string&, const string&, int, int);
    Sportscar(const Sportscar&);
    ~Sportscar();

    Sportscar&  operator=(const Sportscar &);

    void        drive() override;
    int         getTopSpeed() const;

private:
    int         _topSpeed;
};

#endif
