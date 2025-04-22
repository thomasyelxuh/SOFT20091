#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <iostream>

class Admin : public User {
public:
    Admin(std::string uname, std::string pass) : User(uname, pass) {}

    void displayMenu() override;  // Ensure you have an implementation for this
    void manageTimetable();       // You should implement this method in admin.cpp
};

#endif