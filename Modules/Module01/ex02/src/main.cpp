#include "../inc/AVehicle.hpp"
#include "../inc/Car.hpp"
#include <iostream>
#include <string>

int main() {
    Car myCar;

    // Encapsulation: Setting the speed using setter method
    myCar.setSpeed(120);

    // Access the speed using getter method (encapsulation in action)
    std::cout << "The top speed of my car is: " << myCar.getSpeed() << " km/h" << std::endl;

    // Polymorphism and Abstraction: Calling the virtual 'build' method
    AVehicle* builtCar = myCar.build();

    // Display the type of vehicle (demonstrates polymorphism)
    std::cout << "Vehicle type: " << builtCar->getType() << std::endl;

    delete builtCar;

    return 0;
}
