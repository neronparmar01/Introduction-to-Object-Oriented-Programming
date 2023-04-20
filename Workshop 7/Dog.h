/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	10/29/2022
// Author:  Jitesh Arora
// File:	Dog.h
// 
// Last Updated 11/27/2022 by Jitesh Arora
// 
// Description:
// Base class implementation for a Pet
// 
// Name : Neron Parmar
// Student ID : 171690217
//  
////////////////////////////////////////////////////////

#ifndef SDDS_DOG_H
#define SDDS_DOG_H

#include <iostream>
#include "Pet.h"

namespace sdds
{
    class Dog : public Pet
    {
        int m_numWalks;
    public:
        const double COST_FEED = 0.25;
        const double COST_REVIVE = 1.00;
        const double COST_BASE = 4.00;
        Dog();
        Dog(const char* name, int age = 0, double incrBaseCharge = 0);
        void operator++ (int num);
        Dog& operator=(const Dog& rhs);
        std::ostream& outputData(std::ostream& os);
        void walk();
        void reSpawn();
        void feed();
        void groom();
        void hug();

    };
    std::ostream& operator<<(std::ostream& os, Dog& dog);
}

#endif