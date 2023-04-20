// Final Project Milestone 2
// Student Logical operator Tester program
// Version 1.0
// Date	2023-02-27
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
// Name : Neron Parmar               Student ID : 171690217
// File : Error.h
/////////////////////////////////////////////////////////////////

#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>
namespace sdds
{
    class Error
    {
        char* m_message;
    public:
        Error();
        Error(const char* errorMessage);
        Error(const Error& em);
        Error& operator=(const Error& em);
        virtual ~Error();
        void clear();
        bool isClear() const;


        void message(const char* value);


        const char* message() const;
        Error& operator=(const char* errorMessage);
        operator bool() const;
        std::ostream& write(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Error& E);
}

#endif