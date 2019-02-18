//
// Created by vitowu on 2/12/19.
//

#include "p2.h"

namespace Assignment1 {

/**
 *
 * @param s original DNA strand
 * @return reversed DNA strand
 */
std::string reverseDNAStrand(std::string* s) {
    std::string ret;

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
                std::cerr << "Fail to parse: " << c << std::endl;
                std::cerr << "Aborted." << std::endl;
                exit(1);
            }
        }
    }

    return ret;
}

/**
 *
 * @param s1 small strand to be attached
 * @param s2 long DNA strand
 * @param start leftmost search position
 * @return position index if exist, otherwise return -1
 */
int findDNAMatch(std::string s1, std::string s2, int start) {
    std::string reverseS2 = reverseDNAStrand(&s2);

    for (int i = start; i < reverseS2.length() - s1.length(); i++) {
        bool isSubString = true;
        for (int j = 0; j < s1.length(); j++) {
            if (s1[j] != reverseS2[i+j]) {
                isSubString = false;
                break;
            }
        }

        if (isSubString)
            return i;
    }

    return -1;

}

void p2() {
    std::cout << std::endl << "CSC-3002 Assignment 1 [Test Part 2]" << std::endl;

    std::string s1, s2;

    std::cout << "Please input the longer DNA strand: ";
    std::cin >> s2;
    std::cout << "Please input the shorter one: ";
    std::cin >> s1;

    std::vector<int> validPositions;

    int idx;
    int start = 0;

    while ((idx = findDNAMatch(s1, s2, start)) != -1) {
        validPositions.push_back(idx);
        start = idx+1;
    }

    if (validPositions.empty()) {
        std::cout << "There is no valid position for shorter DNA strand." << std::endl;
    } else {
        std::cout << "The matching positions should be: ";
        for (int i : validPositions)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}

}