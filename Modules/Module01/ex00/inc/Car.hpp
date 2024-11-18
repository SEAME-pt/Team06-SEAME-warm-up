#ifndef _CAR_HPP_
#define _CAR_HPP_

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Car {
public:
    Car();
    Car(const Car&);
    Car(const string&, int);
    ~Car();

    Car&   operator=(const Car &);

    string getName() const;
    int    getSpeed() const;
    void   setName(const string&);
    void   setSpeed(int);

private:
    string  _name;
    int     _speed;
};

#endif
