/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// tester program
//
// File : Text.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/2/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) {
        if (filename) {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
    }

    Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr) {
        *this = other;
    }

    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            delete[] m_filename;
            delete[] m_content;

            if (other.m_filename) {
                m_filename = new char[strLen(other.m_filename) + 1];
                strCpy(m_filename, other.m_filename);
            }
            else {
                m_filename = nullptr;
            }

            if (other.m_content) {
                m_content = new char[strLen(other.m_content) + 1];
                strCpy(m_content, other.m_content);
            }
            else {
                m_content = nullptr;
            }
        }
        return *this;
    }

    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }

    void Text::read() {
        delete[] m_content;
        m_content = nullptr;

        if (!m_filename) {
            return;
        }

        int fileLength = getFileLength();
        if (fileLength == 0) {
            return;
        }

        std::ifstream fin(m_filename);
        if (!fin) {
            return;
        }

        m_content = new char[fileLength + 1];
        fin.read(m_content, fileLength);
        m_content[fileLength] = '\0';
    }

    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    const char& Text::operator[](int index) const {
        return m_content[index];
    }

    void Text::write(std::ostream& os) const {
        if (m_content) {
            os << m_content;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Text& text) {
        text.write(os);
        return os;
    }
}
