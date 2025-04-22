#include <iostream>
#include <filesystem>
#include "ntutimetable/headers/Timetable.h"

void testTimetable() {
    Timetable testTimetable;

    try {
        // Add test modules
        testTimetable.addModule("Mathematics", "MATH101");
        testTimetable.addModule("Physics", "PHYS102");

        // Display the timetable
        testTimetable.displayTimetable();

        // Ensure the 'data' directory exists before saving files
        if (!std::filesystem::exists("data")) {
            std::filesystem::create_directory("data");
        }

        // Save to file and export to CSV
        testTimetable.saveToFile("data/test_timetable.txt");
        testTimetable.exportToCSV("data/test_timetable.csv");

        std::cout << "All tests passed successfully.\n";
    } catch (const std::exception &e) {
        std::cerr << "Test failed: " << e.what() << "\n";
    }
}

int main() {
    testTimetable();
    return 0;
}