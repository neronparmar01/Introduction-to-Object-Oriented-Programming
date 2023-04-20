// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : NonPerishable.cpp
// Name : Neron Parmar    Student ID : 171690217    Date: 4/16/23
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