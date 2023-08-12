/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// tester program
//
// File : HtmlText.cpp
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/2/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"
using namespace std;
namespace sdds {
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename), m_title(nullptr) {
        if (title) {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
    }

    HtmlText::HtmlText(const HtmlText& other) : Text(other), m_title(nullptr) {
        *this = other;
    }

    HtmlText& HtmlText::operator=(const HtmlText& other) {
        if (this != &other) {
            Text::operator=(other); // Call the base class's assignment operator

            delete[] m_title;
            if (other.m_title) {
                m_title = new char[strLen(other.m_title) + 1];
                strCpy(m_title, other.m_title);
            }
            else {
                m_title = nullptr;
            }
        }
        return *this;
    }

    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    void HtmlText::write(std::ostream& os) const {
        os << "<html><head><title>";
        os << (m_title ? m_title : "No Title");
        os << "</title></head>\n<body>\n";
        if (m_title) {
            os << "<h1>" << m_title << "</h1>\n";
        }

        bool multipleSpaces = false;
        for (int i = 0; (*this)[i] != '\0'; i++) {
            char ch = (*this)[i];
            switch (ch) {
            case ' ':
                if (multipleSpaces) {
                    os << "&nbsp;";
                }
                else {
                    os << " ";
                    multipleSpaces = true;
                }
                break;
            case '<':
                os << "&lt;";
                multipleSpaces = false;
                break;
            case '>':
                os << "&gt;";
                multipleSpaces = false;
                break;
            case '\n':
                os << "<br />\n";
                multipleSpaces = false;
                break;
            default:
                os << ch;
                multipleSpaces = false;
                break;
            }
        }

        os << "</body>\n</html>";
    }
}
