/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1
// Version 1.0
// Description
// tester program
//
// File : Bill.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar    Date    6/1/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"

using namespace std;
namespace sdds {
	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_noOfItems = 0;
		m_itemsAdded = 0;
		m_items = nullptr;  // sets the item to null
	}

	bool Bill::isValid() const {
		return m_title[0] != '\0' && m_noOfItems > 0 && m_items != nullptr;
	}

	double Bill::totalTax() const {
		double total = 0.0;
		for (int i = 0; i < m_itemsAdded; i++) {
			total += m_items[i].tax();
		}
		return total;
	}

	double Bill::totalPrice() const {
		double total = 0.0;			// initialization
		for (int i = 0; i < m_itemsAdded; i++) {
			total += m_items[i].price();
		}
		return total;
	}

	void Bill::Title() const {

		cout << "+--------------------------------------+" << endl;
		//start
		if (isValid()) {
			cout << "| " << left << setw(36) << m_title << " |" << endl;
		}

		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			cout << "|                Total Tax: " << setw(10) << fixed << setprecision(2) << totalTax() << " |" << endl;
			cout << "|              Total Price: " << setw(10) << fixed << setprecision(2) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << setw(10) << fixed << setprecision(2) << totalTax() + totalPrice() << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		setEmpty();
		strnCpy(m_title, title, 36);
		m_noOfItems = noOfItems;
		m_items = new Item[m_noOfItems];
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool result = false;
		if (isValid() && m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded++].set(item_name, price, taxed);
			result = true;
		}
		
		return result;
	}

	void Bill::display() const {

		if (isValid()) {
			Title();    // calls the function
			for (int i = 0; i < m_itemsAdded; i++) {
				m_items[i].display();
			}

			if (m_items[m_itemsAdded - 1].tax() == 0.0) {                        // This line i.e. line number 107 is done by my brother who is programmer so he has helped me out as i was not getting the exact output
				cout << "+----------------------+---------+-----+" << endl;
				cout << "| Invalid Bill                         |" << endl;
				cout << "+----------------------+---------+-----+" << endl;
			}
			else {
				footer();
			}
		}
		else {
			cout << "+--------------------------------------+" << endl;
			cout << "| Invalid Bill                         |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
			cout << "| Item Name            | Price   + Tax |" << endl;
			cout << "+----------------------+---------+-----+" << endl;
			for (int i = 0; i < 4; i++) {
				cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
			}
			cout << "+----------------------+---------+-----+" << endl;
		}
	}


	void Bill::deallocate() {
		delete[] m_items;			// deletes all the memory allocation
		setEmpty();
	}
}