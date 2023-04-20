/***********************************************************************
// OOP244 Workshop 10:
// File	Displayable.cpp
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    4/8/23        Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Displayable.h"
namespace sict {
    std::ostream& operator<<(std::ostream& os, const Displayable& D) {
        return D.display(os);
    }
}