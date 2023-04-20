/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Media.cpp
// Version 1.0
// Date	   fall, 2022
// Author	Moona Kanwal
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Neron Parmar         3/25/23      Revision, correction
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Media.h"
#include <iostream>

namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Media& media) {
        return media.play(os);
    }
    std::istream& operator>>(std::istream& is, Media& media) {
        media.load(is);
        return is;
    }
}