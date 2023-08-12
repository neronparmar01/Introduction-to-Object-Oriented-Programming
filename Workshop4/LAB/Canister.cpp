/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Version 1.0
// Description
// tester program
//
// File : Canister.cpp
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar     Date   6/9/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Canister.h"
#include "cstring.h"
using namespace std;
namespace sdds {

    const double PI = 3.14159265;

    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    bool Canister::isEmpty() const {
        return m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister& C) const {
        bool equal = false;
        if (m_contentName != nullptr && C.m_contentName != nullptr) {
           if(strCmp(m_contentName, C.m_contentName) == 1)
           {
            return equal = true;
           }
        }
            return equal;
    }

    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr && m_usable) {
            delete[] m_contentName;
            int length = std::strlen(Cstr);
            m_contentName = new char[length + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char* contentName) {
        setToDefault();
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
            m_height = height;
            m_diameter = diameter;
            setName(contentName);
        }
        else {
            m_usable = false;
        }
    }

    Canister::~Canister() {
        delete[] m_contentName;
        m_contentName = nullptr;
    }

    void Canister::clear() {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    double Canister::capacity() const {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    double Canister::volume() const {
        return m_contentVolume;
    }

    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr || !m_usable) {
            m_usable = false;
        }
        else {
            setName(contentName);
        }
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity > 0 && quantity + volume() <= capacity()) {
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C)
    {
        if (m_contentName == nullptr || volume() == 0)      // first check if nullptr or not 
        {
            setContent(C.m_contentName);
        }
        if (strcmp(m_contentName, C.m_contentName) == 0)
        {
            if (C.volume() > capacity() - volume())                 // reduce the content volume
            {
                C.m_contentVolume -= (capacity() - volume());
                m_contentVolume = capacity();
            }
            else
            {
                pour(C.volume());
                C.m_contentVolume = 0.0;
            }
        }
        else
        {
            if (volume() + C.volume() <= capacity())
            {
                C.m_contentVolume = 0;
            }
            else
            {
                C.m_contentVolume -= (capacity() - volume());
                m_usable = false;
            }
             isEmpty();//m_contentVolume < 0.00001;                  // setEmpty() call 
        }
        return *this;
    }

    std::ostream& Canister::display() const {
        cout.width(7);
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        if (m_usable) {
            if (m_contentName != nullptr) {
                cout << " of ";
                cout.width(7);
                cout << m_contentVolume << "cc   " << m_contentName;
            }
        }
        return cout;
    }
}
