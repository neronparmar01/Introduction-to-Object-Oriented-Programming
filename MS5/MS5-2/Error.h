// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : Error.h
// Name : Neron Parmar    Student ID : 171690217    Date: 4/16/23
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
#endif //!SDDS_ERROR_H_