/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// professor's tester program
//
// File: Truck.cpp
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar        Date     7/13/23       Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"

using namespace std;
namespace sdds {

	bool isCapacityFull = false;

	Truck::Truck() {
		this->m_load = 0.0;
		this->m_capacity = 0.0;
	}

	Truck::~Truck() {
		this->m_load = 0.0;
		this->m_capacity = 0.0;
	}


	Truck::Truck(const char* plate, const int year, const double capacity, const char* address) : MotorVehicle(plate, year) {
		if (plate != nullptr && year > 0 && capacity > 0 && address != nullptr) {
			this->m_capacity = capacity;
			this->m_load = 0.0;
			this->moveTo(address);
		}
		else {

			this->m_capacity = 0.0;
			this->m_load = 0.0;
		}
	}

	bool Truck::addCargo(double cargo) {
		bool load = false;
		/*double tolerance = 1100;*/
		if (isCapacityFull == true) {
			load = false;
			return load;
		}
		if (this->m_load <= this->m_capacity /*+ tolerance*/) {
			this->m_load += cargo;
			if (this->m_load > this->m_capacity) {
				this->m_load = this->m_capacity;
				isCapacityFull = true;
			}
			load = true;
		}
		else {
			load = false;
		}
		return load;
	}

	bool Truck::unloadCargo() {
		bool unload = false;
		if (this->m_load > 0) {
			this->m_load = 0;
			unload = true;
		}
		else {
			unload = false;
		}
		return unload;
	}

	std::ostream& Truck::write(std::ostream& os)const {
		MotorVehicle::write(os);
		os << " | " << this->m_load << "/" << this->m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> this->m_capacity;
		cout << "Cargo: ";
		in >> this->m_load;
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const Truck& truck) {
		return truck.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Truck& truck) {
		return truck.read(istr);
	}
}