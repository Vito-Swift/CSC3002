//
// Created by vitowu on 2/12/19.
//

/** @file Assignment1/include/p2.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{p2.h}
 */

#ifndef CSC3002_P2_H
#define CSC3002_P2_H

#include <vector>
#include <iostream>

namespace Assignment1 {

std::string reverseDNAStrand(std::string* s);

int findDNAMatch(std::string s1, std::string s2, int start = 0);

void p2();

}

#endif //CSC3002_P2_H
