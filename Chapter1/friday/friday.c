/*
ID: nasiles1
LANG: C
TASK: friday
*/
#include <stdio.h>

int days[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int is_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");
    int n, i, j, d, cnt[10], year, sum = 0, leap;

    fscanf(fin, "%d", &n);
    for (i = 0; i < 7; i++) cnt[i] = 0;

    for (i = 1; i <= n; i++) {
        year = 1900 + i - 1;
        leap = is_leap(year);
        for (j = 0; j < 12; j++) {
            d = sum + days[j] + 13;
            if (j > 1) d += leap;
            cnt[d % 7]++;   
        }
        sum += 365 + leap;
    }   

    fprintf(fout, "%d", cnt[6]);
    for (i = 1; i < 7; i++) 
        fprintf(fout, " %d", cnt[(i+6) % 7]);
    fprintf(fout, "\n");

    return 0;
}
