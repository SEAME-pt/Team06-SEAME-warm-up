#include <gtest/gtest.h>
#include "../inc/Car.hpp"

// Test default constructor
TEST(CarTest, DefaultConstructor) {
    Car car;
    EXPECT_EQ(car.getName(), "Prototype");
    EXPECT_EQ(car.getSpeed(), 0);
}

// Test parameterized constructor
TEST(CarTest, ParameterizedConstructor) {
    Car car("Porsche Panda", 69);
    EXPECT_EQ(car.getName(), "Porsche Panda");
    EXPECT_EQ(car.getSpeed(), 69);
}

// Test copy constructor
TEST(CarTest, CopyConstructor) {
    Car original("Ferrari", 100);
    Car copy(original);

    EXPECT_EQ(copy.getName(), original.getName());
    EXPECT_EQ(copy.getSpeed(), original.getSpeed());
}

// Test assignment operator
TEST(CarTest, AssignmentOperator) {
    Car car1("Lambo", 200);
    Car car2;
    car2 = car1;

    EXPECT_EQ(car2.getName(), "Lambo");
    EXPECT_EQ(car2.getSpeed(), 200);
}

// Test setName and setSpeed methods
TEST(CarTest, SetMethods) {
    Car car;
    car.setName("BMW");
    car.setSpeed(150);

    EXPECT_EQ(car.getName(), "BMW");
    EXPECT_EQ(car.getSpeed(), 150);
}

// Test getName and getSpeed methods
TEST(CarTest, GetMethods) {
    Car car("Toyota", 120);

    EXPECT_EQ(car.getName(), "Toyota");
    EXPECT_EQ(car.getSpeed(), 120);
}
