/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	10/29/2022
// Author:  Jitesh Arora
// File:	Fish.h
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

#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include "Pet.h"

namespace sdds
{
    class Fish : public Pet
    {
        const double COST_FEED = 0.10;
        const double COST_REVIVE = 0.50;
        const double COST_BASE = 2.00;
    public:
        Fish(const char* name, int age = 0);
        void feed();
        void reSpawn();

        void operator++ (int num);

        Fish& operator=(const Fish& rhs);
    };
    std::ostream& operator<<(std::ostream& os, Fish& fish);
}

#endif