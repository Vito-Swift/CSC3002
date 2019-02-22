//
// Created by vitowu on 2/12/19.
//

/** @file Assignment1/include/p1.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{p1.h}
 */

#ifndef CSC3002_P1_H
#define CSC3002_P1_H

#include <iostream>
#include <thread>
#include "calendar.h"

namespace Assignment1 {

/**
 * @function to get month name string according to the integer input
 * @example: getMonthName(1) -> (std::string)"January"
 *
 * @param month - integer number of month
 * @return month name as a string
 */
std::string getMonthName(int month);


/**
 * @function entry function of part 1
 */
void p1();

}

#endif //CSC3002_P1_H
