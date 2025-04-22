#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;

public:
    User(std::string uname, std::string pass) : username(uname), password(pass) {}
    virtual ~User() {}

    virtual void displayMenu() = 0;  // Pure virtual function

    std::string getUsername() const { return username; }
};

#endif