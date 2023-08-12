/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// professor's tester program
//
// File: MotorVehicle.h
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar        Date     7/13/23       Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "cstring.h"

namespace sdds {
    class MotorVehicle {
        char m_licensePlate[9];
        char m_address[64];
        int m_year;

    public:
        MotorVehicle();
        MotorVehicle(const char* plate, const int year);
        ~MotorVehicle();
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& vehicle);
    std::istream& operator>>(std::istream& istr, MotorVehicle& vehicle);
}

#endif // SDDS_MOTORVEHICLE_H
