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
    pause();
    return;
}

void    Phonebook::searchContact() {
    int contactIndex;

    clearScreen("SEARCH CONTACT");
    if (!this->hasContacts()) {
        cout << "No contacts in Phonebook\n";
        pause();
        return;
    }
    this->printContacts();
    string input = add_prompt("\nEnter the index of the contact you want to view: ");
    stringstream ss(input);
    ss >> contactIndex;
    contactIndex -= 1;
    if (contactIndex >= 0 && contactIndex < this->_contacts.size())
    {
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
                clearScreen("SEARCH CONTACT");
                cout << "Invalid option\n";
                break;
        }
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

    clearScreen("REMOVE CONTACT");
    if (!this->hasContacts()) {
        cout << "No contacts in Phonebook\n";
        pause();
        return;
    }
    cout << "1. Contact number\n";
    cout << "2. Show contact list\n";
    string input = add_prompt("\nEnter an option: ");
    if (input == "1") {
        this->removeContactByNumber();
    } else if (input == "2") {
        this->removeContactByIndex();
    } else {
        clearScreen("REMOVE CONTACT");
        cout << "Invalid option\n";
    }
    return;
}

void   Phonebook::removeContactByNumber() {
    string number;

    clearScreen("REMOVE CONTACT");
    number = add_prompt("Enter the number of the contact you want to remove: ");
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
        pause();
        return;
    } else if (erased > 1) {
        clearScreen("REMOVE CONTACT");
        cout << erased << " contacts successfully removed from Phonebook\n";
        pause();
        return;
    }
    clearScreen("REMOVE CONTACT");
    cout << "Contact not found\n";
    pause();
    return;
}

void    Phonebook::removeContactByIndex() {
    int contactIndex;

    clearScreen("REMOVE CONTACT");
    this->printContacts();
    string input = add_prompt("Enter the index of the contact you want to remove: ");
    stringstream ss(input);
    ss >> contactIndex;
    contactIndex -= 1;
    if (contactIndex >= 0 && contactIndex < this->_contacts.size()) {
        this->_contacts.erase(this->_contacts.begin() + contactIndex);
        clearScreen("REMOVE CONTACT");
        cout << "Contact successfully removed from Phonebook\n";
        pause();
    } else {
        clearScreen("REMOVE CONTACT");
        cout << "Invalid index\n";
        pause();
    }
    return;
}

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
    pause();
    return;
}

bool    Phonebook::hasContacts() const {
    return this->_contacts.size() > 0;
}

const string add_prompt(const string& s) {
   string	str;

    cout << s;
    while (str.empty() || ft_isspace(str))
    {
        getline(cin, str);
        if (cin.eof() ||cin.fail())
            exit (1);
    }
    return (ft_trim_ws(str));
}

const string   ft_trim_ws(string s)
{
	int i = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return(s.substr(i, s.length() - i));
}

bool    ft_isspace(const string& s)
{
	for(int i = 0; i < static_cast<int>(s.length()); i++)
	{
		if(!isspace(s[i]))
			return false;
	}
	return true;
}


void    clearScreen(const string& header) {
    cout << "\033[2J\033[1;1H";
    if (!header.empty()) {
        cout << header;
        cout << "\n\n";
        cout.flush();
    }
}

void    pause(){
    cout << "\nPress ENTER to continue...";
    while(1) {
        if (cin.get() == '\n')
            break;
    }
}
