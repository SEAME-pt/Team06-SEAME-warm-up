#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Function to convert a string to uppercase
std::string to_upper(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Function to convert a string to lowercase
std::string to_lower(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}



int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./convert {command} {string}" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    std::string input = argv[2];

    if (command == "up") {
        std::cout << "Uppercase: " << to_upper(input) << std::endl;
    } else if (command == "down") {
        std::cout << "Lowercase: " << to_lower(input) << std::endl;
    } else {
        std::cerr << "Invalid command. Use 'up' or 'down'." << std::endl;
        return 1;
    }

    // Demonstrate string class functions
    std::cout << "\nDemonstrating std::string functions:" << std::endl;
    demo_string_methods(input);

    return 0;
}
