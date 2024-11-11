#include "Car.hpp"

Car::Car() {
	engine_ = make_unique<Engine>();
	transmission_ = make_unique<Transmission>();
}

void Car::printParts() const {
	engine_->print();
	transmission_->print();
	for (const auto& wheel : wheels_) {
		wheel.print();
	}
	for (const auto& brake : brakes_) {
		brake.print();
	}
}


int main() {
    Car myCar;
    myCar.printParts();
    
    return 0;
}