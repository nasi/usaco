/*
ID: nasiles1
LANG: C
TASK: preface
*/
#include <stdio.h>
#include <string.h>

void int_to_roman(int num, char *dest)
{
    char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *thousands[] = {"", "M", "MM", "MMM", "MMMM", "MMMMM"};
    int th, h, t, o;
    
    th = num / 1000;
    h = (num % 1000) / 100;
    t = (num % 100) / 10;
    o = num % 10;
    
    sprintf(dest, "%s%s%s%s", thousands[th], hundreds[h], tens[t], ones[o]);
}

int main()
{
    FILE *fin = fopen("preface.in", "r");
    FILE *fout = fopen("preface.out", "w");
    char s[50000], *ch;
    char letters[10] = "IVXLCDM";
    int n, i, count[256];
      
    fscanf(fin, "%d", &n);
    memset(count, 0, sizeof(count));
    for (i = 1; i <= n; i++) {
        int_to_roman(i, s);
        for (ch = s; *ch; ch++) count[*ch]++;
    }
    for (ch = letters; *ch; ch++) {
        if (count[*ch]) fprintf(fout, "%c %d\n", *ch, count[*ch]);
    }
    
    return 0;
}
