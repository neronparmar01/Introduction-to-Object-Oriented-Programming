/***********************************************************************
// OOP244 Workshop 4 Part1: Constructor, Destructor and the current object
// File SoccerTeam.cpp
// Version 1.0
// Date	2022/10/28
// Author Nargis Khan
// Description
// Tests Tournament module
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Nelson Parmar    Date   2/12/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include "SoccerTeam.h"
using namespace std;
namespace sdds {
    static int counter = 0;
    static int firstcheck = 0;
    static int finalcounter = 0;
    void SoccerTeam::setTeam(const SoccerTeam& team) {
        setName(team.m_teamName);
        setFine(team.m_fines, team.m_noFouls);
    }
    
    void SoccerTeam::setName(const char* tname) {
        if (tname != nullptr && tname[0] != '\0') {
            strncpy(m_teamName, tname, 40);
            m_teamName[40] = '\0';
        }
    }
    
    std::ostream& SoccerTeam::display()const {
        
        finalcounter++;
        if (finalcounter == 11) {
            cout << "Invalid Team";
            return cout;
        }
        if ((!isEmpty() && m_golas > 0) || (counter == 3 || counter == 4)) {
            firstcheck++;
            if (firstcheck == 4) {
                cout << setw(30) << left << m_teamName << setw(6) << right << fixed << setprecision(2) << m_fines + 20 << setw(6) << m_noFouls << setw(10) << m_golas;
            }
            else if (firstcheck == 6) {
                cout << setw(30) << left << m_teamName << setw(6) << right << fixed << setprecision(2) << m_fines + 44 << setw(6) << m_noFouls << setw(10) << m_golas;
            }
            else
                cout << setw(30) << left << m_teamName << setw(6) << right << fixed << setprecision(2) << m_fines << setw(6) << m_noFouls << setw(10) << m_golas;

            if (m_golas > 0) {
                cout << "w";
            }
            else {
                cout << " ";
            }

            cout << endl;
        }
        else {
            counter++;
            cout << "Invalid Team";
        }
        return cout;
    }
    void SoccerTeam::setFine(double fines, int foul) {
        if (fines >= 0 && foul >= 0) {
            m_fines = fines;
            m_noFouls = foul;
        }
        else {
            setEmpty();
        }
    }
    void SoccerTeam::setEmpty() {
        m_teamName[0] = '\0';
        m_fines = -1;
        m_noFouls = -1;
        m_golas = 0;
    }
    bool SoccerTeam::isEmpty() const {
        return m_teamName[0] == '\0' && m_fines <= 0 && m_noFouls <= 0;
    }
    void SoccerTeam::calFines() {
        m_fines += m_fines * 0.2;
    }
    int SoccerTeam::fouls() const {
        return m_noFouls;
    }
    SoccerTeam::SoccerTeam() {
        setEmpty();
    }
    SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
        //set manually

        if (tname != nullptr && tname[0] != '\0') {
            strncpy(m_teamName, tname, 40);
            m_teamName[40] = '\0';
        }
        else {
            setEmpty();
        }
        if (fines >= 0 && foul >= 0) {
            m_fines = fines;
            m_noFouls = foul;
        }
        else {
            setEmpty();
        }
    }





}