
// Final Project 
// Student POS App 
// Version 1.0
// Date	2023-03-19
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
// 
// File name : PosIO.h
//
// Name : Neron Parmar   StudentID : 171690217
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>

namespace sdds {


	class PosIO
	{
	public:
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::ofstream& save(std::ofstream& ofst) const = 0;

		virtual std::istream& read(std::istream& istr) = 0;
		virtual std::ifstream& load(std::ifstream& ifst) = 0;
		virtual ~PosIO() {};
	};


	std::ostream& operator<<(std::ostream& ostr, const PosIO& P);
	std::ofstream& operator<<(std::ofstream& ofst, const PosIO& P);



	std::istream& operator>>(std::istream& istr, PosIO& P);
	std::ifstream& operator>>(std::ifstream& ifst, PosIO& P);
}
#endif 


