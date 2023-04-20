/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Media.h
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

#ifndef SDDS_MEDIA_H__
#define SDDS_MEDIA_H__

#include <bits/stdc++.h>
#include <iostream>
namespace sdds {
    class Media {
    public:
        virtual std::ostream& play(std::ostream& os) const = 0;

        virtual void load(std::istream& is) = 0;

        virtual ~Media() = default;
    };
    std::ostream& operator<<(std::ostream& os, const Media& media);

    std::istream& operator>>(std::istream& is, Media& media);
}

#endif // !SDDS_MEDIA_H__