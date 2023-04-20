/***********************************************************************
// OOP244 Workshop 9:
// File	Tools.cpp
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar      Date   3/31/23         Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Tools.h"
namespace sdds {
    int strLen(const char* str) {
        int len = -1;
        while (str[++len]);
        return len;
    }
    void strCpy(char* des, const char* src) {
        while (*src) *des++ = *src++;
        *des = *src;
    }
    void strCat(char* des, const char* src) {
        while (*des) des++;
        while (*src) *des++ = *src++;
        *des = *src;
    }
    void delAlloCopy(char*& des, const char* src) {
        if (src && src[0]) {
            delete[] des;
            des = new char[strLen(src) + 1];
            strCpy(des, src);
        }
        else {
            delete[] des;
            des = nullptr;
        }
    }

    char* dynRead(istream& istr, char delimeter) {
        char* str{};
        string toRead;
        getline(istr, toRead, delimeter);
        if (istr) {
            str = new char[strLen(toRead.c_str()) + 1];
            strCpy(str, toRead.c_str());
        }
        return str;
    }
}