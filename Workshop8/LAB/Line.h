/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: Line.h
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "LblShape.h"

namespace sdds {
	class Line : public LblShape {
		int m_length;

	public:
		Line();
		Line(const char* length, int lenght);

		void getSpecs(std::istream& is);
		// overrrides the base class
		void draw(std::ostream& os)const;
	};
}

#endif // !SDDS_LINE_H
