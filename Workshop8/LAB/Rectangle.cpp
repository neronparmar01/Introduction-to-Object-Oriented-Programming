/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: Rectangle.cpp
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Rectangle.h"

using namespace std;
namespace sdds {
	Rectangle::Rectangle() :LblShape() {
		this->m_height = 0;
		this->m_width = 0;
	}

	//Rectangle::~Rectangle() {

	//}

	Rectangle::Rectangle(const char* label1, int width1, int height1) : LblShape(label1) {
		this->m_height = height1;
		this->m_width = width1;

		if (this->m_height < 3 || this->m_width < (strlen(label1) + 2)) {
			this->m_height = 0;
			this->m_width = 0;
		}
	}

	// overrides the base class functions
	void Rectangle::getSpecs(std::istream& is) {
		int width;
		int height;
		char symbol;
		bool escape = false;

		do {
			LblShape::getSpecs(is);
			is >> width >> symbol >> height;
			if (!is) {
				is.clear();
				is.ignore(30000, '\n');
			}
			else {
				is.ignore();
				this->m_width = width;
				this->m_height = height;
				escape = true;
			}
		} while (!escape);
	}

	void Rectangle::draw(std::ostream& os) const{
		if (this->m_height > 0 && this->m_width > 0) {
			os << "+";
			os.width(this->m_width - 1);      // error occuring after this
			os.fill('-');
			os << "+";
			os.fill(' ');
			os << endl;

			os << "|";
			os.setf(ios::left);
			os.width(this->m_width - 2);
			os << label();
			os.unsetf(ios::left);
			os << "|";
			os << endl;

			for (int i = 0; i < this->m_height - 3; i++){
				os << "|";
				os.width(this->m_width - 1);
				os.fill(' ');
				os << "|";
				os << endl;
			}

			os << "+";
			os.width(this->m_width - 1);
			os.fill('-');
			os << "+";
			os.fill(' ');
		}
	}

}