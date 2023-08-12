/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : cstring.cpp
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar     Date   5/27/23      Reason
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

	int strCmp(const char* s1, const char* s2) {
		int i = 0;
		while (s1[i] == s2[i] && s1[i] != '\0')
			i++;
		return s1[i] - s2[i];
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int i = 0;
		while (s1[i] == s2[i] && s1[i] != '\0' && i < len)
			i++;
		if (i == len)
			return 0;
		return s1[i] - s2[i];
	}

	int strLen(const char* s) {
		int len = 0;
		while (s[len] != '\0')
			len++;
		return len;
	}

	const char* strStr(const char* str1, const char* str2) {
		int i, j;
		for (i = 0; str1[i] != '\0'; i++) {
			for (j = 0; str2[j] != '\0'; j++) {
				if (str1[i + j] != str2[j])
					break;
			}
			if (str2[j] == '\0')
				return &str1[i];
		}
		return nullptr;
	}

	void strCat(char* des, const char* src) {
		int len = strLen(des);
		int i = 0;
		while (src[i] != 0) {
			des[len + 1] = src[i];
			i++;
		}
		des[len + 1] = '\0';
	}
}