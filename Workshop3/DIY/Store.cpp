/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Store.cpp
// Version 1.0
// Date	2022/10/28
// Author Nargis Khan
// Description
// Tests Store module
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Nelson Parmar   Date   2/6/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include "Store.h"
using namespace sdds;
using namespace std;

namespace sdds
{
    void Store::setStore(const char* sName, int no)
    {
        setEmpty();     // will set the store to the empty state at this point

        if (strlen(sName))
        {
            strncpy(m_sName, sName, MAX_SNAME - 1);
            m_sName[MAX_SNAME - 1] = '\0';  
        }

        if (no > 0)
        {
            m_noOfToys = no;
        }
    }

    void Store::setToys(const char* tname, int sku, double price, int age)
    {
        if (m_addToys < m_noOfToys)
        {
            m_toy[m_addToys].addToys(tname, sku, price, age);  // calling out the member function

            m_addToys++;
        }
    }

    void Store::display() const
    {
        int flag = 1;

        if (m_sName == nullptr)
        {
            std::cout << "Invalid input" << endl;
            flag = 0;
        }

        if (flag)   // checks whether the value of the flag is true or not
        {
            std::cout << std::setfill('*') << std::setw(60) << "*" << std::endl;
            std::cout << m_sName << std::endl;
            std::cout << std::setfill('*') << std::setw(60) << "*" << std::endl;
            std::cout << "list of the toys\n";
            std::cout << std::right << std::setfill(' ') << std::setw(30) << "SKU" <<
                std::right << std::setfill(' ') << std::setw(10) << "Age" <<
                std::right << std::setfill(' ') << std::setw(11) << "Price" <<
                std::right << std::setfill(' ') << std::setw(10) << "Sale" <<
                std::endl;

            for (int n = 0; n < m_noOfToys; n++)
            {
                std::cout << "Toy[" << n + 1 << "] :";

                m_toy[n].display();
            }
        }
        else
        {
            printf("Invalid Toys");
        }
    }

    void Store::find(int sku)
    {
        int flag = 1;
        for (int n = 0; n < MAX_NUM_TOYS && flag; n++)
        {
            if (m_toy[n].getSku() == sku)
            {
                m_toy[n].isSale(true); 
                m_toy[n].calSale();
            }
        }
    }

    void Store::setEmpty()
    {
        // sets all the variables to the null and the zero value to make it at the empty state
        m_sName[0] = '\0';
        m_noOfToys = 0;
        m_addToys = 0;
        for (int n = 0; n < MAX_NUM_TOYS; n++)
        {
            m_toy[n].addToys("\0", 0, 0, 0);
        }
    }
}