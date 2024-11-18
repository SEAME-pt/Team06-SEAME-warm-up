#include "../inc/Car.hpp"

Car::Car() : AVehicle("car")
{
    std::cout << "Car default constructor called\n";
}

Car::Car(const Car& other) : AVehicle(other), _topSpeed(other._topSpeed)
{
    std::cout << "Car copy constructor called\n";
    *this = other;
}

Car::~Car()
{
    std::cout << "Car destructor called\n";
}

Car&	Car::operator=(const Car& other)
{
    if (this != &other) {
        AVehicle::operator=(other);
        _topSpeed = other._topSpeed;
    }
    return *this;
}

AVehicle*	Car::build() const
{
    std::cout << "New car built\n";
    return new Car();
}

void	Car::setSpeed(int speed)
{
    if (speed < 0)
        this->_topSpeed = 0;
    else
        this->_topSpeed = speed;
}

int		Car::getSpeed() const
{
    return this->_topSpeed;
}
