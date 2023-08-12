/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: Line.cpp
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Line.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	Line::Line() : LblShape() {
		this->m_length = 0;
	}

	Line::Line(const char* length, int lenght) : LblShape(length) {
		this->m_length = lenght;
	}

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> this->m_length;
		is.ignore(1000, '\n');
	}

	void Line::draw(std::ostream& os) const {
		if (this->m_length > 0 && LblShape::label() != nullptr) {
			os << LblShape::label() << endl;
			for (int i = 0; i < this->m_length; i++) {
				os << "=";
			}
		}
	}
}
