#include "ex03.hpp"

int main(int ac, char** av){
    try {
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
            cout.flush();
            getline(cin, cmd);
            if (cmd == "ADD")
                phonebook.addContact();
            else if (cmd == "SEARCH")
                phonebook.searchContact();
            else if (cmd == "REMOVE")
                phonebook.removeContact();
            else if (cmd == "BOOKMARK")
                phonebook.printBookmarked();
        }
    } catch (std::runtime_error &e) {
        cerr << e.what() << '\n';
        return (1);
    } catch (std::exception &e) {
        cerr << e.what() << '\n';
    } catch (...) {
        cerr << "An unknown error occurred\n";
    }
    return (0);
}
