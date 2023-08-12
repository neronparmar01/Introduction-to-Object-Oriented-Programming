/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: Utils.h
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

namespace sdds {
	int strlen(const char* str);
	void strcpy(char* des, const char* src, int len = -1);
	int strcmp(const char* s1, const char* s2);
}
#endif // !SDDS_UTILS_H_