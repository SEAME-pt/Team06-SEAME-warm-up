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
    Car(const string&, const string&, int);
    virtual ~Car();

    Car&   operator=(const Car &);

    string getMake() const;
    string getModel() const;
    int    getYear() const;
    virtual void   drive();

private:
    string  _make;
    string  _model;
    int     _year;
};

#endif
