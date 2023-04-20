// Final Project 
// Student POS App 
// Version 1.0
// Date	2023-03-19
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
// 
// File name : Error.h
//
// Name : Neron Parmar   StudentID : 171690217
/////////////////////////////////////////////////////////////////

#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
	class Error {
		char* errorMessage = nullptr;


	public:
		Error(const char* eMesssage = NULL);
		~Error();

		Error(const Error& E);
		Error& operator=(const Error& E);
		operator bool() const;
		Error& clear();
		std::ostream& display(std::ostream& ostr) const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Error& E);
}
#endif 


