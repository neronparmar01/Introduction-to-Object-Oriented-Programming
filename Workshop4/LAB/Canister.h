/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Version 1.0
// Description
// tester program
//
// File : Canister.h
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar     Date   6/9/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CANISTER_H
#define SDDS_CANISTER_H

#include <iostream>

namespace sdds {

    class Canister {
        char* m_contentName;
        double m_diameter;
        double m_height;
        double m_contentVolume;
        bool m_usable;

        void setToDefault();
        bool isEmpty() const;
        bool hasSameContent(const Canister& C) const;
        void setName(const char* Cstr);

    public:
        Canister();
        Canister(const char* contentName);
        Canister(double height, double diameter, const char* contentName = nullptr);
        ~Canister();

        Canister& setContent(const char* contentName);
        Canister& pour(double quantity);
        Canister& pour(Canister& C);
        std::ostream& display() const;

        double capacity() const;
        double volume() const;
        void clear();
    };

}

#endif // !SDDS_CANISTER_H
