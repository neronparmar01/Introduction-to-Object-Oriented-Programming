/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 2
// Version 1.0
// Description
// professor's tester program
//
// File: Mark.h
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar    Date   6/18/23     Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_MARK_H
#define SDDS_MARK_H
#include <iostream>

namespace sdds {
	class Mark {
		int m_marks;
		double GPA;
		char m_letter;
		bool m_valid;

		// member functions 
		void setMarks(int setMarks);
		void validate();

		// public member functions
	public:
		Mark();
		Mark(int grade);
		operator const int();
		operator double();
		operator char();
		Mark& operator+=(int extraGrade);
		Mark& operator=(int fixInvalid);
		bool operator~();
	};
	int operator+=(int& val, Mark& rhs);
}

#endif // !SDDS_MARK_H
