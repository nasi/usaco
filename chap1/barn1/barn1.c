/*
ID: nasiles1
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p, const void *q)
{ return (*(int*)p) - (*(int*)q); }

int main()
{
    FILE *fin = fopen("barn1.in", "r");
    FILE *fout = fopen("barn1.out", "w");
    int m, s, c, i, p, r;
    int a[300], in[300], top = 0, min = 300, max = 0;

    fscanf(fin, "%d %d %d", &m, &s, &c);
    for (i = 0; i < c; i++) {
        fscanf(fin, "%d", in+i);
        if (in[i] < min) min = in[i];
        if (in[i] > max) max = in[i];
    }
    qsort(in, c, sizeof(int), cmp);
    for (p=in[0], i=1; i < c; p=in[i], i++) { a[top++] = in[i] - p; }
    qsort(a, top, sizeof(int), cmp);
    if (m > c) { fprintf(fout, "%d\n", c); } else {
        r = max - min + 1;
        for (i = top-1; i > top-m; i--)
            r -= a[i] - 1;
        fprintf(fout, "%d\n", r);
    }

    return 0;
}
