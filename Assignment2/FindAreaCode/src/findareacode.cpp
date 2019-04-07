/*
 * File: FindAreaCode.cpp
 * ----------------------
 * This program looks up a numeric area codes for the United States
 * and Canada.  The program works in both directions.  If the user
 * enters a number, the program prints out the state or province to
 * which that code is assigned.  If the user enters a name, it prints
 * out all the area codes assigned to that name.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "error.h"
#include "map.h"
#include "simpio.h"
#include "strlib.h"

using namespace std;

/* Function prototypes */

void readCodeFile(string filename, Map<int,string> & map);

/* Main program */

int main() {
    Map<int,string> areaCodeToState;
    readCodeFile("../src/AreaCodes.txt", areaCodeToState);

    while (true) {
        string line;
        cout << "Enter area code or state name: ";
        getline(cin, line);

        // Exit if get a blank line
        if (line == "") break;

        if (stringIsInteger(line)) {
            // Search state name by code
            int code = stringToInteger(line);

            // Print state name if code in map, otherwise exit with a prompt msg
            if (!areaCodeToState.containsKey(code)) cout << "Cannot find code: " << line << endl;
            else cout << areaCodeToState[code] << endl;

        } else {
            // Search code by state name

            // Iterative search the input state name in map
            // Print code number if state name in map, otherwise exit with a prompt msg
            bool isValidState = false;
            areaCodeToState.mapAll([&](int code, string state){
                if (state == line) {
                    cout << code << endl;
                    isValidState = true;
                }
            });
            if (!isValidState) cout << "Cannot find state: " << line << endl;
        }
    }

    return 0;
}

/*
 * Function: readCodeFile
 * Usage: readCodeFile(filename, map);
 * -----------------------------------
 * Reads a data file representing area codes and locations into the map,
 * which must be declared by the client.  Each line must consist of the
 * area code, a hyphen, and the name of the state/province.
 */

void readCodeFile(string filename, Map<int,string> & map) {
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) error("Can't read the data file");
    string line;
    while (getline(infile, line)) {
        if (line.length() < 4 || line[3] != '-') error("Illegal data line: " + line);
        int code = stringToInteger(line.substr(0, 3));
        map.put(code, line.substr(4));
    }
    infile.close();
}
