#include <gtest/gtest.h>
#include "../inc/AVehicle.hpp"
#include "../inc/Car.hpp"

// Test for the Car class
class CarTest : public ::testing::Test {
protected:
    // You can initialize common objects in the SetUp() function
    CarTest() {
        car = new Car();
    }

    // You can clean up the resources in the TearDown() function
    ~CarTest() override {
        delete car;
    }

    void SetUp() override {
        // Initialize the car with a specific speed before each test
        car->setSpeed(150);
    }

    void TearDown() override {
        // Reset or clean up anything needed after each test
    }

    Car* car; // A pointer to the Car object for testing
};

// Test that the car has the correct speed set using the getter
TEST_F(CarTest, TestGetSpeed) {
    EXPECT_EQ(car->getSpeed(), 150);
}

// Test the build method that should return a new Car object
TEST_F(CarTest, TestBuild) {
    AVehicle* builtCar = car->build();

    // Verify that the built car is of type "car"
    EXPECT_EQ(builtCar->getType(), "car");

    // Clean up the dynamically created object
    delete builtCar;
}

// Test the type of the car (which should be "car")
TEST_F(CarTest, TestCarType) {
    EXPECT_EQ(car->getType(), "car");
}

// Test that the assignment operator works correctly
TEST_F(CarTest, TestAssignmentOperator) {
    Car anotherCar;
    anotherCar = *car;

    // Ensure the assignment works correctly
    EXPECT_EQ(anotherCar.getSpeed(), car->getSpeed());
    EXPECT_EQ(anotherCar.getType(), car->getType());
}

// Test the copy constructor
TEST_F(CarTest, TestCopyConstructor) {
    Car copiedCar(*car);

    // Ensure the copy constructor works as expected
    EXPECT_EQ(copiedCar.getSpeed(), car->getSpeed());
    EXPECT_EQ(copiedCar.getType(), car->getType());
}

