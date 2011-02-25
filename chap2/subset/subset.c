/*
ID: nasiles1
LANG: C
TASK: subset
*/
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fin = fopen("subset.in", "r");
    FILE *fout = fopen("subset.out", "w");
    unsigned long n, i, j, sum, half, t, a[40][800], b[40][800];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    fscanf(fin, "%ld", &n);
    
    a[1][0] = a[1][1] = 1;
    for (i = 2; i <= n; i++) {
        sum = i * (i+1) / 2;
        for (j = 0; j <= sum; j++) {
            a[i][j] += a[i-1][j];
            if (a[i][j]) b[i][i+j] = a[i][j];
        }
        for (j = 0; j <= sum; j++)
            a[i][j] += b[i][j];
    }
    
    t = n * (n + 1);
    if (t % 4 == 0) {
        half = t / 4;
        fprintf(fout, "%ld\n", a[n][half] >> 1);
    } else {
        fprintf(fout, "0\n");
    }
    
    return 0;
}
