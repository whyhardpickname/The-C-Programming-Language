#include<stdio.h>

char *month_name(int month);

int main() {
    printf("%s", month_name(11));
    return 0;
}

char *month_name(int month) {
    static char *monthtab[] = {
        "illegal month", 
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "Deceber"
    };
    
    return (month < 1 || month > 12) ? monthtab[0] : monthtab[month];
}