/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Version 1.0
// Description
// tester program
//
// File : cstring.h
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar     Date   6/9/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds {
    void strCpy(char* des, const char* src);
    int strCmp(const char* s1, const char* s2);
    int strLen(const char* s);
}
#endif // !SDDS_CSTRING_H