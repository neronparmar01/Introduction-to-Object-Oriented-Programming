/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
// tester program
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
// and the comments stated in the main function
//
// File : Car.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/7/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Car.h"
using namespace std;
namespace sdds {
    Car::Car(const char* plate, const char* makeModel) {
        set(plate, makeModel);
    }
    void Car::set(const char* plate, const char* makeModel) {
        strncpy(m_plate, plate, 8);
        m_plate[8] = 0;
        strncpy(m_makeModel, makeModel, 40);
        m_makeModel[40] = 0;;
    }
    std::ostream& Car::display(std::ostream& os)const {
        return os << m_plate << " " << m_makeModel;
    }
    std::istream& Car::read(std::istream& is) {
        is >> m_plate;
        is.getline(m_makeModel, 40, '\n');
        return is;
    }
    bool Car::operator==(const char* mmSubstr)const {
        return strstr(m_makeModel, mmSubstr) != nullptr;
    }
}