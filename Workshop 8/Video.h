/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	Video.h
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


#ifndef SDDS_VIDEO_H__
#define SDDS_VIDEO_H__

#include "Media.h"
#include <string>
#include<iostream>
namespace sdds {
    class Video : public Media {
    public:
        int m_length{};
    protected:
        int& getLength();
    public:
        Video();
        Video(const Video&) = delete;
        Video& operator=(const Video&) = delete;
        Video(int length);
        void load(std::istream& is) override;
        std::ostream& play(std::ostream& os) const override = 0;
        void setEmpty();
        bool isEmpty() const;
        int getLength() const;
    };
}

#endif // !SDDS_VIDEO_H__