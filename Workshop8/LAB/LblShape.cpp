/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8
// Version 1.0
// Description
// tester program
//
// File: LblShape.cpp
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar      Date    7/24/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

using namespace std;
namespace sdds {

    char* LblShape::label() const
    {
        return this->m_label;
    }

    LblShape::LblShape()
    {
        if (this->m_label != nullptr) {
            this->m_label = nullptr;
        }

    }

    LblShape::LblShape(const char* label)
    {
        if (label != nullptr) {
            this->m_label = new char[(strlen(label) + 1)];
            strcpy(this->m_label, label);
        }
    }

    LblShape::~LblShape()
    {
        delete[] this->m_label;
        this->m_label = nullptr;
    }

    void LblShape::getSpecs(std::istream& is)
    {
        char thisLabel[50];
        is.get(thisLabel, 50, ',');
        is.ignore(1000, ',');

        delete[] this->m_label;

        this->m_label = new char[strlen(thisLabel) + 1];
        strcpy(this->m_label, thisLabel);
    }
}