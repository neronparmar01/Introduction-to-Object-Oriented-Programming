/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1
// Version 1.0
// Description
// tester program
//
// File : Item.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar    Date    6/1/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);       // copies the string 
		m_itemName[20] = '\0';
	}

	void Item::setEmpty() {
		m_price = 0.0;				 // sets to impossible value
		m_itemName[0] = '\0';		 // sets the null
		m_taxed = false;
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (name != nullptr && price >= 0) {
			setName(name);    
			m_price = price;
			m_taxed = taxed;
		}
		else {
			setEmpty();
		}
	}

	double Item::price() const {
		return m_price;
	}

	double Item::tax()const {
		return (m_taxed ? m_price * 0.13 : 0.0);   // if loop
		}

	bool Item::isValid()const {
		if (m_itemName[0] != '\0' && m_price != 0.0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Item::display() const {
    if (isValid()) {
        cout << "| " << left << setw(20) << setfill('.') << m_itemName << " | "
            << right << setw(7) << setfill(' ') << fixed << setprecision(2) << m_price << " | "
            << (m_taxed ? "Yes " : "No  ") << "|" << endl;
    }
    else {
        cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
    }
}


}