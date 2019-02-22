//
// Created by vitowu on 2/12/19.
//

/** @file Assignment1/include/calender.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{calendar.h}
 */

//
// Assignment1 Calendar Library
//

#ifndef CSC3002_CALENDAR_H
#define CSC3002_CALENDAR_H

namespace Assignment1 {

/** @enum_type to denote different months
 *  elements in Month have consecutive values from 1 to 12 according the the order of months
 */
enum Month {
  JANUARY = 1,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JANE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER,
};


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
int daysInMonth(Month month, int year);


/**
 * @function to determine whether a year is a leap year
 * @example: isLeapYear(2003) -> (bool)false
 *           isLeapYear(2004) -> (bool)true
 *
 * @param year - input year
 * @return if the input year is a leap year then return true, otherwise return false
 */
bool isLeapYear(int year);

}

#endif //CSC3002_CALENDAR_H
