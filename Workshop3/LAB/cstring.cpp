/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1
// Version 1.0
// Description
// tester program
//
// File : cstring.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar    Date    6/1/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "cstring.h"

namespace sdds {
	void strnCpy(char* des, const char* src, int len) {
		int i = 0;
		while (src[i] != '\0' && i < len) {
			des[i] = src[i];
			i++;
		}
		if (i < len) {
			des[i] = '\0';
		}
	}
}