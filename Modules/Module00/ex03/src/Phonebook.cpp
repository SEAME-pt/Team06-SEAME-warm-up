#include "Phonebook.hpp"

Phonebook::Phonebook() {
    return;
}

Phonebook::~Phonebook() {
    return;
}

void    Phonebook::addContact() {
    Contact newContact;

    clearScreen("ADD CONTACT");
    newContact.setName(add_prompt("Name: "));
    newContact.setNumber(add_prompt("Number: "));
    newContact.setNickname(add_prompt("Nickname: "));
    newContact.setBookmarked(false);
    this->_contacts.push_back(newContact);
    clearScreen("ADD CONTACT");
    cout << "Contact successfully added to Phonebook\n";
    screenPause();
    return;
}

/*
* Displays selected contact (from index) information and allows user to bookmark or remove bookmark
*/
void    Phonebook::showContact(int& contactIndex) {
     if (!(contactIndex >= 0 && contactIndex < this->_contacts.size())) {
        throw out_of_range("Invalid index");
     }
    clearScreen("SEARCH CONTACT");
    cout << "Name: " << this->_contacts[contactIndex].getName() << '\n';
    cout << "Number: " << this->_contacts[contactIndex].getNumber() << '\n';
    cout << "Nickname: " << this->_contacts[contactIndex].getNickname() << '\n';
    cout << "Bookmarked: " << (this->_contacts[contactIndex].getBookmarked() ? "Yes" : "No") << '\n';
    cout << "\n1. Bookmark\n";
    cout << "2. Remove from Bookmarks\n";
    cout << "Back to menu with an invalid option\n\n";
    switch (add_prompt("Enter an option: ")[0]) {
        case '1':
            this->_contacts[contactIndex].setBookmarked(true);
            break;
        case '2':
            this->_contacts[contactIndex].setBookmarked(false);
            break;
        default:
            break;
    }
}

/*
* Displays list of contacts saved in Phonebook and allows user to select a contact to view
*/
void    Phonebook::searchContact() {
    clearScreen("SEARCH CONTACT");
    try {
        this->hasContacts();
        this->printContacts();
        string input = add_prompt("\nEnter the index of the contact you want to view: ");
        stringstream ss(input);
        int contactIndex;
        ss >> contactIndex;
        contactIndex -= 1;
        this->showContact(contactIndex);
    } catch (out_of_range &e) {
        clearScreen("SEARCH CONTACT");
        cerr << e.what() << '\n';
        screenPause();
    } catch (invalid_argument &e) {
        clearScreen("SEARCH CONTACT");
        cerr << e.what() << '\n';
        screenPause();
    }
    return;
}

/*
* Prints list of contacts saved in Phonebook
*/
void    Phonebook::printContacts() const {
    for (size_t i = 0; i < this->_contacts.size(); i++) {
        cout << i + 1 << ". ";
        cout <<  this->_contacts[i].getName();
        cout << '\n';
        cout.flush();
    }
}

/*
* Option to remove contact by number or from the list
*/
void    Phonebook::removeContact() {
    clearScreen("REMOVE CONTACT");
    try {
        this->hasContacts();
        cout << "1. Contact number\n";
        cout << "2. Show contact list\n";
        string input = add_prompt("\nEnter an option: ");
        if (input == "1") {
            this->removeContactByNumber();
        } else if (input == "2") {
            this->removeContactByIndex();
        } else {
            throw invalid_argument("Invalid option");
        }
    } catch (invalid_argument &e) {
        clearScreen("REMOVE CONTACT");
        cerr << e.what() << '\n';
        screenPause();
    } catch (out_of_range &e) {
        clearScreen("REMOVE CONTACT");
        cerr << e.what() << '\n';
        screenPause();
    }
    return;
}

/*
* Removes all contacts with given number
*/
void   Phonebook::removeContactByNumber() {
    clearScreen("REMOVE CONTACT");
    string number = add_prompt("Enter the number of the contact you want to remove: ");
    int erased = 0;
    for (size_t i = 0; i < this->_contacts.size(); i++) {
        if (this->_contacts[i].getNumber() == number) {
            this->_contacts.erase(this->_contacts.begin() + i);
            erased += 1;
            i -= 1;
        }
    }
    if (erased == 1) {
        clearScreen("REMOVE CONTACT");
        cout << "Contact successfully removed from Phonebook\n";
        screenPause();
        return;
    } else if (erased > 1) {
        clearScreen("REMOVE CONTACT");
        cout << erased << " contacts successfully removed from Phonebook\n";
        screenPause();
        return;
    } else {
        throw invalid_argument("No contacts with that number");
    }
    return;
}

/*
* Removes contact from list by index
*/
void    Phonebook::removeContactByIndex() {
    clearScreen("REMOVE CONTACT");
    this->printContacts();
    string input = add_prompt("Enter the index of the contact you want to remove: ");
    stringstream ss(input);
    int contactIndex;
    ss >> contactIndex;
    contactIndex -= 1;
    if (contactIndex >= 0 && contactIndex < this->_contacts.size()) {
        this->_contacts.erase(this->_contacts.begin() + contactIndex);
        clearScreen("REMOVE CONTACT");
        cout << "Contact successfully removed from Phonebook\n";
        screenPause();
    } else {
        throw out_of_range("Invalid index");
    }
    return;
}

/*
* Prints bookmarked contacts
*/
void    Phonebook::printBookmarked() const {
    clearScreen("BOOKMARKED CONTACTS");
    for (size_t i = 0; i < this->_contacts.size(); i++) {
        if (this->_contacts[i].getBookmarked()) {
            cout << "Name: " << this->_contacts[i].getName() << '\n';
            cout << "Number: " << this->_contacts[i].getNumber() << '\n';
            cout << "Nickname: " << this->_contacts[i].getNickname() << '\n';
            cout << '\n';
        }
    }
    screenPause();
    return;
}

bool    Phonebook::hasContacts() const {
    if (this->_contacts.size() > 0)
        return true;
    else
        throw std::invalid_argument("No contacts in Phonebook");
}

/*
* Prompts user for input and returns trimmed string
* does not allow empty strings or strings with only whitespace
*/
const string add_prompt(const string& s) {
   string	str;

    cout << s << flush;
    while (true) {
        getline(cin, str);
        if (cin.eof()) {
            throw std::runtime_error("Input terminated by user (EOF).");
        }
        if (cin.fail()) {
            cin.clear(); //clear error flags
            cerr << "Invalid input. Please try again.\n";
            continue;
        }
        str = ft_trim_ws(str);
        if (!str.empty() && !ft_isspace(str)) {
            break;
        }
        cerr << "Can't be white spaces!\n";
        cout << s << flush;
    }
    return (str);
}

/*
* Trims whitespace from beginning of string
*/
const string   ft_trim_ws(string s)
{
	int i = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return(s.substr(i, s.length() - i));
}

bool    ft_isspace(const string& s)
{
	for(int i = 0; i < static_cast<int>(s.length()); i++) {
		if(!isspace(s[i]))
			return false;
	}
	return true;
}

/*
* Clears screen and prints header
*/
void    clearScreen(const string& header) {
    cout << "\033[2J\033[1;1H";
    if (!header.empty()) {
        cout << header;
        cout << "\n\n";
        cout.flush();
    }
}

/*
* Pauses program until user presses ENTER
*/
void screenPause() {
    cout << "\nPress ENTER to continue..." << flush;

    while (true) {
        int ch = cin.get();

        if (ch == '\n') {
            break;
        } else if (cin.eof()) {
            throw std::runtime_error("EOF encountered while waiting for ENTER.");
        } else if (cin.fail()) {
            cerr << "Input error detected. Clearing input stream...\n";
            cin.clear();
            cout << "\nPress ENTER to continue..." << flush;
        }
    }
}
