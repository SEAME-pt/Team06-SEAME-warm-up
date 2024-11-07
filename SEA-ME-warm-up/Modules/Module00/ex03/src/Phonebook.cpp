#include "Phonebook.hpp"

Phonebook::Phonebook() {
    return;
}

Phonebook::~Phonebook() {
    return;
}

void    Phonebook::addContact() {
    Contact newContact;

    clearScreen();
    newContact.setName(add_prompt("Name: "));
    newContact.setNumber(add_prompt("Number: "));
    newContact.setNickname(add_prompt("Nickname: "));
    this->_contacts.push_back(newContact);
    clearScreen();
    cout << "Contact successfully added to Phonebook\n";
    pause();
    return;
}

void    Phonebook::searchContact() {
    int contactIndex;

    clearScreen();
    if (!this->hasContacts()) {
        cout << "No contacts in Phonebook\n";
        pause();
        return;
    }
    this->printContacts();
    string input = add_prompt("Enter the index of the contact you want to view: ");
    stringstream ss(input);
    ss >> contactIndex;
    contactIndex -= 1;
    if (contactIndex >= 0 && contactIndex < this->_contacts.size())
    {
        clearScreen();
        cout << "Name: " << this->_contacts[contactIndex].getName() << '\n';
        cout << "Number: " << this->_contacts[contactIndex].getNumber() << '\n';
        cout << "Nickname: " << this->_contacts[contactIndex].getNickname() << '\n';
        cout << "Bookmarked: " << (this->_contacts[contactIndex].getBookmarked() ? "Yes" : "No") << '\n';
        cout << "\n1. Bookmark\n";
        cout << "2. Remove from Bookmarks\n";
        cout << "3. Back\n";
        if (add_prompt("Enter an option: ") == "1") {
            this->_contacts[contactIndex].setBookmarked(true);
        } else if (add_prompt("Enter an option: ") == "2") {
            this->_contacts[contactIndex].setBookmarked(false);
        } else if (add_prompt("Enter an option: ") == "3") {
            return;
        }
    }
    else {
        clearScreen();
        cout << "Invalid index\n";
    }
    return;
}

void    Phonebook::printContacts() const {
    for (size_t i = 0; i < this->_contacts.size(); i++) {
        cout << i + 1 << ". ";
        cout <<  this->_contacts[i].getName();
        cout << '\n';
    }
}

void    Phonebook::removeContact() {
    int contactIndex;

    clearScreen();
    if (!this->hasContacts()) {
        cout << "No contacts in Phonebook\n";
        pause();
        return;
    }
    cout << "Remmove using contact number or see list of contacts\n";
    cout << "1. Remove using contact number\n";
    cout << "2. See list of contacts\n";
    string input = add_prompt("Enter an option: ");
    if (input == "1") {
        this->removeContactByNumber();
    } else if (input == "2") {
        this->removeContactByIndex();
    } else {
        clearScreen();
        cout << "Invalid option\n";
    }
    return;
}

void   Phonebook::removeContactByNumber() {
    string number;

    clearScreen();
    number = add_prompt("Enter the number of the contact you want to remove: ");
    for (size_t i = 0; i < this->_contacts.size(); i++) {
        if (this->_contacts[i].getNumber() == number) {
            this->_contacts.erase(this->_contacts.begin() + i);
            clearScreen();
            cout << "Contact successfully removed from Phonebook\n";
            pause();
            return;
        }
    }
    clearScreen();
    cout << "Contact not found\n";
    pause();
    return;
}

void    Phonebook::removeContactByIndex() {
    int contactIndex;

    clearScreen();
    this->printContacts();
    string input = add_prompt("Enter the index of the contact you want to remove: ");
    stringstream ss(input);
    ss >> contactIndex;
    contactIndex -= 1;
    if (contactIndex >= 0 && contactIndex < this->_contacts.size()) {
        this->_contacts.erase(this->_contacts.begin() + contactIndex);
        clearScreen();
        cout << "Contact successfully removed from Phonebook\n";
        pause();
    } else {
        clearScreen();
        cout << "Invalid index\n";
        pause();
    }
    return;
}

void    Phonebook::printBookmarked() const {
    clearScreen();
    for (size_t i = 0; i < this->_contacts.size(); i++) {
        if (this->_contacts[i].getBookmarked()) {
            cout << "Name: " << this->_contacts[i].getName() << '\n';
            cout << "Number: " << this->_contacts[i].getNumber() << '\n';
            cout << "Nickname: " << this->_contacts[i].getNickname() << '\n';
            cout << '\n';
        }
    }
    pause();
    return;
}

bool    Phonebook::hasContacts() const {
    return this->_contacts.size() > 0;
}

string add_prompt(string s) {
   string	str;

    while (str.empty() || ft_isspace(str))
    {
        cout << s;
        getline(std::cin, str);
        if (std::cin.eof() ||cin.fail())
            exit (1);
    }
    return (ft_trim_ws(str));
}

std::string	ft_trim_ws(std::string s)
{
	int i = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return(s.substr(i, s.length() - i));
}

bool	ft_isspace(std::string s)
{
	for(int i = 0; i < static_cast<int>(s.length()); i++)
	{
		if(!std::isspace(s[i]))
			return false;
	}
	return true;
}


void clearScreen(){
    cout << "\033[2J\033[1;1H";
}

void pause(){
    cout << "Press ENTER to continue...";
    while(1) {
        if (cin.get() == '\n')
            break;
    }
}
