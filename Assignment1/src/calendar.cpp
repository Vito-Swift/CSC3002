//
// Created by vitowu on 2/12/19.
//

#include "calendar.h"

namespace Assignment1 {

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

bool isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

}