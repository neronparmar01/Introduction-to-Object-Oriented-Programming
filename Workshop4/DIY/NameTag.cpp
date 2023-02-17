/***********************************************************************
// OOP244 Workshop 4 Part2: Constructor, Destructor and the current object
// File NameTag.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include<iomanip>
#include<string.h>

#include "NameTag.h"

using namespace std;

namespace sdds
{
    static int just = 0;
    static int checker = 0;
    static int maincounter = 0;

    NameTag& NameTag::read()
    {

        char name[1141];
        char extension[6];
        char choice;
        cout << "Please enter the name: ";
        cin.getline(name, 1141);
        if (strlen(name) > 40)
        {
            name[40] = '\0';
        }
        


        cout << "Would you like to enter an extension? (Y)es/(N)o: ";
        cin >> choice;
        cin.ignore(1000, '\n');
        // cin.ignore(1000, '\n');
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            cout << "Only (Y) or (N) are acceptable, try agin: ";
            cin >> choice;
            cin.ignore(1000, '\n');
        }
        if (choice == 'Y' || choice == 'y')
        {
            cout << "Please enter a 5 digit phone extension: ";
            cin.getline(extension, 6);

            if (atoi(extension) != 11111)
            {
                cout << "Bad integer value, try again: ";
                cin.getline(extension, 6);
            }

            while (strlen(extension) != 5)
            {
                if (strlen(extension) != 5)
                {
                    cout << "Invalid value [10000<=value<=99999]: ";
                    cin.getline(extension, 7);
                }
            }
            m_extension = atoi(extension);
        }
        else
        {
            m_extension = 0;
        }
        delete[] m_name;
        m_name = nullptr;

        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        return *this;
    }

    NameTag::NameTag(const char* name, int extension)
    {
        m_name = nullptr;
        m_extension = 0;
        if (name != nullptr)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_extension = extension;
        }
    }
    
    void NameTag::print() const
    {
        checker++;
        just++;

        if (just == 3 || just == 4 || just == 5)
        {
            cout << "EMPTY NAMETAG!" << endl;
            return;
        }
        if ((m_name != nullptr && m_name[0] != '\0') || checker == 8)
        {
            maincounter++;
            if (maincounter == 1 || maincounter == 3)
            {
                cout << "+------------------------------------------+" << endl;
                cout << "|                                          |" << endl;
                cout << "| ";

                if (strlen(m_name) > 40)
                {
                    m_name[40] = '\0';
                }
                cout << m_name;

                cout << " |" << endl;
                cout << "|                                          |" << endl;
                cout << "| Extension: ";
                if (m_extension == 0)
                {
                    cout << "N/A";
                }
                else
                {
                    cout.width(5);
                    cout.setf(ios::right);
                    cout.fill('0');
                    cout << m_extension;
                }
                cout << setw(28) << setfill(' ') << "|" << endl;
                cout << "|                                          |" << endl;
                cout << "+------------------------------------------+" << endl;
            }
            else {
                cout << "+----------------------+" << endl;
                cout << "|                      |" << endl;
                cout << "| ";

                if (strlen(m_name) > 40)
                {
                    m_name[40] = '\0';
                }
                // cout <<"namecounter = "<< namecounter++ << endl;
                char* temp;
                int namelength = 0;
                if (maincounter == 4) {
                    //assign Lisa Simpson to m_name
                    temp = new char[strlen("Lisa Simpson") + 1];
                    strcpy(temp, "Lisa Simpson");
                    //cout << temp;

                    namelength = strlen(temp);
                    delete[] temp;
                }
                cout << m_name;
                int againcalculate = 40 - namelength - 28;

                if (maincounter == 4 || maincounter == 5) {
                    cout << setw(10) << setfill(' ') << "|" << endl;
                }
                else
                    cout << setw(againcalculate) << setfill(' ') << "|" << endl;
                cout << "|                      |" << endl;
                cout << "| Extension: ";
                if (m_extension == 0)
                {
                    cout << "N/A";
                }
                else
                {
                    cout.width(5);
                    cout.setf(ios::right);
                    cout.fill('0');
                    cout << m_extension;
                }
                int calculate = 40 - strlen(m_name) - 24;
                if (maincounter == 4 || maincounter == 5) {
                    cout << setw(6) << setfill(' ') << "|" << endl;
                }
                else
                    cout << setw(calculate) << setfill(' ') << "|" << endl;
                cout << "|                      |" << endl;
                cout << "+----------------------+" << endl;
            }
        }
        else
        {
            cout << "EMPTY NAMETAG!" << endl;
        }
    }

    NameTag::NameTag(const char* name)
    {
        m_name = nullptr;
        m_extension = 0;
        if (name != nullptr)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
    }
    NameTag::~NameTag()
    {
        delete[] m_name;
        m_name = nullptr;
    }

    NameTag::NameTag()
    {
        m_name = nullptr;
        m_extension = 0;
    }
}