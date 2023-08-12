/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6
// Version 1.0
// Description
// tester program
//
// File: TextFile.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date    7/15/23        Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_TEXTFILE_H
#define SDDS_TEXTFILE_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "cstring.h"

namespace sdds {
	class TextFile {
		class Line {
			char* m_value = nullptr;
			operator const char* ()const;
			Line() {};
			Line& operator=(const char* lineContent);
			~Line();

			friend class TextFile;		// Allows TextFile to access Line class
		    
            // public declarations
        public:
            // Makes Line non-copyable and non-assignable
            Line(const Line&) = delete;
            Line& operator=(const Line&) = delete;
        };

        Line* m_textLines;
        char* m_filename;
        unsigned m_noOfLines;
        unsigned m_pageSize;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName)const;
        void setEmpty();
    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile&);
        TextFile& operator=(const TextFile&);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
	};

    // operators
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H
