/***********************************************************************
// OOP244 Workshop 4 Part2: Constructor, Destructor and the current object
// File NameTag.h
// Version 1.0
// Date	2023/01
// Author Fardad Soleimanloo
// Description
// Tests NameTag module
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Nelson Parmar         Date   2/11/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_NAMETAG_H__
#define SDDS_NAMETAG_H__
namespace sdds {
    class NameTag {
    public:
        char* m_name;
        int m_extension;
    public:
        NameTag();
        NameTag(const char* name);
        NameTag(const char* name, int extension); // two argument constructor
        ~NameTag(); // destructor
        void print() const;
        NameTag& read();
    };
}

#endif