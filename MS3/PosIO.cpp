// Final Project 
// Student POS App 
// Version 1.0
// Date	2023-03-19
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
// 
// File name : PosIO.cpp
//
// Name : Neron Parmar   StudentID : 171690217
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PosIO.h"
using namespace std;



namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const PosIO& P)
	{
		return P.write(ostr);
	}


	std::ofstream& operator<<(std::ofstream& ofst, const PosIO& P)
	{
		return P.save(ofst);
	}


	std::istream& operator>>(std::istream& istr, PosIO& P)
	{
		P.read(istr);
		return istr;
	}


	std::ifstream& operator>>(std::ifstream& ifst, PosIO& P)
	{
		return P.load(ifst);
	}
}