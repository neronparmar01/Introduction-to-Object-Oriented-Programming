/***********************************************************************
// OOP244 Workshop 4 Part1: Constructor, Destructor and the current object
// File Tournament.h
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

#ifndef SDDS_TOURNAMENT_H
#define SDDS_TOURNAMENT_H
#include <string.h>
#include<cstring>
#include "SoccerTeam.h"

namespace sdds
{
    class Tournament
    {
        char* m_name;
        int m_num;
        SoccerTeam* m_soccer = nullptr;
    public:
        Tournament();
        Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);
        ~Tournament();
        void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);
        void setEmpty();
        bool isEmpty() const;
        Tournament& match(const SoccerTeam* ls);
        ostream& display() const;
    };
}

#endif

