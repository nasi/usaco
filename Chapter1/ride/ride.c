/*
ID: nasiles1 
LANG: C
TASK: ride
*/
#include <stdio.h>

int number(char *s)
{
    int ret = 1;
    char *ch = s;
    while (*ch) {
        ret *= *ch - 64;
        ch++;
    }
    return ret % 47;
}

int main()
{
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");

    char comet[10], group[10];
    fscanf(fin, "%s", comet);
    fscanf(fin, "%s", group);
    if (number(comet) == number(group)) 
        fprintf(fout, "GO\n");
    else
        fprintf(fout, "STAY\n");

    return 0;
}
