#include <gtest/gtest.h>
#include "../inc/Car.hpp"

/* TEST(CarTest, CarConstructor) {
	Car myCar;
	EXPECT_EQ(myCar.printParts(), "Engine part\nTransmission part\nWheel part\nWheel part\nWheel part\nWheel part\nBrake part\nBrake part\nBrake part\nBrake part\n");
} */



TEST(CarTest, PrintPartsOutput) {
    Car myCar;

    // Redireciona o std::cout para um stringstream para capturar a saída
    std::stringstream buffer;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    // Chama a função que imprime no terminal
    myCar.printParts();

    // Restaura o buffer original de std::cout
    std::cout.rdbuf(oldCoutBuffer);

    // Verifica se a saída capturada é a esperada
    std::string expectedOutput = 
        "Engine part\n"
        "Transmission part\n"
        "Wheel part\n"
        "Wheel part\n"
        "Wheel part\n"
        "Wheel part\n"
        "Brake part\n"
        "Brake part\n"
        "Brake part\n"
        "Brake part\n";

    EXPECT_EQ(buffer.str(), expectedOutput);
}

/* int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
} */