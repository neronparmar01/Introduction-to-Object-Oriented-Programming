// Final Project Milestone 2
// Student Logical operator Tester program
// Version 1.0
// Date	2023-02-27
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
// Name : Neron Parmar               Student ID : 171690217
// File : Error.cpp
/////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>    // includes all the library
#include "Error.h"
using namespace std;

namespace sdds {
    Error::Error() {
        m_message = nullptr;
    }
    //Error(const Error& em)
    Error::Error(const Error& em) {
        if (em.m_message != nullptr) {
            m_message = new char[strlen(em.m_message) + 1];
            strcpy(m_message, em.m_message);
        }
        else {
            m_message = nullptr;
        }
    }
    Error::Error(const char* errorMessage) {
        if (errorMessage != nullptr) {
            m_message = new char[strlen(errorMessage) + 1];
            strcpy(m_message, errorMessage);
        }
        else {
            m_message = nullptr;
        }
    }


    bool Error::isClear() const {
        return m_message == nullptr;
    }
    void Error::message(const char* value) {
        delete[] m_message;
        m_message = new char[strlen(value) + 1];
        strcpy(m_message, value);
    }
    //Error& operator=(const Error& em)
    Error& Error::operator=(const Error& em) {
        if (this != &em) {
            delete[] m_message;
            m_message = new char[strlen(em.m_message) + 1];
            strcpy(m_message, em.m_message);
        }
        return *this;
    }

    const char* Error::message() const {
        return m_message;
    }
    Error& Error::operator=(const char* errorMessage) {
        delete[] m_message;
        m_message = new char[strlen(errorMessage) + 1];
        strcpy(m_message, errorMessage);
        return *this;
    }
    Error::operator bool() const {
        return m_message != nullptr;
    }
    std::ostream& operator<<(std::ostream& os, const Error& error) {
        if (!error.isClear()) {
            os << error.message();
        }
        return os;
    }
    Error::~Error() {
        delete[] m_message;
        m_message = nullptr;
    }
    void Error::clear() {
        delete[] m_message;
        m_message = nullptr;
    }

}