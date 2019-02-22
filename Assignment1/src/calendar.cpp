//
// Created by vitowu on 2/12/19.
//

/** @file Assignment1/src/calendar.cpp
 *  This is a source file, connect to library headers @headername{calendar.h}.
 */

#include "calendar.h"

namespace Assignment1 {

/**
 * @function to calculate days in input month and input year
 * @example: daysInMonth(NOVEMBER, 2019) -> (int)30
 *           daysInMonth(FEBRUARY, 2017) -> (int)28
 *           daysInMonth(FEBRUARY, 2004) -> (int)29
 *
 * @param month - month input
 * @param year - year input
 * @return days in the input month of the input year
 */
int daysInMonth(Month month, int year) {
    switch (month) {
        case APRIL:
        case JULY:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
            return (isLeapYear(year)) ? 29 : 28;
        default:
            return 31;
    }
}

/**
 * @function to determine whether a year is a leap year
 * @example: isLeapYear(2003) -> (bool)false
 *           isLeapYear(2004) -> (bool)true
 *
 * @param year - input year
 * @return if the input year is a leap year then return true, otherwise return false
 */
bool isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

}