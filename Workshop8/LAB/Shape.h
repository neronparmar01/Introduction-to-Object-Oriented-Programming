/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: Shape.h
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>


namespace sdds {
	class Shape {

	public:
		virtual ~Shape() {};
		virtual void draw(std::ostream& os)const = 0;
		virtual void getSpecs(std::istream& is) = 0;
	};
	std::ostream& operator<<(std::ostream& os, const Shape& shape);
	std::istream& operator>>(std::istream& is, Shape& shape);
}

#endif // !SDDS_SHAPE_H
