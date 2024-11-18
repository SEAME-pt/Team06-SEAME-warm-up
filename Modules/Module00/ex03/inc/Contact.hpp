#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

using std::string;

class Contact
{
public:
    Contact();
    ~Contact();
    void    setName(const string& name);
    void    setNumber(const string& number);
    void    setNickname(const string& nickname);
    void    setBookmarked(bool bookmarked);
    string  getName() const;
    string  getNumber() const;
    string  getNickname() const;
    bool    getBookmarked() const;

private:
    string  _name;
    string  _number;
    string  _nickname;
    bool    _bookmarked;
};

#endif
