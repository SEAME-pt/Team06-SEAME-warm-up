#include <gtest/gtest.h>
#include "../inc/Sportscar.hpp"

TEST(SportscarTest, DefaultConstructor) {
    Sportscar car;
    EXPECT_EQ(car.getMake(), "Toyota");
    EXPECT_EQ(car.getModel(), "Prototype");
    EXPECT_EQ(car.getYear(), 2024);
    EXPECT_EQ(car.getTopSpeed(), 200);
}

TEST(SportscarTest, ParameterizedConstructor) {
    Sportscar car("Porsche", "911", 2021, 320);
    EXPECT_EQ(car.getMake(), "Porsche");
    EXPECT_EQ(car.getModel(), "911");
    EXPECT_EQ(car.getYear(), 2021);
    EXPECT_EQ(car.getTopSpeed(), 320);
}

TEST(SportscarTest, CopyConstructor) {
    Sportscar car("Porsche", "911", 2021, 320);
    Sportscar car2(car);
    EXPECT_EQ(car2.getMake(), "Porsche");
    EXPECT_EQ(car2.getModel(), "911");
    EXPECT_EQ(car2.getYear(), 2021);
    EXPECT_EQ(car2.getTopSpeed(), 320);
}

TEST(SportscarTest, AssignmentOperator) {
    Sportscar car("Porsche", "911", 2021, 320);
    Sportscar car2;
    car2 = car;
    EXPECT_EQ(car2.getMake(), "Porsche");
    EXPECT_EQ(car2.getModel(), "911");
    EXPECT_EQ(car2.getYear(), 2021);
    EXPECT_EQ(car2.getTopSpeed(), 320);
}

TEST(SportscarTest, Drive) {
    Sportscar car("Porsche", "911", 2021, 320);
    testing::internal::CaptureStdout();
    car.drive();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Porsche 911 (2021) is driving\nSpeed: 320\n");
}

