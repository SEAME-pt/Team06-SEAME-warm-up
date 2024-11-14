#include "Car.hpp"

Car::Car() : engine_(std::unique_ptr<Engine>(new Engine())),
        transmission_(std::unique_ptr<Transmission>(new Transmission())) {
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