// Program name: Date.h
// Author: Gregory Mahoy
// Date last updated: 11/10/2025
// Purpose: Header file for the Date class that defines a date object with
// month, day, and year. Includes declarations for validation, formatting,
// and exception handling.

#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>

class Date {
private:
    int month, day, year;

    int daysInMonth(int m) const;
    std::string getMonthName(int m) const;

public:
    // Constructor
    Date(int m, int d, int y);

    // Mutators
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    // Accessor
    std::string toString() const;
};

#endif
