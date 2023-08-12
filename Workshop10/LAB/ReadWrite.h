/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
// tester program
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
// and the comments stated in the main function
//
// File : ReadWrite.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/7/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
    class ReadWrite {
    public:
        virtual std::ostream& display(std::ostream& os)const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual ~ReadWrite() {
        }
    };
    std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
    std::istream& operator>>(std::istream& is, ReadWrite& c);
}
#endif // !SDDS_READWRITE_H_
