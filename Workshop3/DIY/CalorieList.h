/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
// professor's tester program
//
//	File : ClaorieList.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   6/4/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H

#include "Food.h"

namespace sdds {
    class CalorieList {
        Food* m_foods;
        int m_noOfFoods;
        int m_foodAdded;
        int m_size; // Added member variable for size
        int totalCalories() const;
        void Title() const;
        void footer() const;
        void setEmpty();
        bool isValid() const;

    public:
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        void display() const;
        void deallocate();
    };
} 
#endif // !SDDS_CALORIELIST_H
