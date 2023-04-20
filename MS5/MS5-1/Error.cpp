// Final Project
// Point of Sale Application
// Version 1.0
// Date  2023-03-29
// Author   Fardad Soleimanloo
// Description
// This program test the student implementation of the Point of
// Sale Application
//
// File : Error.cpp
// Name : Neron Parmar     Student ID : 171690217     Date : 4/16/23
/////////////////////////////////////////////////////////////////

#include <cstring>
#include <iostream>
#include "Error.h"

namespace sdds {

    Error::Error() {
        m_error = nullptr;
    }

    Error::Error(const char* error) : Error() {
        if (!error) return;
        int len = strlen(error);
        m_error = new char[len + 1]; // +1 for NULL
        strcpy(m_error, error);
    }

    Error::Error(const Error& other) : Error(other.m_error) {
    }

    Error::~Error() {
        clear();
    }

    Error& Error::operator=(const Error& other) {
        clear();
        if (other.m_error) {
            int len = strlen(other.m_error);
            m_error = new char[len + 1]; // +1 for NULL
            strcpy(m_error, other.m_error);
        }
        return *this;
    }

    Error::operator bool() const {
        if (m_error)
            return true;
        return false;
    }

    Error& Error::clear() {
        if (m_error)
            delete[] m_error;

        m_error = nullptr;
        return *this;
    }

    void Error::display(std::ostream& out) const {
        if (*this)
            out << m_error;
    }

    std::ostream& operator<<(std::ostream& out, const Error& err) {
        err.display(out);
        return out;
    }

}