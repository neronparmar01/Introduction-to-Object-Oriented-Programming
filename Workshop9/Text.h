/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// tester program
//
// File : Text.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/2/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <iostream>
#include <fstream>

namespace sdds {
    class Text {
        char* m_filename;
        char* m_content;
        int getFileLength()const;
    protected:
        const char& operator[](int index) const;

    public:
        Text(const char* filename = nullptr);
        Text(const Text& other);
        Text& operator=(const Text& other);
        ~Text();

        void read();
        virtual void write(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Text& text);
}

#endif // !SDDS_TEXT_H
