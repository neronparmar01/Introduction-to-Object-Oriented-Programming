/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 2
// Version 1.0
// Description
// professor's tester program
//
// File: Mark.cpp
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar    Date   6/18/23     Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Mark.h"

using namespace std;
namespace sdds {
	Mark::Mark() {
		m_marks = 0;
		GPA = 0.0;
		m_letter = 'F';
		m_valid = true;
	}

	Mark::Mark(int grade) : Mark(){
		setMarks(grade);
	}

	bool Mark::operator~() {
		/*if (m_marks >= 0 && m_marks <= 100)
		return m_marks;*/
		return (m_marks <= 100 && m_marks >= 0);
	}

	void Mark::setMarks(int setMarks) {
		m_marks = setMarks;
		validate();
	}

	void Mark::validate() {
		m_valid = ~*this ? true : false;
		m_marks = int(*this);
	}

	Mark::operator const int() {
		return (~(*this)) ? m_marks : 0;
	}

	Mark::operator double() {
		if (m_valid && ~*this && m_marks >= 80 && m_marks <= 100) {
			GPA = 4.0;
		}
		else if (m_valid && ~*this && m_marks >= 70 && m_marks <= 80) {
			GPA = 3.0;
		}
		else if (m_valid && ~*this && m_marks >= 60 && m_marks <= 70) {
			GPA = 2.0;
		}
		else if (m_valid && ~*this && m_marks >= 50 && m_marks <= 60) {
			GPA = 1.0;
		}
		else {
			GPA = 0.0;
		}

		return GPA;
	}

	Mark::operator char() {
		if (!m_valid) {
			m_letter = 'X';
		}else if (m_marks >= 80 && m_marks <= 100) {
			m_letter = 'A';
		}
		else if (m_marks >= 70 && m_marks <= 80) {
			m_letter = 'B';
		}
		else if (m_marks >= 60 && m_marks <= 70) {
			m_letter = 'C';
		}
		else if (m_marks >= 50 && m_marks <= 60) {
			m_letter = 'D';
		}
		else {
			m_letter = 'F';
		}

		return m_letter;
	}

	Mark& Mark::operator+=(int extraGrade) {
		if (~*this && extraGrade >= 0 && m_valid) {
			m_marks += extraGrade;
			validate();
		}
		return *this;
	}

	Mark& Mark::operator=(int fixInvalid) {
		setMarks(fixInvalid);

		return *this;
	}


	int operator+=(int& val, Mark& rhs)
	{
		return ~rhs ? val += int(rhs) : val;
	}

}