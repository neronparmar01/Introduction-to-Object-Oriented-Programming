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
// File : ReadWrite.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/7/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& os, const ReadWrite& c) {
        return c.display(os);
    }

    istream& operator >> (istream& is, ReadWrite& c) {
        return c.read(is);
    }
}