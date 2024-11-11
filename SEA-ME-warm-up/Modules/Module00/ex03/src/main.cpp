#include "ex03.hpp"

int main(int ac, char** av){
    Phonebook phonebook;
    string cmd;

    while (cmd != "EXIT" && !cin.eof() && !cin.fail()){
        clearScreen("PHONEBOOK");
        cout << "ADD\n";
        cout << "SEARCH\n";
        cout << "REMOVE\n";
        cout << "BOOKMARK\n";
        cout << "EXIT\n";
        cout << '\n';
        cout << "Enter a command: ";
        getline(cin, cmd);
        if (cmd == "ADD")
            phonebook.addContact();
        else if (cmd == "SEARCH")
            phonebook.searchContact();
        else if (cmd == "REMOVE")
            phonebook.removeContact();
        else if (cmd == "BOOKMARK")
            phonebook.printBookmarked();
        else if (cmd != "EXIT")
            cout << "Invalid command\n";
    }
    return (0);
}
