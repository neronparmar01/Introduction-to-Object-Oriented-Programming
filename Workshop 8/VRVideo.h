/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	VRVideo.h
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

#ifndef SDDS_VRVIDEO_H__
#define SDDS_VRVIDEO_H__

#include "Video.h"
#include <iostream>

namespace sdds {
    class VRVideo : public Video {
    private:
        char* m_equipment{};
    public:
        VRVideo();

        VRVideo(const VRVideo&) = delete;

        VRVideo& operator=(const VRVideo&) = delete;

        VRVideo(int length, const char* equipment);
        ~VRVideo();
        void load(std::istream& is) override;
        std::ostream& play(std::ostream& os) const override;
    };
}

#endif // !SDDS_VRVIDEO_H__