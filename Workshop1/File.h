/***********************************************************************
// OOP244 Workshop 1 p1
//
// File  File.h
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar         Date  1/18/23     Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds
{

	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}
#endif // !SDDS_FILE_H_