/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
// professor's tester program
//
//	File : cstring.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   6/4/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds {

	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(char* s1, const char* s2);
	int strnCmp(char* s1, const char* s2, int len);
	int strLen(const char* s);
	const char* strStr(const char* str1, const char* str2);
	void strCat(char* des, const char* src);
}
#endif // !SDDS_CSTRING_H
