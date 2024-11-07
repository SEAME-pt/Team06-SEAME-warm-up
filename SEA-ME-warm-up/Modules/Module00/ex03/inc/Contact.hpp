#pragma once

#include <string>

using std::string;

class Contact {
    public:
        Contact();
        ~Contact();
        void    setName(string name);
        void    setNumber(string number);
        void    setNickname(string nickname);
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
