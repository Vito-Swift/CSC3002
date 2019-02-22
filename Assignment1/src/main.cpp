//
// Created by vitowu on 2/12/19.
//

/** @file Assignment1/src/main.cpp
 *  This is a test file to examine the function of library in @headername{p1.h} @headername{p2.h}
 *  To launch the test file libraries included in the header must be linked to the executable.
 *  Built together with associate libraries.
 */

#include "p1.h"
#include "p2.h"
#include "calendar.h"

/**
 * @function entry function of test file
 * @return EXIT_SUCCESS if no runtime_error during running
 */
int main() {

    // call the entry function of part 1
    Assignment1::p1();

    // call the entry function of part 2
    Assignment1::p2();
    return EXIT_SUCCESS;
}
