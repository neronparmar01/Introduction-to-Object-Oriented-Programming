// Final Project 
// PublicationSelector Usage demonstration
// File:	Streamable.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name    Neron Parmar     Date     8/7/23            Reason
//                    
/////////////////////////////////////////////////////////////////

#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

namespace sdds {
    class Streamable {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool conIO(std::ios& io) const = 0;
        virtual ~Streamable() {}
        virtual operator bool() const = 0;
    };

    std::ostream& operator<<(std::ostream& os, const Streamable& S);
    std::istream& operator>>(std::istream& is, Streamable& S);
}

#endif // SDDS_STREAMABLE_H
