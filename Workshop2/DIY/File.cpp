/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : File.cpp
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar     Date   5/27/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr = nullptr; // Define fptr as an external variable

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != nullptr;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) {
            fclose(fptr);
            fptr = nullptr;
        }
    }

    FILE* getFptr() {
        return fptr;
    }
}
