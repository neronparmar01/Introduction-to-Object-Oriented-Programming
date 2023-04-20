// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : PosIO.cpp
// Name : Neron Parmar    Student ID : 171690217    Date: 4/16/23
/////////////////////////////////////////////////////////////////

#include "PosIO.h"

namespace sdds {

    std::ostream& operator<<(std::ostream& os, const PosIO& pos) {
        return pos.write(os);
    }

    std::ofstream& operator<<(std::ofstream& of, const PosIO& pos) {
        return pos.save(of);
    }

    std::istream& operator>>(std::istream& is, PosIO& pos) {
        return pos.read(is);
    }

    std::ifstream& operator>>(std::ifstream& ifs, PosIO& pos) {
        return pos.load(ifs);
    }

}