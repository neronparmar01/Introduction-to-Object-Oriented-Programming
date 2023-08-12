/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Version 1.0
// Description
// tester program
//
// File: LabelMaker.cpp
//
// Revision History
// -----------------------------------------------------------
// Name     Neron Parmar     Date   6/11/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "LabelMaker.h"

using namespace std;
namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {
		labels = nullptr;
		numLabels = noOfLabels;
		labels = new Label[noOfLabels];
	}

	void LabelMaker::readLabels() {
		int i = 0;
		cout << "Enter " << numLabels << " labels:" << endl;
		while (i < numLabels) 
		{
			cout << "Enter label number " << (i + 1) << endl;
			labels[i].readLabel();
			i++;
		}
	}

	void LabelMaker::printLabels() {
		int i = 0;
		while (i < numLabels) {
			labels[i].printLabel() << endl;
			i++;
		}
	}

	LabelMaker::~LabelMaker() {
		if (labels != nullptr) {
			delete[] labels;
			labels = nullptr;
		}
	}
}