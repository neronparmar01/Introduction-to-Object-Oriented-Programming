/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Description
// professor's tester program
//
//	File : ClaorieList.cpp
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
#include "CalorieList.h"

namespace sdds {
    void CalorieList::init(int size) {
        if (size < 1) {
            setEmpty();
            return;
        }
        m_noOfFoods = 0;
        m_foodAdded = 0;
        m_foods = new Food[size];
        m_size = size;
    }

    bool CalorieList::add(const char* item_name, int calories, int when) {
        if (m_foodAdded == m_size) {
            return false;
        }
        else {
            m_foods[m_noOfFoods].setCalories(item_name, calories, when);
            m_noOfFoods++;
            m_foodAdded++;
            return true;
        }
    }

    int CalorieList::totalCalories() const {
        int total = 0;
        for (int i = 0; i < m_noOfFoods; i++) {
            total += m_foods[i].getCalories();
        }
        return total;
    }

    void CalorieList::display() const {
        if (isValid()) {
            Title();
            for (int i = 0; i < m_noOfFoods; i++) {
                m_foods[i].display();
            }
                footer();
        }
        else {
            std::cout << "Invalid Calorie List!" << std::endl;
        }
    }

    void CalorieList::deallocate() {
        delete[] m_foods;
        setEmpty();
    }

    void CalorieList::setEmpty() {
        m_foods = nullptr;
        m_size = 0;
        m_noOfFoods = 0;
        m_foodAdded = 0;
    }

    bool CalorieList::isValid() const {
        return m_foods != nullptr;
    }

    void CalorieList::Title() const {
        std::cout << "+----------------------------------------------------+" << std::endl;
        if (isValid()) {
            if (m_foodAdded > 0) {
                std::cout << "|  Daily Calorie Consumption                         |" << std::endl;
            }
            else {
                std::cout << "|  Calorie Consumption list is empty!                |" << std::endl;
            }
        }
        else {
            std::cout << "|  Invalid Calorie Consumption list!                 |" << std::endl;
        }
        std::cout << "+--------------------------------+------+------------+" << std::endl;
        std::cout << "| Food name                      | Cals | When       |" << std::endl;
        std::cout << "+--------------------------------+------+------------+" << std::endl;
    }

    void CalorieList::footer() const {
        std::cout << "+--------------------------------+------+------------+" << std::endl;
        if (isValid()) {
            if (m_foodAdded > 0) {
                std::cout << "|    Total Calories for today: ";
                std::cout.width(8);
                std::cout << totalCalories() << " |            |" << std::endl;
            }
        }
        std::cout << "+----------------------------------------------------+" << std::endl;
    }
} 
