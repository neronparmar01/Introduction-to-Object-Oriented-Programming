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

#include "cstring.h"

namespace sdds {
    void strCpy(char* des, const char* src) {
        int i = 0;
        while (src[i] != '\0') {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }


    int strCmp(const char* s1, const char* s2) {
        // returns 0 i thare the same
        // return > 0 if s1 > s2
        // return < 0 if s1 < s2

        int i = 0;
        while (s1[i] == s2[i] && s1[i] != '\0')
            i++;
        return s1[i] - s2[i];
    }


    int strLen(const char* s) {
        // returns the address of first occurance of "str2" in "str1"
        // returns nullptr if no match is found
        int len = 0;
        while (s[len] != '\0')
            len++;
        return len;
    }
}   