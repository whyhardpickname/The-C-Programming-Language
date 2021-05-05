#include<stdio.h>

static int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int day, int *pmonth,  int *pday);

int main() {

    printf("%d\n", day_of_year(2021, 2, 1));

    int month;
    int day;
    month_day(2021, 365, &month, &day);
    printf("%month = %d, day = %d\n", month, day);
    
    return 0;
}

int day_of_year(int year, int month, int day) {
    if (year < 1) {
        return -1;
    }

    if (month < 1 || month > 12) {
        return -1;
    }

    int leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
    int *p = daytab[leap];
    if (day < 1 || day > *(p + month)) {
        return -1;
    }

    while (--month) {
        day += *++p;
    }
    return day;
}

void month_day(int year, int day, int *pmonth,  int *pday) {
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    int leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
    

    int i;
    int month;
    int *p = daytab[leap];
    while (day > *++p) {
        day -= *p;
    }
    if (day <= *p) {
        *pmonth = p - *(daytab + leap);
        *pday = day;
    }
    else {
        *pmonth = -1;
        *pday = -1;
    }
}