/*
ID: nasiles1
LANG: C
TASK: fracdec
*/
#include <stdio.h>
#include <string.h>

int n, d, a[100001], b[50000], bn = 1, line = 76;
char s[100];

void output(FILE* fout, char c)
{
    fprintf(fout, "%c", c);
    if (--line == 0) {
        line = 76;
        fprintf(fout, "\n");
    }
}

int main()
{
    FILE *fin = fopen("fracdec.in", "r");
    FILE *fout = fopen("fracdec.out", "w");
    int i, flag = 0;
    
    memset(a, 0, sizeof(a));
    fscanf(fin, "%d %d", &n, &d);
    
    sprintf(s, "%d.", n/d);
    fprintf(fout, "%s", s);
    line -= strlen(s);
    n %= d;
    if (n == 0) { fprintf(fout, "0"); line--; }
    a[n] = 1;
    while (n != 0) {
        b[bn++] = n * 10 / d;
        n = (n * 10) % d;
        if (a[n]) { flag = 1; break; }
        a[n] = bn;
    }
    for (i = 1; i < bn; i++) {
        if (flag && i==a[n]) output(fout, '(');
        output(fout, b[i] + '0');
    }
    if (flag) output(fout, ')');
    if (line != 76) fprintf(fout, "\n");

    return 0;
}
