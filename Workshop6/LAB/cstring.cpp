/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6
// Version 1.0
// Description
// tester program
//
// File: cstring.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date    7/15/23        Reason
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
	int strLen(const char* s) {
		// returns the address of first occurance of "str2" in "str1"
		// returns nullptr if no match is found
		int len = 0;
		while (s[len] != '\0')
			len++;
		return len;
	}
	void strCat(char* des, const char* src) {
		int len = strLen(des);
		int i = 0;
		while (src[i] != 0) {
			des[len + i] = src[i];
			i++;
		}
		des[len + i] = '\0';
	}
}