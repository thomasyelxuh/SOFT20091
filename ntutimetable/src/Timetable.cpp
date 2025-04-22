#include "Timetable.h"
#include <fstream>
#include <sstream>  // For string stream operations to handle CSV correctly

void Timetable::addModule(const std::string &name, const std::string &code) {
    try {
        modules.push_back(Module(name, code));
        std::cout << "Module " << name << " added successfully.\n";
    } catch (const std::exception &e) {
        std::cerr << "Error adding module: " << e.what() << "\n";
    }
}

void Timetable::displayTimetable() const {
    if (modules.empty()) {
        std::cout << "No modules scheduled.\n";
        return;
    }

    std::cout << "===== Timetable =====\n";
    for (const auto &mod : modules) {
        std::cout << "Module: " << mod.getModuleName() << " | Code: " << mod.getModuleCode() << "\n";
    }
}

void Timetable::saveToFile(const std::string &filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    for (const auto &mod : modules) {
        file << mod.getModuleName() << "," << mod.getModuleCode() << "\n";
    }

    file.close();
    std::cout << "Timetable saved successfully.\n";
}

void Timetable::exportToCSV(const std::string &filename) const {
    saveToFile(filename);
    std::cout << "Timetable exported to CSV.\n";
}

void Timetable::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    modules.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, code;

        if (std::getline(ss, name, ',') && std::getline(ss, code, ',')) {
            modules.emplace_back(name, code);
        }
    }

    file.close();
    std::cout << "Timetable loaded successfully.\n";
}

void Timetable::removeModule(const std::string &moduleCode) {
    auto it = std::remove_if(modules.begin(), modules.end(),
                             [&moduleCode](const Module &mod) { return mod.getModuleCode() == moduleCode; });

    if (it != modules.end()) {
        modules.erase(it, modules.end());
        std::cout << "Module with code " << moduleCode << " removed.\n";
    } else {
        std::cout << "Module with code " << moduleCode << " not found.\n";
    }
}