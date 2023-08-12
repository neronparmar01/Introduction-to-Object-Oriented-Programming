/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : File.h
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar     Date   5/27/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

#include <cstdio>

namespace sdds {

    bool openFile(const char filename[]);
    int noOfRecords();
    void closeFile();
    FILE* getFptr(); 
}

#endif // !SDDS_FILE_H_
