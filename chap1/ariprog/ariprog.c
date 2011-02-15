/*
ID: nasiles1
LANG: C
TASK: ariprog
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _ { int a, b; } prog;

int cmp1(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int cmp2(const void *a, const void *b)
{
    int t = ((*(prog*)a).b - (*(prog*)b).b);
    if (t) return t; 
    else return ((*(prog*)a).a - (*(prog*)b).a);
}

int main()
{
    FILE *fin = fopen("ariprog.in", "r");
    FILE *fout = fopen("ariprog.out", "w");
    int i, j, k, m, n, p, q, a[40000], b = 0, s;
    int set[40000], nset = 0, l;
    char map[125005] = {0};
    prog sol[10005]; int nsol = 0;
    int x, y, max, flag;

    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);

    for (p = 0; p <= m; p++) {
        for (q = p; q <= m; q++) {
            s = p*p + q*q;
            a[b++] = s;
        }
    }
    qsort(a, b, sizeof(int), cmp1);
    set[0] = l = a[0]; nset++;
    for (i = 1; i < b; i++) {
        if (a[i] != l) { set[nset++] = a[i]; l = a[i]; }
    }
    for (i = 0; i < nset; i++) map[set[i]] = 1;

    max = set[nset-1];
    for (i = 0; i < nset; i++) {
        for (j = i+1; j < nset; j++) {
            x = set[i]; y = set[j] - set[i];
            if (x+(n-1)*y <= max) {
                flag = 1;
                for (k = 2; k < n; k++) {
                    if (!map[x+k*y]) { flag = 0; break; }
                }
                if (flag) {
                    sol[nsol].a = x;
                    sol[nsol].b = y;
                    nsol++;
                }
            }            
        }
    }
    qsort(sol, nsol, sizeof(prog), cmp2);
    for (i = 0; i < nsol; i++) fprintf(fout, "%d %d\n", sol[i].a, sol[i].b);
    if (nsol == 0) fprintf(fout, "NONE\n");

    return 0;
}
