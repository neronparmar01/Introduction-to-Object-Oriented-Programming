/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// tester program
//
// File : HtmlText.h
//
// Revision History
// -----------------------------------------------------------
// Name  Neron Parmar     Date   8/2/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include <iostream>
#include "Text.h"
#include "cstring.h"
namespace sdds {
    class HtmlText : public Text {
        char* m_title;

    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& other);
        HtmlText& operator=(const HtmlText& other);
        ~HtmlText();

        virtual void write(std::ostream& os) const override;
    };
}

#endif // !SDDS_HTMLTEXT_H
