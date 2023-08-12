/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : salReport.cpp 
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar       Date    5/25/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Employee.h"
using namespace sdds;
int main() {
    if (load()) {
        display();
    }
    deallocateMemory();
    return 0;
}