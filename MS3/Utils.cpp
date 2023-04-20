// Final Project 
// Student POS App 
// Version 1.0
// Date	2023-03-19
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
// 
// File name : Utils.cpp
//
// Name : Neron Parmar   StudentID : 171690217
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds {
    Utils U;
    size_t Utils::strlen(const char* str)const {
        size_t len{};
        for (len = 0; str[len]; len++);
        return len;
    }
    char* Utils::strcpy(char* des, const char* src)const {
        size_t i{};
        for (i = 0; src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = char(0);
        return des;
    }
    char* Utils::strcpy(char* des, const char* src, int len)const {
        int i;
        for (i = 0; i < len && src[i]; i++) des[i] = src[i];
        des[i] = 0;
        return des;
    }
    char* Utils::strcat(char* des, const char* src)const {
        size_t len = strlen(des);
        int i = 0;
        while (src[i]) {
            des[i + len] = src[i];
            i++;
        }
        des[i + len] = char(0);
        return des;
    }
    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    char* Utils::aloCopy(size_t length, const char* src)const {
        char* ret{};
        length = 0u;
        if (src) {
            length = U.strlen(src);
            ret = new char[length + 1];
            U.strcpy(ret, src);
        }
        return ret;
    }
}