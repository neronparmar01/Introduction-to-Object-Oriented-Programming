/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: Rectangle.h
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
#include "Utils.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width{ 0 };
		int m_height{ 0 };
	public:
		Rectangle();
		Rectangle(const char* label1, int width1, int height1);
		//virtual ~Rectangle();

		// overrides the base class functions
		void getSpecs(std::istream& is);
		void draw(std::ostream& os)const;
	};
}
#endif // !SDDS_RECTANGLE_H
