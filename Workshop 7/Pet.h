/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	10/29/2022
// Author:  Jitesh Arora
// File:	Pet.h
// 
// Last Updated 11/27/2022 by Jitesh Arora
// 
// Description:
// Base class implementation for a Pet
// 
// Name : Neron Parmar
// Student ID : 171690217
//  
////////////////////////////////////////////////////////

#ifndef SDDS_PET_H
#define SDDS_PET_H

#include <iostream>

namespace sdds
{
	class Pet
	{
	public:
		const double COST_BASE = 1.00;		
		const double COST_FEED = 0.00;		
		const double COST_REVIVE = 0.25;	

		static const int MAXLEN_PETNAME = 20;

		char	m_Name[MAXLEN_PETNAME];
		int		m_origAge;
		int 	m_age;

		int		m_numFeeds;
		int		m_numHugs;
		int		m_numCleans;

		double	m_totalCharges;
		double	m_healthLvl;

		//	protected:
		void	applyHealthDelta(double delta);
		void	addCharge(double fee);
		bool	isAlive() const;

		int getFeeds();
		int getGrooms();
		int getHugs();


		Pet();
		Pet(const char* name, int age = 0, double incrBaseCharge = 0);

		void feed();
		void groom();
		void hug();
		void reSpawn();

		void payBalance(std::ostream& os);

		void operator++ (int num);			
		Pet& operator=(const Pet& rhs);		
		std::ostream& outputData(std::ostream& os);
	};
	std::ostream& operator<<(std::ostream& os, Pet& pet);
}

#endif