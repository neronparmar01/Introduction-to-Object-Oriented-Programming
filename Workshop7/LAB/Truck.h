/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// professor's tester program
//
// File: Truck.h
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar        Date     7/13/23       Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include <iostream>
#include <iomanip>
#include <string>
#include "cstring.h"
#include "MotorVehicle.h"

namespace sdds {
	class Truck : public MotorVehicle {
		double m_capacity;
		double m_load;

	public:
		Truck();
		~Truck();
		Truck(const char* plate, const int year, const double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator<<(std::ostream& ostr, const Truck& truck);
	std::istream& operator>>(std::istream& istr, Truck& truck);
}

#endif // !SDDS_TRUCK_H
