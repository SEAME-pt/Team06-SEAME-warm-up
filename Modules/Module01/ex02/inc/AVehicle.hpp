#ifndef _AVEHICLE_HPP_
#define _AVEHICLE_HPP_

#include <iostream>

class AVehicle
{
public:
    AVehicle();
    AVehicle(const std::string& type);
    AVehicle(const AVehicle& ref);
    virtual             ~AVehicle();

    AVehicle&           operator=(const AVehicle& ref);

    const std::string&  getType() const;

    virtual AVehicle*   build() const = 0;

protected:
    std::string         _type;
};

#endif
