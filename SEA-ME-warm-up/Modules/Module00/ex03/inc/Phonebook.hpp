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
using std::getline;
using std::isspace;
using std::string;
using std::stringstream;
using std::vector;

class Phonebook
{
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
};

const string  add_prompt(const string& s);
const string  ft_trim_ws(string s);
bool    ft_isspace(const string& s);
void    pause();
void    clearScreen(const string& header = "");

#endif
