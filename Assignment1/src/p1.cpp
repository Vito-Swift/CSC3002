//
// Created by vitowu on 2/12/19.
//

/** @file Assignment1/src/p1.cpp
 *  This is a source file, connect to library headers @headername{p1.h}.
 */

#include "p1.h"

namespace Assignment1{

/**
 * @function to get month name string according to the integer input
 * @example: getMonthName(1) -> (std::string)"January"
 *
 * @param month - integer number of month
 * @return month name as a string
 */
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

/**
 * @function entry function of part 1
 */
void p1() {
    // print greetings
    std::cout << "[INFO] CSC-3002 Assignment 1 Test Part 1" << std::endl;

    // integer to store the specific year
    int year;

    // read user input of specific year and assign to year
    std::cout << "Enter a year: ";
    std::cin >> year;

    // several examination of user input
    while (!std::cin) { // input is not an integer

        // flush inappropriate input
        std::cin.clear();
        std::cin.ignore(INT16_MAX, '\n');

        // print error message
        std::cerr << "Input must be an integer." << std::endl;

        // std::cerr and std::cout have different terminal directions, which may cause unexpected problems if not sleep
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // read user input again
        std::cout << "Enter a year: ";
        std::cin >> year;
    }

    while (year <= 0) { // input is non-positive

        // print error message
        std::cerr << "Input year cannot be a non-positive value." << std::endl;

        // read user input again
        std::cout << "Enter a year: ";
        std::cin >> year;
    }

    try {
        // print each month name with days of it in the specific year
        for (int i = 1; i < 13; i++) {
            std::cout << getMonthName(i) << " has " << daysInMonth(Month(i), year) << " days." << std::endl;
        }

    } catch(std::runtime_error& e) {
        // caught a runtime error
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

}