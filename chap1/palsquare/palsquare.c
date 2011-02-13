/*
ID: nasiles1
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <string.h>

char* _itoa(int val, int base)
{
    static char buf[200] = {0};
    int i = 100;
    for(; val && i ; --i, val /= base)
        buf[i] = "0123456789ABCDEFGHIJKL"[val % base];
    return &buf[i+1];
}

int palindromes(char *s)
{
    int i, l;
    l = strlen(s);
    for (i = 0; i < l/2; i++)
        if (s[i] != s[l-i-1]) return 0;
    return 1;
}

int main()
{
    FILE *fin = fopen("palsquare.in", "r");
    FILE *fout = fopen("palsquare.out", "w");
    int i, n;
    char a[100], b[100];

    fscanf(fin, "%d", &n);
    for (i = 1; i <= 300; i++) {
        strcpy(a, _itoa(i, n));
        strcpy(b, _itoa(i*i, n));
        if (palindromes(b)) fprintf(fout, "%s %s\n", a, b);
    }
    return 0;
}
