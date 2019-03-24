//
// Created by vitowu on 2/12/19.
//

/** @file Assignment1/src/p2.cpp
 *  This is a source file, connect to library headers @headername{p2.h}.
 */

#include "p2.h"

namespace Assignment1 {

/**
 * @function to reverse DNA strand input
 *           i.e. replace each A with T, C with G and vice versa
 * @example: reverseDNAStrand("AGCCTGC") -> (std::string)"TCGGACG"
 *
 * @param s - original DNA strand
 * @return reversed DNA strand
 */
std::string reverseDNAStrand(std::string* s) {
    std::string ret;

    // iterate each character in input string and reverse each char according to specific rules
    for (char c : *s) {
        switch (c) {
            case 'A':
                ret += "T";
                break;
            case 'T':
                ret += "A";
                break;
            case 'G':
                ret += "C";
                break;
            case 'C':
                ret += "G";
                break;
            default: {
                // detect character which is not in "ATGC"
                std::cerr << "Fail to parse: " << c << std::endl;
                std::cerr << "Aborted." << std::endl;
                exit(1);
            }
        }
    }

    return ret;
}

/**
 * @function to find valid DNA match index with input 2 DNA strands and start index
 * @example: findDNAMatch("AC", "ATGGCGTGCCG", 3) -> (int)6
 *          findDNAMatch("C", "ATTAC", 0) -> (int)-1
 *
 * @param s1 - small strand to be attached
 * @param s2 - long DNA strand
 * @param start - leftmost search position
 * @return position index if exist, otherwise return -1
 */
int findDNAMatch(std::string s1, std::string s2, int start) {
    // reverse the longer strand
    std::string reverseS2 = reverseDNAStrand(&s2);

    // split substrings starting from each char of the reversed longer strand with the equal length as the short strand
    for (int i = start; ulong(i) <= reverseS2.length() - s1.length(); i++) {

        // boolean to store if ith substring is as same as the shorter strand
        bool isSameString = true;

        // comparision between each character
        for (int j = 0; ulong(j) < s1.length(); j++) {

            if (s1[ulong(j)] != reverseS2[ulong(i+j)]){
                isSameString = false;
                break;
            }
        }

        if (isSameString)
            return i;
    }

    // no valid matched
    return -1;

}

/**
 * @function entry function of part 2
 */
void p2() {
    // print greetings
    std::cout << std::endl << "[INFO] CSC-3002 Assignment 1 Test Part 2" << std::endl;

    std::string s1, s2;

    // read user input of the longer DNA strand and assign to s2
    std::cout << "Please input the longer DNA strand: ";
    std::cin >> s2;

    // check if s2 is a valid DNA strand
    while (s2.find_first_not_of("AGCT") != std::string::npos) { // s2 include characters which are not AGCT

        // print error message
        std::cerr << "Invalid DNA strand." << std::endl;

        // std::cerr and std::cout have different terminal directions, which may cause unexpected problems if not sleep
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // read user input again
        std::cout << "Please input the longer DNA stand: ";
        std::cin >> s2;
    }

    // read user input of the shorter DNA strand and assign to s1
    std::cout << "Please input the shorter one: ";
    std::cin >> s1;

    // check if s1 is a valid DNA strand
    while (s1.find_first_not_of("AGCT") != std::string::npos) { // s1 include characters which are not AGCT

        // print error message
        std::cerr << "Invalid DNA strand." << std::endl;

        // std::cerr and std::cout have different terminal directions, which may cause unexpected problems if not sleep
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // read user input again
        std::cout << "Please input the shorter DNA stand: ";
        std::cin >> s1;
    }

    // vector to restore all valid matched positions
    std::vector<int> validPositions;

    // temp variable to restore each search result
    int idx;

    // search from the first character of the longer DNA strand
    int start = 0;

    // no more matches if return -1
    while ((idx = findDNAMatch(s1, s2, start)) != -1) {

        // find valid matched index and append to the vector
        validPositions.push_back(idx);

        // continue to find valid matched index start from consecutive character
        start = idx+1;
    }

    if (validPositions.empty()) {
        // no valid matched index
        std::cout << "There is no valid position for shorter DNA strand." << std::endl;
    } else {
        std::cout << "The matching positions should be: ";
        for (int i : validPositions)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}

}
