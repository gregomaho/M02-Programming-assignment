// Program name: main.cpp
// Author: Gregory Mahoy
// Date last updated: 11/10/2025
// Purpose: Main program demonstrating the Date class. Prompts the user
// for input to create and modify a date while handling exceptions for
// invalid values using try-catch blocks.

#include <iostream>
#include "Date.h"

using namespace std;

int main() {
    int month, day, year;
    Date* datePtr = nullptr;

    cout << "=== Date Creation Program ===\n";

    // Create Date Object
    while (true) {
        try {
            cout << "\nEnter month (1-12): ";
            cin >> month;
            cout << "Enter day: ";
            cin >> day;
            cout << "Enter year (1900-2020): ";
            cin >> year;

            datePtr = new Date(month, day, year);
            cout << "\nDate created successfully: " << datePtr->toString() << "\n";
            break;
        } catch (invalid_argument& e) {
            cout << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    // Change month
    while (true) {
        try {
            cout << "\nEnter new month (1-12): ";
            cin >> month;
            datePtr->setMonth(month);
            cout << "Updated date: " << datePtr->toString() << "\n";
            break;
        } catch (invalid_argument& e) {
            cout << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    // Change day
    while (true) {
        try {
            cout << "\nEnter new day: ";
            cin >> day;
            datePtr->setDay(day);
            cout << "Updated date: " << datePtr->toString() << "\n";
            break;
        } catch (invalid_argument& e) {
            cout << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    // Change year
    while (true) {
        try {
            cout << "\nEnter new year (1900-2020): ";
            cin >> year;
            datePtr->setYear(year);
            cout << "Updated date: " << datePtr->toString() << "\n";
            break;
        } catch (invalid_argument& e) {
            cout << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    cout << "\nFinal date: " << datePtr->toString() << "\n";
    delete datePtr;

    return 0;
}
