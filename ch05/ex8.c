#include<stdio.h>

static int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {

    return 0;
}
int day_of_year(int year, int month, int day);
void month_day(int year, int day);

int day_of_year(int year, int month, int day) {
    if (year < 1) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    int leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
    if (day < 1 || day > daytab[leap][month]) {
        return 0;
    }
    int i;
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}