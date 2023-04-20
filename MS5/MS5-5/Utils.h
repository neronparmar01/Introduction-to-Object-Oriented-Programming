


#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
namespace sdds {
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
    int uniqueDateValue(int year, int mon, int day, int hour, int min);
    int daysOfMonth(int year, int month);
    int makeFoolproofChoice(int min, int max, const char* prompt);
}
#endif //!SDDS_UTILS_H_