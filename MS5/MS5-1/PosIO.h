// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : PosIO.h
// Name : Neron Parmar     Student ID : 171690217     Date : 4/16/23
/////////////////////////////////////////////////////////////////

#ifndef SDDS_POSIO_H_
#define SDDS_POSIO_H_
#include <iostream>

namespace sdds {
    class PosIO {
    public:
        virtual ~PosIO() {}
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual std::ofstream& save(std::ofstream& of) const = 0;
        virtual std::ifstream& load(std::ifstream& ifs) = 0;
    };

    std::ostream& operator<<(std::ostream& os, const PosIO& pos);
    std::ofstream& operator<<(std::ofstream& of, const PosIO& pos);
    std::istream& operator>>(std::istream& in, PosIO& pos);
    std::ifstream& operator>>(std::ifstream& ifs, PosIO& pos);
}
#endif //!SDDS_POSIO_H_