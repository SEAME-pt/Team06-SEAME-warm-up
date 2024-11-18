#include "../inc/AVehicle.hpp"

AVehicle::AVehicle() : _type("default")
{
    std::cout << "AVehicle default constructor called\n";
}

AVehicle::AVehicle(const std::string& type) : _type(type)
{
    std::cout << "AVehicle parameter constructor called\n";
}

AVehicle::AVehicle(const AVehicle& other)
{
    std::cout << "AVehicle copy constructor called\n";
    *this = other;
}

AVehicle::~AVehicle()
{
    std::cout << "AVehicle destructor called\n";
}

AVehicle&	AVehicle::operator=(const AVehicle& other)
{
    if (this != &other)
        this->_type = other.getType();
    return *this;
}

const std::string&	AVehicle::getType() const
{
    return this->_type;
}
