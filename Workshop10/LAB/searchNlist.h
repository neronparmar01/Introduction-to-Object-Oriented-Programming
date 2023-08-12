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
// File : searchNList.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/7/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"

namespace sdds {
	//template
	template<typename T, typename K>
	bool search(Collection<T>& collection, const T arr[], int arrSize, const K& key) {
		bool found = false;
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == key) {
				collection.add(arr[i]);
				found = true;
			}
		}
		return found;
	}

	template<typename T>
	void listArrayElements(const char* title, const T arr[], int arrSize) {
		std::cout << title << std::endl;
		for (int i = 0; i < arrSize; i++) {
			std::cout << (i + 1) << ": " << arr[i] << std::endl;
		}
	}
}

#endif // !SDDS_SEARCHNLIST_H
