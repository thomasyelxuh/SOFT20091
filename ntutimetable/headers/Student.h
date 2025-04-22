#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>

class Student : public User {
public:
    Student(std::string uname, std::string pass) : User(uname, pass) {}

    void displayMenu() override;  // Ensure you implement this in student.cpp
    void viewTimetable();         // Implement this in student.cpp
};

#endif