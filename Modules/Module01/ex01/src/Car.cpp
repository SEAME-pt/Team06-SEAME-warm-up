#include "../inc/Car.hpp"

Car::Car() {
    _make = "Toyota";
    _model = "Prototype";
    _year = 2024;
    cout << _make << " " << _model << " (" << _year << ") was created" << endl;
}

Car::Car(const string& make, const string& model, int year) : _make(make), _model(model), _year(year) {
    cout << _make << " " << _model << " (" << _year << ") was created" << endl;
}

Car::Car(const Car &other) {
    _make = other._make;
    _model = other._model;
    _year = other._year;
    cout << _make << " " << _model << " (" << _year << ") was cloned" << endl;
}

Car::~Car() {
    cout << _make << " " << _model << " (" << _year << ") was destroyed" << endl;
}

Car& Car::operator=(const Car &other) {
    if(this == &other)
        return *this;
    _make = other._make;
    _model = other._model;
    _year = other._year;
    cout << _make << " " << _model << " (" << _year << ") was assigned" << endl;
    return *this;
}

string Car::getMake() const {
    return _make;
}

string Car::getModel() const {
    return _model;
}

int    Car::getYear() const {
    return _year;
}

void    Car::drive() {
    cout << _make << " " << _model << " (" << _year << ") is driving" << endl;
}


