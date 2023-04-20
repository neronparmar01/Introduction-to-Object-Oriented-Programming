// Final Project
// Milestone 4
// Perishable and NonPerishable Tester
// Version 1.0
// Date	2023-03-29
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of Milestone 4
// for submission.
//
// 
// Name : Neron Parmar      StudentID : 171690217
// File : PosIO.cpp
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