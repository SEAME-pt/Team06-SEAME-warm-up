#include "ex02.hpp"

string convertUp(string str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = toupper(str[i]);
        }
    }
    return str;
}

string convertDown(string str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

int main(int ac, char** av) {
    if (ac != 3) {
        cerr << "The program takes two arguments: './convert {command} {string}'\n";
        return 1;
    }
    string cmd = av[1];
    string str = av[2];
    if (cmd == "up") {
        cout << convertUp(str) << '\n';
    } else if (cmd == "down"){
        cout << convertDown(str) << '\n';
    } else {
        cerr << "The first argument must be 'up' or 'down'\n";
        return 1;
    }
    return 0;
}
