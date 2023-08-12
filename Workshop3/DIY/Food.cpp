/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
// professor's tester program
//
//	File : Food.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   6/4/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Food.h"

using namespace std;
namespace sdds {
    void Food::setEmpty() {
        m_name[0] = '\0';
        m_calories = 0;
        m_time = 0;
    }

    void Food::setCalories(const char* name, int calories, int when) {
        if (name != nullptr && name[0] != '\0' && calories >= 0 && when >= 1 && when <= 4) {
            strncpy(m_name, name, 30);
            m_name[30] = '\0';
            m_calories = calories;
            m_time = when;
        }
        else {
            setEmpty();
        }
    }

    bool Food::isValid() const {
        return m_name[0] != '\0' && m_calories > 0 && m_time >= 1 && m_time <= 4;
    }

    void Food::display() const {
        if (isValid()) {
            cout << "| " << left << setw(30) << setfill('.');
            cout << m_name;
            cout << " | ";
            cout.setf(ios::right);
            cout.fill(' ');    // fills the space
            cout.width(4);
            cout << m_calories;
            cout << " | ";
            cout.width(10);
            switch (m_time)
            {
            case 1:
                cout << "Breakfast";
                break;
            case 2:
                cout << "Lunch";
                break;
            case 3:
                cout << "Dinner";
                break;
            case 4:
                cout << "Snack";
                break;
            }
            cout << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

    int Food::getCalories() const {
        return m_calories;
    }
}
