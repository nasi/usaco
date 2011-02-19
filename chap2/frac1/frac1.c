/*
ID: nasiles1
LANG: C
TASK: frac1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _ { int a, b; } solution;
solution sol[30000];
int n, nsol = 0;

int gcd(int x, int y)
{
    int z;
    while ( x != 0 ) {
       z = x; x = y % x; y = z;
    }
    return y;
}

int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

int cmp(const void *p, const void *q)
{
    int t = lcm((*(solution *)p).b, (*(solution *)q).b);
    int pp = t * (*(solution *)p).a / (*(solution *)p).b;
    int qq = t * (*(solution *)q).a / (*(solution *)q).b;
    
    return pp - qq;
}

int main()
{
    FILE *fin = fopen("frac1.in", "r");
    FILE *fout = fopen("frac1.out", "w");
    int i, j, k = 1;
    
    fscanf(fin, "%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= i; j++) {
            if (gcd(i, j) == 1) {
                sol[nsol].a = j; sol[nsol].b = i; nsol++;
            }
        }
    }
    qsort(sol, nsol, sizeof(solution), cmp);
    for (i = 0; i < nsol; i++) {
        fprintf(fout, "%d/%d\n", sol[i].a, sol[i].b);
    }
    
    return 0;
}
