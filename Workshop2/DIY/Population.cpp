/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2 Part 2
// Version 1.0
// Description
// professor's tester program
//
// File : Population.cpp
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar     Date   5/27/23      Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;

namespace sdds {
#include <fstream>

    bool load(const char* filename) {
        if (!filename) {
            cout << "Could not open data file: " << filename << endl;
            return false;
        }

        if (!openFile(filename)) {
            cout << "Could not open data file: " << filename << endl;
            return false;
        }

        int numRecords = noOfRecords();
        if (numRecords == 0) {
            closeFile();
            cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            return false;
        }

        PostalCode* populationData = new PostalCode[numRecords];
        if (!populationData) {
            closeFile();
            cout << "Allocation failed!" << endl;
            return false;
        }

        FILE* fptr = getFptr(); // Get the value of fptr from File.cpp

        for (int i = 0; i < numRecords; i++) {
            char code[4];
            int population;
            if (fscanf(fptr, "%3[^,],%d\n", code, &population) == 2) {
                strCpy(populationData[i].code, code);
                populationData[i].population = population;
            }
        }

        closeFile();
        return true;
    }



    void display() {
        PostalCode* populationData = nullptr;
        int numRecords = 0;

        if (openFile("PCpopulations.csv")) {
            numRecords = noOfRecords();
            if (numRecords > 0) {
                populationData = new PostalCode[numRecords];
                if (populationData) {
                    for (int i = 0; i < numRecords; i++) {
                        char code[4];
                        int population;
                        if (fscanf(getFptr(), "%3[^,],%d\n", code, &population) == 2) {
                            strCpy(populationData[i].code, code);
                            populationData[i].population = population;
                        }
                    }
                }
            }

            closeFile();
        }

        // Calculate total population
        int totalPopulation = 0;
        for (int i = 0; i < numRecords; i++) {
            totalPopulation += populationData[i].population;
        }

        // Sort population data in descending order
        for (int i = 0; i < numRecords - 1; i++) {
            for (int j = i + 1; j < numRecords; j++) {
                if (populationData[i].population > populationData[j].population) {
                    PostalCode temp = populationData[i];
                    populationData[i] = populationData[j];
                    populationData[j] = temp;
                }
            }
        }

        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < numRecords; i++) {
            cout << i + 1 << "- " << populationData[i].code << ": " << populationData[i].population << endl;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopulation << endl;

        delete[] populationData;
    }



    void deallocateMemory() {

    }
}