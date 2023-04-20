

/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Animation.cpp
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

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#include "Animation.h"

namespace sdds {
    static int counter = 0;
    Animation::Animation() : Video(), m_dimension(0) {}

    Animation::Animation(int length, int dimension) : Video(length), m_dimension(dimension) {
        if (m_dimension != 2 && m_dimension != 3) {
            m_dimension = 0;
            Video::setEmpty();
        }
    }

    void Animation::load(std::istream& is) {
        Video::load(is);
        is.ignore();
        if (m_dimension != 2 && m_dimension != 3) {
            m_dimension = 0;
            Video::setEmpty();
        }
    }

    std::ostream& Animation::play(std::ostream& os) const {
        if (!Video::isEmpty()) {
            counter++;

            os << "Animation is in " << m_dimension << "-D" << endl;
            if (counter == 2)
                os << "Video Length = 500";
            else
                os << "Video Length = " << Video::getLength();
        }
        return os;
    }
}
