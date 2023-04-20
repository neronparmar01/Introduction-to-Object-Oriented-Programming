/***********************************************************************
// OOP244 Workshop 9:
// File	Person.h
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar      Date   3/31/23         Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_PERSON_H
#define SDDS_PERSON_H

#include <iostream>
namespace sdds {
    class Person {
    public:
        char* m_name{};
        char* m_middleName{};
        char* m_lastName{};

        Person();
        Person(const Person& copyFrom);
        Person& operator=(const Person& RightOperand);
        virtual ~Person();
        virtual std::istream& read(std::istream& istr);
        virtual std::ostream& write(std::ostream& ostr)const;

        virtual operator bool()const;

        virtual void operator~();
    };
    std::istream& operator>>(std::istream& leftOperand, Person& rightOperand);
    std::ostream& operator<<(std::ostream& leftOperand, const Person& rightOperand);
}

#endif
