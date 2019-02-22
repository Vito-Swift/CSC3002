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
#include <thread>
#include <iostream>

namespace Assignment1 {

/**
 * @function to reverse DNA strand input
 *           i.e. replace each A with T, C with G and vice versa
 * @example: reverseDNAStrand("AGCCTGC") -> (std::string)"TCGGACG"
 *
 * @param s: original DNA strand
 * @return reversed DNA strand
 */
std::string reverseDNAStrand(std::string* s);


/**
 * @function to find valid DNA match index with input 2 DNA strands and start index
 * @example: findDNAMatch("AC", "ATGGCGTGCCG", 3) -> (int)6
 *          findDNAMatch("C", "ATTAC", 0) -> (int)-1
 *
 * @param s1 small strand to be attached
 * @param s2 long DNA strand
 * @param start leftmost search position
 * @return position index if exist, otherwise return -1
 */
int findDNAMatch(std::string s1, std::string s2, int start = 0);


/**
 * @function entry function of part 2
 */
void p2();

}

#endif //CSC3002_P2_H
