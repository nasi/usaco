/*
ID: nasiles1
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _ { int start; int end; } node;

int cmp(const void *p, const void *q)
{ return (*(node*)p).start - (*(node*)q).start; }

int main()
{
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    int i, j, n, r1, r2;
    node c[6000];

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) 
        fscanf(fin, "%d %d", &c[i].start, &c[i].end);
    qsort(c, n, sizeof(node), cmp);
    
    r1 = r2 = 0;
    for (i = 0; i < n; i++) {
        int last = c[i].end;
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            if (j < i) {
                if (c[j].end > last) last = c[j].end;
            } else {
                if (c[j].start <= last && last < c[j].end) last = c[j].end;
                else if (c[j].start > last) break;
            }
        }
        if (last - c[i].start > r1) r1 = last - c[i].start;
        if (j < n) {
            if (c[j].start - last > r2) r2 = c[j].start - last;
        }
    }

    fprintf(fout, "%d %d\n", r1, r2);
    return 0;
}

