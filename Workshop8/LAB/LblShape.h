/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: LblShape.h
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__

#include <iostream>
#include "Shape.h"
#include "Utils.h"

namespace sdds
{
	class LblShape : public Shape{
		char* m_label{ nullptr };
	protected:
		char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& copy) = delete;
		LblShape& operator=(const LblShape& src) = delete;

		// overriding 
		void getSpecs(std::istream& is);
	};
}
#endif 