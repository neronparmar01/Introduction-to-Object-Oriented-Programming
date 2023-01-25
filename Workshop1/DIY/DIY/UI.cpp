// Workshop 1 p2: tester program
//
// File  UI.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name   Neron Parmar         Date  1/24/23          Reason
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "GPAlist.h"
#include "File.h"
#include "GPA.h"
#include "UI.h"
using namespace sdds;
using namespace std;

namespace sdds
{
    void funcMain(void)
    {
        if (fileopen("students.csv"))
        {
            struct GPA STUD[90];
            for (int i = 0; i < 90; i++)
            {
                STUD[i].s_no = STUD[i].gpa = 0;
                STUD[i].name[0] = '\0';
            }
            struct GPA dummy;
            int stu_counter = 0;
            int complete = 1;
            while (complete&& stu_counter < 90)
            {
                complete = stu_nam(dummy.name) && stu_num(&dummy.s_no) && stu_GPA(&dummy.gpa);
                if (complete)
                {
                    STUD[stu_counter++] = dummy;
                }
            }

            for (int x = 89; x > 0; x--)
            {
                for (int y = 0; y < x; y++)
                {
                    if (STUD[y].s_no > STUD[y + 1].s_no)
                    {
                        dummy = STUD[y];
                        STUD[y] = STUD[y + 1];
                        STUD[y + 1] = dummy;
                    }
                }
            }
            inpt(STUD);

            fileclose();
        }
    }
    void inpt(const struct GPA* STUD)
    {
        int done = 1;
        char character;
        double score = 0;
        int complete = 1;

        cout<<"Enter GPA query..."<<endl;

        while (done)
        {
            cout<<"? ";
            scanf("%c", &character);
            if (character != '!')
            {
                scanf("%lf", &score);
            }
            if (character == '!' || character == '>' || character == '<' || character == '~')
            {
                if (character == '!')
                {
                }
                if (score < 0.0 || score > 4.0)
                {
                    complete = 0;
                    cout<<"Sorry select any GPA less than or equal to 4."<<endl;
                }
            }
            else
            {
                complete = 0;
            }
            if (!complete)
            {

                cout<<"Syntax error: ? [Op][value]<ENTER>"<<endl;
                cout<<"Op: [>,<,~,!]"<<endl;
                printf("value: GPA value\n\n");
            }
            while (getchar() != '\n')
            {
                // do nothing!
            }
            if (complete)
            {
                done = outp(character, score, STUD) ? 1 : 0;
            }
            complete = 1;
        }
    }
    int outp(const char character, const double score, const struct GPA* STUD)
    {
        int done = 1;
        int check = 0;
        if (character == '~')
        {
            for (int i = 0; i < 90; i++)
            {
                if (STUD[i].gpa == score && STUD[i].s_no != 0)
                {
                    check++;
                    printf("[%d] %d: %0.1lf (%s)\n", check, STUD[i].s_no, STUD[i].gpa, STUD[i].name);
                }
            }
        }
        else if (character == '>')

        {
            for (int i = 0; i < 90; i++)
            {
                if (STUD[i].gpa > score && STUD[i].s_no != 0)
                {
                    check++;
                    printf("[%d] %d: %0.1lf (%s)\n", check, STUD[i].s_no, STUD[i].gpa, STUD[i].name);
                }
            }
        }
        else if (character == '<')
        {
            for (int i = 0; i < 90; i++)
            {
                if (STUD[i].gpa < score && STUD[i].s_no != 0)
                {
                    check++;
                    printf("[%d] %d: %0.1lf (%s)\n", check, STUD[i].s_no, STUD[i].gpa, STUD[i].name);
                }
            }
        }
        else if (character == '!')

        {
            char response;
            printf("Exit the program? (Y)es/(N)o: ");
            scanf("%c", &response);
            response = toupper(response);
            if (response == 'Y')
            {
                done = 0;
            }
            else
            {
                done = 1;
            }
        }
        return done;
    }
}
