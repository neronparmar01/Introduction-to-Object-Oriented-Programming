/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Version 1.0
// Description
// tester program
//
// File: LabelMaker.h
//
// Revision History
// -----------------------------------------------------------
// Name     Neron Parmar     Date   6/11/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

#include <iostream>
namespace sdds {
	class LabelMaker {
	private:
		int numLabels;
		Label* labels;

	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif // !SDDS_LABELMAKER_H
