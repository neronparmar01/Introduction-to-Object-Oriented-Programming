// Final Project
// Milestone 4
// Perishable and NonPerishable Tester
// Version 1.0
// Date	2023-03-29
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of Milestone 4
// for submission.
//
// 
// Name : Neron Parmar      StudentID : 171690217
// File : Error.h
/////////////////////////////////////////////////////////////////


#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
#include <iostream>

namespace sdds {
    class Error {
    public:
        Error();
        Error(const char* error);
        Error(const Error& other);
        ~Error();
        Error& operator=(const Error& other);
        operator bool() const;
        Error& clear();
        void display(std::ostream& out) const;

    private:
        char* m_error;
    };
    std::ostream& operator<<(std::ostream& out, const Error& err);
}
#endif 