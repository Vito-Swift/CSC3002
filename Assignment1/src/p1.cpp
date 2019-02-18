//
// Created by vitowu on 2/12/19.
//

#include "p1.h"

namespace Assignment1{

std::string getMonthName(int month) {
    std::string monthNames[] = {"",
                                "January",
                                "February",
                                "March",
                                "April",
                                "May",
                                "Jane",
                                "July",
                                "August",
                                "September",
                                "October",
                                "November",
                                "December"
    };
    return monthNames[month];
}

void p1() {
    std::cout << "CSC-3002 Assignment 1 [Test Part 1]" << std::endl;

    int year;

    std::cout << "Enter a year: ";
    std::cin >> year;

    if (year <= 0) {
        std::cerr << "Input year cannot be a non-positive value. Aborted." << std::endl;
        exit(1);
    }

    try {
        for (int i = 1; i < 13; i++) {
            std::cout << getMonthName(i) << " has " << daysInMonth(Month(i), year) << " days." << std::endl;
        }

    } catch(std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

}