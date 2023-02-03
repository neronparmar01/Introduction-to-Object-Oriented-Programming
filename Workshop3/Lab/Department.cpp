/***********************************************************************
// OOP244 Workshop 3 # p1: tester program
//
// File	Department.cpp
// Version 1.0
// Date		October 7, 2022
// Author	Mohammad Shamas
// Description
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Nelson Parmar         Date   2/2/23         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <cstring>

#include "Department.h"

using namespace std;

namespace sdds {

    void Department::updateName(const char* newname) {
        if (!newname)
            return;

        if (deptName) {
            delete[] deptName;
        }

        const size_t strsize = strlen(newname) + 1;
        deptName = new char[strsize];
        strncpy(deptName, newname, strsize);
    }

    void Department::updateBudget(double change) {
        bdgt += change;
    }

    bool Department::addProject(Project& project) {
        if (remainingBudget() < project.m_cost)
            return false;

        if (!prj) {
            numPrj = 1;
            prj = new Project[numPrj];
            prj[0] = project;
            return true;
        }

        Project* tmparr = new Project[numPrj + 1];
        for (int i = 0; i < numPrj; i++) {
            tmparr[i] = prj[i];
        }

        tmparr[numPrj] = project;

        delete[] prj;
        numPrj++;

        prj = new Project[numPrj];
        for (int i = 0; i < numPrj; i++) {
            prj[i] = tmparr[i];
        }

        delete[] tmparr;
        return true;
    }

    //creating the department
    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }

    void display(const Project& project) {
        cout << "Project " << project.m_topic <<
            " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //displaying the department
    void display(const Department& department) {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget() <<
            " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) {
            display(temp[i]);
        }
    }
}