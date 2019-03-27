/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */

#include <iostream>
#include <fstream>
#include "filelib.h"     // promptUserForFile
using namespace std;

/* Function prototypes */

void removeComments(istream & is, ostream & os);

/* Main program */

int main() {
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    removeComments(infile, cout);
    infile.close();
    return 0;
}

/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

void removeComments(istream & is, ostream & os) {

    Vector<std::string> fileLines;
    readEntireFile(is, fileLines);

    string uncommentedFile;
    bool inMultiComm;
    bool inSingleComm;

    inMultiComm = false;
    inSingleComm = false;


    for (const string& line: fileLines) {

        unsigned long n = line.length();

        if (n == 1)
            uncommentedFile += line;

        else {
            for (unsigned int i = 0; i < n; i++) {

                if (inMultiComm && line[i] == '*' && line[i+1] == '/') {
                    inMultiComm = false;
                    i++;
                }

                else if (inMultiComm || inSingleComm)
                    continue;

                else if (line[i] == '/' && line[i+1] == '*') {
                    inMultiComm = true;
                    i++;
                }

                else if (line[i] == '/' && line[i+1] == '/') {
                    inSingleComm = true;
                    i++;
                }

                else
                    uncommentedFile += line[i];
             }
        }

        if (!inMultiComm) {
            if (inSingleComm)
                inSingleComm = false;
            uncommentedFile += '\n';
        }

    }

    uncommentedFile += '\0';
    os << uncommentedFile;
    os.clear();
}
