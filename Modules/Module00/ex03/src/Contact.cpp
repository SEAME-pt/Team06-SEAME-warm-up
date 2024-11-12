#include "Contact.hpp"

Contact::Contact(){
    return;
}

Contact::~Contact(){
    return;
}

void    Contact::setName(const string& name){
    this->_name = name;
}

void    Contact::setNumber(const string& number){
    this->_number = number;
}

void    Contact::setNickname(const string& nickname){
    this->_nickname = nickname;
}

void    Contact::setBookmarked(bool bookmarked){
    this->_bookmarked = bookmarked;
}

string  Contact::getName() const{
    return this->_name;
}

string  Contact::getNumber() const{
    return this->_number;
}

string  Contact::getNickname() const{
    return this->_nickname;
}

bool    Contact::getBookmarked() const{
    return this->_bookmarked;
}

