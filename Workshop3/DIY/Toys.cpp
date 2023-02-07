/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File Toys.cpp
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
#include "Toys.h"
using namespace std;
using namespace sdds;

namespace sdds
{
    void Toys::addToys(const char* tname, int sku, double price, int age)
    {
        if (tname == nullptr)
        {
            m_tname[0] = '\0';    // initializing the m_tname to the null.
        }
        else if (strlen(tname) && sku >= 10000000 && sku <= 99999999 && price >= 0.0 && age > 0)
        {
            strcpy(m_tname, tname);    // copying the the name content to other
            m_sku = sku;
            m_price = price;
            m_age = age;
        }
        else
        {
            // setting values to zero and null
            m_tname[0] = '\0';
            m_sku = 0;
            m_price = 0.0;
            m_age = 0;
        }
    }

    void Toys::isSale(bool sale)
    {
        m_onSale = sale;
    }

    void Toys::calSale()
    {
        m_price = ((0.8) * m_price);
    }

    void Toys::display() const
    {
        if ((m_sku >= 10000000 && m_sku <= 99999999) && m_tname != nullptr && m_price > 0.0 && m_age > 0)
        {
            std::cout << std::left << std::setw(15) << m_tname <<
                std::right << std::setw(10) << m_sku <<
                std::right << std::setw(6) << m_age <<
                std::right << std::setw(12) << std::fixed << std::setprecision(2) << m_price;
            if (m_onSale)
            {
                std::cout << std::right << setw(10) << "On Sale";
                printf(" ");
            }
            else
            {
                std::cout << std::right << setw(8) << "";
            }

            std::cout << endl;
        }
        else
        {
            std::cout << "Invalid Toy" << endl;
        }
    }

    int Toys::getSku() const
    {
        return m_sku;  // returning the sku number
    }
}