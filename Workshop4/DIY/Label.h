/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Version 1.0
// Description
// tester program
//
// File: Label.h
//
// Revision History
// -----------------------------------------------------------
// Name     Neron Parmar     Date   6/11/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include <iostream>
namespace sdds {
	class Label {
	private:
		char* content;
		char* frame;

	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel() const; 
	};
}
#endif // !SDDS_LABEL_H
