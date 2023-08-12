/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// professor's tester program
//
// File: MotorVehicle.cpp
//
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar        Date     7/13/23       Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "MotorVehicle.h"

using namespace std;
namespace sdds {

	MotorVehicle::MotorVehicle() {
		this->m_licensePlate[0] = '\0';
		this->m_address[0] = '\0';
		this->m_year = 0;
	}

	MotorVehicle::MotorVehicle(const char* plate, const int year) {
		if (plate != nullptr && year > 0) {
			strCpy(this->m_licensePlate, plate);         // use this keyword
			strCpy(this->m_address, "Factory");
			this->m_year = year;
		}
	}

	void MotorVehicle::moveTo(const char* address) {
		if (address != nullptr) {
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << this->m_licensePlate;
			cout.unsetf(ios::right);
			// issue cleared
			cout << "| |";
			cout.width(20);
			// issue cleared
			cout << this->m_address;
			cout.unsetf(ios::right);
			cout << " ---> ";
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout << "|" << endl;
			cout.unsetf(ios::left);
			strCpy(this->m_address, address);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const {
		return os << "| " << this->m_year << " | " << this->m_licensePlate << " | " << this->m_address;
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> this->m_year;
		cin.ignore(1000, '\n');
		cout << "License plate: ";
		in.getline(this->m_licensePlate, 9, '\n');
		cout << "Current location: ";
		in.getline(this->m_address, 64, '\n');
		return in;
	}

	std::ostream& operator << (std::ostream& ostr, const MotorVehicle& vehicle) {
		return vehicle.write(ostr);
	}

	std::istream& operator >> (std::istream& istr, MotorVehicle& vehicle) {
		return vehicle.read(istr);
	}

	MotorVehicle::~MotorVehicle() {
		this->m_licensePlate[0] = '\0';
		this->m_address[0] = '\0';
		this->m_year = 0;
	}
}