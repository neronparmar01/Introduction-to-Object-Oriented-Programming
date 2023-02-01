/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  Tools.cpp
// Version 1.1
// Date   Fall 2022
// Author Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                  Date          Reason
// Parmar Neron Nelson   1/31/23       reordered user's tweets report
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Tools.h"

namespace sdds {

    void strCpy(char* str1, const char* str2) {
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }

}
