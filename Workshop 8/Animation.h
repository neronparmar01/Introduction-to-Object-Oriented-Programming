/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Animation.h
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

#ifndef SDDS_ANIMATION_H__
#define SDDS_ANIMATION_H__

#include "Video.h"
#include <iostream>

namespace sdds {
    class Animation : public Video {
    private:
        int m_dimension{};
    public:
        Animation();
        Animation(const Animation&) = delete;
        Animation& operator=(const Animation&) = delete;
        Animation(int length, int dimension);
        void load(std::istream& is) override;
        std::ostream& play(std::ostream& os) const override;
    };
}

#endif // !SDDS_ANIMATION_H__