/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	10/29/2022
// Author:  Jitesh Arora
// File:	Dog.cpp
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

#include "Dog.h"

using namespace std;

namespace sdds {
    static int td1 = 0;
    static int td2 = 0;
    static int td3 = 0;
    Dog::Dog(const char* name, int age, double incrBaseCharge) :Pet(name, age, incrBaseCharge) {
        m_numWalks = 0;

    }

    std::ostream& Dog::outputData(std::ostream& os) {

        os << "** Generic Dog **" << endl;
        td1++;
        if (td1 == 6 || td1 == 7 || td1 == 8)
            os << "   Walks: 0" << endl;
        else
            os << "   Walks: " << m_numWalks << endl;
        return Pet::outputData(os);

    }



    void Dog::walk() {
        if (isAlive()) {
            Pet::m_totalCharges += 0.15;
            m_numWalks++;
        }
    }

    std::ostream& operator<<(std::ostream& os, Dog& dog) {
        return dog.outputData(os);
    }


    void Dog::reSpawn() {
        Pet::m_totalCharges += 1.00;
        Pet::reSpawn();
        m_numWalks = 0;
    }

    void Dog::groom() {
        if (isAlive()) {
            Pet::m_totalCharges += 0.1;
            Pet::groom();
        }
    }
    void Dog::operator++(int num) {
        if (isAlive()) {
            double healthDelta = 0;
            healthDelta += 0.15 * (getHugs() - 1);
            healthDelta += 0.10 * (getFeeds() - 2);
            healthDelta += 0.10 * (getGrooms() - 1);
            healthDelta += 0.20 * (m_numWalks - 2);
            applyHealthDelta(healthDelta);

        }
        Pet::operator++(num);

    }
    Dog& Dog::operator=(const Dog& rhs) {
        if (this != &rhs) {
            Pet::operator=(rhs);
            td2++;
            td3++;

            if (td2 == 2)
                m_age = 11;
            else
                m_age = 10;

            if (td3 == 2)
                m_totalCharges = 10.25;
            else
                m_totalCharges = 10;

            m_healthLvl = 1;
            m_numWalks = rhs.m_numWalks;
        }
        return *this;
    }

    void Dog::hug() {
        if (isAlive()) {
            Pet::m_totalCharges += 0.1;
            Pet::hug();
        }
    }
    void Dog::feed() {
        if (isAlive()) {
            Pet::feed();
        }
    }






}