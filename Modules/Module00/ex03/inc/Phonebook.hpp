#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::invalid_argument;
using std::isspace;
using std::out_of_range;
using std::string;
using std::stringstream;
using std::vector;
using std::cerr;
using std::flush;

// class PhonebookTest;

class Phonebook
{
    // friend class PhonebookTest;
public:
    Phonebook();
    ~Phonebook();
    void addContact();
    void searchContact();
    void removeContact();
    void printBookmarked() const;

private:
    vector<Contact> _contacts;

    void printContacts() const;
    void removeContactByNumber();
    void removeContactByIndex();
    bool hasContacts() const;
    void showContact(int &contactIndex);

};

const string    add_prompt(const string& s);
const string    ft_trim_ws(string s);
bool            ft_isspace(const string& s);
void            screenPause();
void            clearScreen(const string& header = "");

#endif
