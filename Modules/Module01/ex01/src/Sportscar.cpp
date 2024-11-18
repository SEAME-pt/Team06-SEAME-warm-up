#include "../inc/Sportscar.hpp"

Sportscar::Sportscar() : Car() {
    _topSpeed = 200;
    cout << "Sportscar with top speed of " << _topSpeed << " was created" << endl;
}

Sportscar::Sportscar(const string& make, const string& model, int year, int topSpeed) : Car(make, model, year), _topSpeed(topSpeed) {
    cout << "Sportscar with top speed of " << _topSpeed << " was created" << endl;
}

Sportscar::Sportscar(const Sportscar &other) : Car(other) {
    _topSpeed = other._topSpeed;
    cout << "Sportscar with top speed of " << _topSpeed << " was cloned" << endl;
}

Sportscar::~Sportscar() {
    cout << "Sportscar with top speed of " << _topSpeed << " was destroyed" << endl;
}

Sportscar& Sportscar::operator=(const Sportscar &other) {
    if(this == &other)
        return *this;
    Car::operator=(other);
    _topSpeed = other._topSpeed;
    cout << "Sportscar with top speed of " << _topSpeed << " was assigned" << endl;
    return *this;
}

int    Sportscar::getTopSpeed() const {
    return _topSpeed;
}

void    Sportscar::drive() {
    Car::drive();
    cout << "Speed: " << _topSpeed << endl;
}

