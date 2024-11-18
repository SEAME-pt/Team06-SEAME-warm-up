#include "../inc/Car.hpp"

Car::Car() {
    _name = "Prototype";
    _speed = 0;
}

Car::Car(const string& name, int speed) : _name(name), _speed(speed) {
    cout << _name << " is going at " << _speed << " kph" << endl;
}

Car::Car(const Car &other) {
    _name = other._name;
    _speed = other._speed;
    cout << _name << " was copied going at " << _speed << " kph" << endl;
}

Car::~Car() {
    cout << _name << " was destroyed going at " << _speed << " kph" << endl;
}

Car& Car::operator=(const Car &other) {
    cout << _name << " was assigned to " << other._name << " going at " << other._speed << " kph" << endl;
    if (this == &other)
        return *this;
    _name = other._name;
    _speed = other._speed;
    return *this;
}

string Car::getName() const {
    return _name;
}

int Car::getSpeed() const {
    return _speed;
}

void Car::setName(const string& name) {
    _name = name;
}

void Car::setSpeed(int speed) {
    _speed = speed;
    cout << _name << " is now going at " << _speed << " kph" << endl;
}
