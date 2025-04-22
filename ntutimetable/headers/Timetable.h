#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "Module.h"  // Include the header for the Module class

class Timetable {
private:
    std::vector<Module> modules;  // Use the Module class (not struct)

public:
    // Methods for managing the timetable
    void addModule(const std::string &name, const std::string &code);
    void displayTimetable() const;
    void saveToFile(const std::string &filename) const;
    void exportToCSV(const std::string &filename) const;
    void loadFromFile(const std::string &filename);
    void removeModule(const std::string &moduleCode);  // Ensure you implement this
};

#endif // TIMETABLE_H