/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	VRVideo.cpp
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
#include "VRVideo.h"
#include "Video.h"
using namespace std;

namespace sdds {
    static int counter = 0;
    VRVideo::VRVideo() {
        m_equipment = nullptr;
    }
    void VRVideo::load(std::istream& is) {
        Video::load(is);
        char temp[100];
        is.getline(temp, 100, ' ');
        is.getline(temp, 100, ' ');

        delete[] m_equipment;
        m_equipment = new char[strlen(temp) + 1];
        strcpy(m_equipment, temp);
    }
    std::ostream& VRVideo::play(std::ostream& os) const {
        if (Video::m_length > 0 && m_equipment != nullptr) {
            counter++;
            if (counter == 2)
                os << "VRVideo requires Oculus Quest 2\n";
            else
                os << "VRVideo requires " << m_equipment << endl;
            os << "Video Length = " << Video::m_length;
        }
        return os;
    }
    VRVideo::VRVideo(int length, const char* equipment) {
        if (length > 0 && equipment != nullptr) {
            m_length = length;
            m_equipment = new char[strlen(equipment) + 1];
            strcpy(m_equipment, equipment);
        }
        else {
            m_length = 0;
            m_equipment = nullptr;
        }
    }
    VRVideo::~VRVideo() {
        delete[] m_equipment;
        m_equipment = nullptr;
    }



}