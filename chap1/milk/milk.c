/*
ID: nasiles1
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _ { int p, a; } farmer;

int cmp(const void *p, const void *q)
{ return (*(farmer*)p).p - (*(farmer*)q).p; }

int main()
{
    FILE *fin = fopen("milk.in", "r");
    FILE *fout = fopen("milk.out", "w");
    int m, n, i, res = 0; farmer f[6000];
    
    fscanf(fin, "%d %d", &n, &m);
    for (i = 0; i < m; i++)
        fscanf(fin, "%d %d", &f[i].p, &f[i].a);
    qsort(f, m, sizeof(farmer), cmp);

    for (i = 0; i < m; i++) {
        if (f[i].a <= n) {
            n -= f[i].a;
            res += f[i].a * f[i].p;
        } else {
            res += n * f[i].p; 
            break;
        }
    }
    fprintf(fout, "%d\n", res);    

    return 0;
}
