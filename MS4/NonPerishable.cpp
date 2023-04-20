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
// File : NonPerishable.cpp
/////////////////////////////////////////////////////////////////

#include <iomanip>
#include "NonPerishable.h"

namespace sdds {

    std::ostream& NonPerishable::write(std::ostream& os) const {
        Item::write(os);
        if (*this) {
            if (m_displayType == POS_LIST) {
                os << "     N / A   |";
            }
            else {
                os << "=============^" << std::endl;
            }
        }

        return os;
    }

}