#include "../inc/Car.hpp"

int main() {
    Car porsche("Porsche", 69);
    Car panda(porsche);
    Car twingo("Renault", 11);
    twingo = panda;

    panda.setName("Porsche Panda");
    panda.setSpeed(42);
    twingo.setName("Renault Twingo");
    twingo.setSpeed(299);


    return 0;
}
