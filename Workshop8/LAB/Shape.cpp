/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: Shape.cpp
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Shape.h"

using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}
}