// Program name: Date.cpp
// Author: Gregory Mahoy
// Date last updated: 11/10/2025
// Purpose: Implementation file for the Date class. Handles validation of
// month, day, and year, provides formatted string output, and throws
// exceptions for invalid date values.

#include "Date.h"
#include <sstream>

int Date::daysInMonth(int m) const {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 28; // ignoring leap years per assignment instructions
        default:
            return 0;
    }
}

std::string Date::getMonthName(int m) const {
    static const std::string monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return monthNames[m - 1];
}

// Constructor
Date::Date(int m, int d, int y) {
    setMonth(m);
    setYear(y);
    setDay(d);
}

// Mutators
void Date::setMonth(int m) {
    if (m < 1 || m > 12)
        throw std::invalid_argument("Invalid Value – there are only 12 months in a year.");
    month = m;
}

void Date::setDay(int d) {
    int maxDay = daysInMonth(month);
    if (d < 1 || d > maxDay) {
        std::ostringstream ss;
        ss << "Invalid Value – there are only " << maxDay
           << " days in " << getMonthName(month) << ".";
        throw std::invalid_argument(ss.str());
    }
    day = d;
}

void Date::setYear(int y) {
    if (y < 1900 || y > 2020)
        throw std::invalid_argument("Invalid Value – year must be between 1900 and 2020.");
    year = y;
}

// Accessor
std::string Date::toString() const {
    std::ostringstream ss;
    ss << getMonthName(month) << " " << day << ", " << year;
    return ss.str();
}
