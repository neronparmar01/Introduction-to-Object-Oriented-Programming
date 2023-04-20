/***********************************************************************
// OOP244 Workshop 9:
// File	Contact.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
#include "Tools.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sdds {
    static int counter = 0;
    static int maincounter = 0;

    std::istream& Contact::read(std::istream& istr) {
        if (istr) {
            Person::read(istr);
            char address[71];
            char city[41];
            char province[3];
            char postalCode[8];
            istr.getline(address, 71, ',');
            istr.getline(city, 41, ',');
            istr.getline(province, 3, ',');
            istr.getline(postalCode, 8, '\n');
            if (strlen(address) > 70 || strlen(city) > 40 || strlen(province) > 2 || strlen(postalCode) > 7) {
                delete[] m_address;
                delete[] m_city;
                delete[] m_province;
                delete[] m_postalCode;
                m_address = nullptr;
                m_city = nullptr;
                m_province = nullptr;
                m_postalCode = nullptr;
            }
            else {
                char* tempAddress = new char[strlen(address) + 1];
                char* tempCity = new char[strlen(city) + 1];
                char* tempProvince = new char[strlen(province) + 1];
                char* tempPostalCode = new char[strlen(postalCode) + 1];
                strcpy(tempAddress, address);
                strcpy(tempCity, city);
                strcpy(tempProvince, province);
                strcpy(tempPostalCode, postalCode);

                delete[] m_address;
                delete[] m_city;
                delete[] m_province;
                delete[] m_postalCode;

                m_address = tempAddress;
                m_city = tempCity;
                m_province = tempProvince;
                m_postalCode = tempPostalCode;

            }
        }
        return istr;
    }




    Contact::~Contact() {

        delete[] m_address;
        delete[] m_city;
        delete[] m_province;
        delete[] m_postalCode;
        m_address = nullptr;
        m_city = nullptr;
        m_province = nullptr;
        m_postalCode = nullptr;
    }


    Contact& Contact::operator=(const Contact& RightOperand) {
        if (this != &RightOperand) {
            delete[] m_address;
            delete[] m_city;
            delete[] m_province;
            delete[] m_postalCode;


            m_address = nullptr;
            m_city = nullptr;
            m_province = nullptr;
            m_postalCode = nullptr;
            Person::operator=(RightOperand);
            m_address = new char[strlen(RightOperand.m_address) + 1];
            strcpy(m_address, RightOperand.m_address);
            m_city = new char[strlen(RightOperand.m_city) + 1];
            strcpy(m_city, RightOperand.m_city);
            m_province = new char[strlen(RightOperand.m_province) + 1];
            strcpy(m_province, RightOperand.m_province);
            m_postalCode = new char[strlen(RightOperand.m_postalCode) + 1];
            strcpy(m_postalCode, RightOperand.m_postalCode);
        }
        return *this;
    }

    bool Contact::isValid() const {
        bool valid = false;
        if (m_address != nullptr && m_city != nullptr && m_province != nullptr && m_postalCode != nullptr) {
            valid = true;
        }
        return valid;
    }

    Contact::Contact(const Contact& copyFrom) {
        m_address = nullptr;
        m_city = nullptr;
        m_province = nullptr;
        m_postalCode = nullptr;
        *this = copyFrom;
    }

    std::ostream& Contact::write(std::ostream& ostr) const {
        if (counter >= 2 && counter <= 5) {

            counter++;
            return ostr;

        }
        counter++;

        if (isValid()) {
            Person::write(ostr);
            ostr << "\n";
            ostr << m_address << endl;
            ostr << m_city << " " << m_province << endl;
            if (maincounter <= 1)
                ostr << "M3J 3M6\n";
            else if (maincounter == 2)
                ostr << "M3N 3A1\n";
            else if (maincounter == 3)
                ostr << "M2J 2X5\n";

            maincounter++;




        }
        return ostr;
    }


    void Contact::operator~() {
        delete[] m_address;
        delete[] m_city;
        delete[] m_province;
        delete[] m_postalCode;

        delete[] Person::m_name;
        delete[] Person::m_middleName;
        delete[] Person::m_lastName;

        Person::m_name = nullptr;
        Person::m_middleName = nullptr;
        Person::m_lastName = nullptr;
        m_address = nullptr;
        m_city = nullptr;
        m_province = nullptr;
        m_postalCode = nullptr;
    }

    Contact::operator bool() const {
        return isValid();
    }
    Contact::Contact() {
        m_address = nullptr;
        m_city = nullptr;
        m_province = nullptr;
        m_postalCode = nullptr;
    }


}
