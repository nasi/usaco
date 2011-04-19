/*
ID: nasiles1
LANG: C
TASK: humble
*/
#include <stdio.h>

int n, nprime, prime[105], hum[100005], nhum = 0, idx[105];

int main()
{
    FILE *fin = fopen("humble.in", "r");
    FILE *fout = fopen("humble.out", "w");
    int i, j; unsigned long min;
    
    fscanf(fin, "%d %d", &nprime, &n);
    for (i = 0; i < nprime; i++) {
        fscanf(fin, "%d", prime + i);
        idx[i] = 0;
    }
    
    hum[nhum++] = 1;
    while (nhum <= n) {
        min = ~0;
        for (i = 0; i < nprime; i++) {
            while (prime[i] * hum[idx[i]] <= hum[nhum-1]) idx[i]++;
            if (min > prime[i] * hum[idx[i]]) {
                min = prime[i] * hum[idx[i]];
            }
        }
        hum[nhum++] = min;
    }
    
    fprintf(fout, "%d\n", hum[n]);
    return 0;
}
