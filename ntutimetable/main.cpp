#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>  // For string stream operations (to handle CSV correctly)
#include "headers/admin.h"
#include "headers/student.h"
#include "headers/timetable.h"

// Function prototypes
void adminMenu(Admin &admin, Timetable &timetable);
void studentMenu(Student &student, Timetable &timetable);
bool authenticateUser(const std::string &username, const std::string &password);

int main() {
    // Sample Users
    Admin admin("admin", "admin123");
    Student student("alice", "password");
    Timetable timetable;

    // Load timetable from file
    try {
        timetable.loadFromFile("data/timetable.txt");
    } catch (const std::exception &e) {
        std::cerr << "Error loading timetable: " << e.what() << "\n";
    }

    int choice;
    std::string username, password;

    while (true) {
        std::cout << "\n===== NTU Timetabling System =====\n";
        std::cout << "1. Admin Login\n2. Student Login\n3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Admin Username: ";
                std::cin.ignore();  // To clear any leftover input from previous `std::cin`
                std::getline(std::cin, username);  // Use getline for more flexibility
                std::cout << "Enter Password: ";
                std::getline(std::cin, password);  // Use getline for more flexibility

                if (username == admin.getUsername() && authenticateUser(username, password)) {
                    adminMenu(admin, timetable);
                } else {
                    std::cout << "Invalid login credentials.\n";
                }
                break;

            case 2:
                std::cout << "Enter Student Username: ";
                std::cin.ignore();  // To clear any leftover input from previous `std::cin`
                std::getline(std::cin, username);  // Use getline for more flexibility
                std::cout << "Enter Password: ";
                std::getline(std::cin, password);  // Use getline for more flexibility

                if (username == student.getUsername() && authenticateUser(username, password)) {
                    studentMenu(student, timetable);
                } else {
                    std::cout << "Invalid login credentials.\n";
                }
                break;

            case 3:
                std::cout << "Saving timetable before exit...\n";
                try {
                    timetable.saveToFile("data/timetable.txt");
                } catch (const std::exception &e) {
                    std::cerr << "Error saving timetable: " << e.what() << "\n";
                }
                std::cout << "Exiting NTU Timetabling System...\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

// Admin menu
void adminMenu(Admin &admin, Timetable &timetable) {
    int option;
    while (true) {
        admin.displayMenu();
        std::cout << "Select an option: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                std::string moduleName, moduleCode;
                std::cout << "Enter Module Name: ";
                std::cin >> moduleName;
                std::cout << "Enter Module Code: ";
                std::cin >> moduleCode;

                try {
                    timetable.addModule(moduleName, moduleCode);
                } catch (const std::exception &e) {
                    std::cerr << "Error adding module: " << e.what() << "\n";
                }
                break;
            }
            case 2: {
                std::string moduleCode;
                std::cout << "Enter Module Code to Remove: ";
                std::cin >> moduleCode;

                try {
                    timetable.removeModule(moduleCode);
                } catch (const std::exception &e) {
                    std::cerr << "Error removing module: " << e.what() << "\n";
                }
                break;
            }
            case 3:
                try {
                    timetable.saveToFile("data/timetable.txt");
                    std::cout << "Timetable saved successfully.\n";
                } catch (const std::exception &e) {
                    std::cerr << "Error saving timetable: " << e.what() << "\n";
                }
                break;
            case 4:
                timetable.displayTimetable();
                break;
            case 5:
                try {
                    timetable.exportToCSV("data/timetable.csv");
                    std::cout << "Timetable exported to CSV successfully.\n";
                } catch (const std::exception &e) {
                    std::cerr << "Error exporting to CSV: " << e.what() << "\n";
                }
                break;
            case 6:
                std::cout << "Logging out...\n";
                return;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}

// Student menu
void studentMenu(Student &student, Timetable &timetable) {
    int option;
    while (true) {
        student.displayMenu();
        std::cout << "Select an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                timetable.displayTimetable();
                break;
            case 2:
                std::cout << "Logging out...\n";
                return;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}

// Authentication function (for demonstration purposes)
bool authenticateUser(const std::string &username, const std::string &password) {
    // In real implementation, password would be hashed and checked against a database
    if ((username == "admin" && password == "admin123") || 
        (username == "alice" && password == "password")) {
        return true;
    }
    return false;
}