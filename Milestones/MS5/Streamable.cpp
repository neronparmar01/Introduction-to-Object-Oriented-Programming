// Final Project 
// PublicationSelector Usage demonstration
// File:	Streamable.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar     Date     8/7/23            Reason
//                    
/////////////////////////////////////////////////////////////////

#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds {

    ostream& operator<<(ostream& os, const Streamable& S) {
        if (S.operator bool()) S.write(os);
        return os;
    }
    istream& operator>>(istream& is, Streamable& S) {
        if (S.operator bool()) S.read(is);
        return is;
    }
}