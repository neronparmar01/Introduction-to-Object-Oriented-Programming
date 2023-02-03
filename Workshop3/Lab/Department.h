/***********************************************************************
// OOP244 Workshop 3 # p1: tester program
//
// File	Department.h
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

#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH + 1];
        double m_cost;
    };

    class Department {
        char* deptName = nullptr;
        Project* prj = nullptr;
        int numPrj = 0;
        double bdgt = 15345.99;

    public:

        void updateName(const char* newname);
        void updateBudget(double change);
        bool addProject(Project& newproject);
        void createDepartment(const char* newname, Project& newproject, double change);

        Project* fetchProjects() const {
            return prj;
        };

        int fetchNumProjects() const {
            return numPrj;
        };

        double fetchBudget() const {
            return bdgt;
        };

        char* fetchName() const {
            return deptName;
        };

        double totalexpenses() {
            double sum = 0;
            for (int i = 0; i < numPrj; i++) {
                sum += prj[i].m_cost;
            }
            return sum;
        };

        double remainingBudget() {
            return bdgt - totalexpenses();
        };

        void clearDepartment() {
            delete[] deptName;
            delete[] prj;
            numPrj = 0;
        }
    };

    void display(const Project& project);
    void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_