/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : Population.h
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar     Date   5/27/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_POPULATION_H
#define SDDS_POPULATION_H


namespace sdds {
    struct PostalCode {
        char code[4];
        int population;
    };

    bool load(const char* filename);
    void display();
    void deallocateMemory();
}

#endif // !SDDS_POPULATION_H
