/*
ID: nasiles1
LANG: C
TASK: money
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int v, n, m[30];
unsigned long long a[10005][30];

int cmp(const void *p, const void *q)
{
    return *(int*)p - *(int*)q;
}

int main()
{
    FILE *fin = fopen("money.in", "r");
    FILE *fout = fopen("money.out", "w");
    int i, j;
    memset(a, 0, sizeof(a));
    
    fscanf(fin, "%d %d", &v, &n);
    for (i = 0; i < v; i++) fscanf(fin, "%d", m+i);
    qsort(m, v, sizeof(int), cmp);
    
    for (i = 1; i <= n; i++) {
        for (j = 0; j < v; j++) {
            if (j == 0) {
                a[i][0] = (i % m[0] == 0) ? 1 : 0;
            } else {
                if (i > m[j]) {
                    a[i][j] = a[i][j-1] + a[i-m[j]][j];
                } else if (i == m[j]) {
                    a[i][j] = a[i][j-1] + 1;
                } else {
                    a[i][j] = a[i][j-1];
                }
            }
        }
    }
    
    fprintf(fout, "%lld\n", a[n][v-1]);
    
    return 0;
}
