#include "User.h"

// Constructor
User::User(std::string uname, std::string pass) 
    : username(uname), password(pass) {}

// Getter
std::string User::getUsername() const { return username; }