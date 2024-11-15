#include "../inc/Car.hpp"
#include "../inc/Sportscar.hpp"

int main() {
    Car       myCar("Toyota", "Corolla", 2020);
    Sportscar mySportscar("Porsche", "911 Turbo", 2024, 320);

    myCar.drive();
    mySportscar.drive();

    Sportscar anotherSportscar(mySportscar);
    Sportscar thirdSportscar;

    thirdSportscar = mySportscar;
    thirdSportscar.drive();

    return 0;
}
