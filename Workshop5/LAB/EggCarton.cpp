/***********************************************************************
// OOP244 Workshop 5 Part1: Operators
// File EggCarton.cpp
// Version 1.0
// Date	2023/02
// Author Fardad Soleimanloo
// Description
// Tests EggCarton module
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Nelson Parmar   Date  2/16/23    Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "EggCarton.h"

using namespace std;

namespace sdds {
    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;

    void EggCarton::setBroken() {
        m_size = 0;
        m_egs = 0;
        jmboo = false;
    }

    EggCarton::operator int() const {
        return (bool)*this ? m_egs : -1;
    }

    EggCarton::operator double() const {
        return (bool)*this ? (jmboo ? JumboEggWieght : RegularEggWieght) * m_egs / 1000.0 : -1.0;
    }

    EggCarton& EggCarton::operator--() {
        if ((bool)*this && m_egs > 0) {
            m_egs--;
        }
        return *this;
    }

    EggCarton& EggCarton::operator++() {
        if ((bool)*this) {
            m_egs++;
            if (m_egs > m_size) {
                setBroken();
            }
        }
        return *this;
    }

    EggCarton EggCarton::operator--(int) {
        EggCarton temp = *this;
        --* this;
        return temp;
    }

    EggCarton::operator bool() const {

        return m_size > 0;

    }

    ostream& EggCarton::display(ostream& ostr) const {

        if (*this) {
            displayCarton(m_size, m_egs, jmboo, ostr);
        }
        else {
            ostr << "Broken Egg Carton!" << endl;
        }
        return ostr;

    }

    EggCarton& EggCarton::operator += (EggCarton& right) {
        if ((bool)*this) {
            int space = m_size - m_egs;
            if (space > 0) {
                m_egs += space;
                right.m_egs -= space;
            }
        }
        return *this;
    }

    ostream& operator << (ostream& ostr,
        const EggCarton& right) {
        return right.display(ostr);
    }

    EggCarton& EggCarton::operator += (int value) {
        if ((bool)*this) {
            m_egs += value;
            if (m_egs > m_size) {
                setBroken();
            }
        }
        return *this;
    }

    istream& EggCarton::read(istream& istr) {

        char jumbo;
        istr >> jumbo;
        istr.ignore();
        istr >> m_size;
        istr.ignore();
        istr >> m_egs;

        jmboo = jumbo == 'j';
        if (m_size < 6 || m_size > 36 || m_size % 6 != 0 || m_egs < 0 || m_egs > m_size) {
            setBroken();
        }
        return istr;

    }
    EggCarton EggCarton::operator++(int) {
        EggCarton temp = *this;
        ++* this;
        return temp;
    }

    EggCarton& EggCarton::operator = (int value) {
        if ((bool)*this) {
            m_egs = value;
            if (m_egs > m_size) {
                setBroken();
            }
        }
        return *this;
    }

    istream& operator >> (istream& istr, EggCarton& right) {

        return right.read(istr);
    }

    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {

        if (size >= 6 && size <= 36 && size % 6 == 0 && noOfEggs >= 0 && noOfEggs <= size) {
            m_size = size;
            m_egs = noOfEggs;
            jmboo = jumboSize;
        }
        else {
            setBroken();
        }

    }

    // displays the Carton on the screen
    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr) const {
        int cartonWidth = size == 6 ? 3 : 6;
        for (int i = 0; i < size; i++) {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        return ostr;
    }

    bool EggCarton::operator == (const EggCarton& right) const {
        return (bool)*this && (bool)right && (double)*this - (double)right >= -0.001 && (double)*this - (double)right <= 0.001;
    }

    int operator + (int left,
        const EggCarton& right) {
        return (bool)right ? left + (int)right : left;
    }

}