/*
ID: nasiles1
LANG: C
TASK: dualpal
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

int solve(int s)
{
    int i, cnt = 0;
    for (i = 2; i <= 10; i++) {
        if (palindromes(_itoa(s, i))) cnt++;
        if (cnt >= 2) return 1;
    }
    return 0;
}

int main()
{
    FILE *fin = fopen("dualpal.in", "r");
    FILE *fout = fopen("dualpal.out", "w");
    int i, n, s;

    fscanf(fin, "%d %d", &n, &s);

    s++;
    for (i = 0; i < n; i++) {
        while (!solve(s)) s++;
        fprintf(fout, "%d\n", s++);
    }

    return 0;
}
