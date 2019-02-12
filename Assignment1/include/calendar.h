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

int daysInMonth(Month month, int year);

bool isLeapYear(int year);

}

#endif //CSC3002_CALENDAR_H
