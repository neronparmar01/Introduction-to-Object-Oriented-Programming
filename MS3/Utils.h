// Final Project 
// Student POS App 
// Version 1.0
// Date	2023-03-19
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
// 
// File name : Utils.h
//
// Name : Neron Parmar   StudentID : 171690217
/////////////////////////////////////////////////////////////////

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
	class Utils
	{
	public:
		size_t strlen(const char* str)const;
		char* strcpy(char* des, const char* src)const;
		char* strcpy(char* des, const char* src, int len)const;
		char* strcat(char* des, const char* src)const;
		int strcmp(const char* s1, const char* s2)const;
		char* aloCopy(size_t length, const char* src)const;
	};
	extern Utils U;
}
#endif 



