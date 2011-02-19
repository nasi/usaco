/*
ID: nasiles1
LANG: C
TASK: pprime
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int ans[1000], n = 0, a, b;
int np[100000];

void init()
{
    int i, j;
    memset(np, 0, sizeof(np));
    np[0] = np[1] = 1;
    for (i = 2; i < 100000; i++) {
        if (!np[i])
            for (j = i+i; j < 100000; j += i) np[j] = 1;
    }
}

int prime(int x)
{
    int i;
    for (i = 2; i <= (int)sqrt(x); i++) if (x % i == 0) return 0;
    return 1;
}

void solve(int ndigit)
{
    int i, j, k, l, s;
    if (ndigit == 3) {
        for (i = 1; i < 10; i += 2)
            for (j = 0; j < 10; j++) {
                s = i*100 + j*10 + i;
                if (!np[s]) { ans[n++] = s; }
            }
    } else if (ndigit == 5) {
        for (i = 1; i < 10; i += 2)
            for (j = 0; j < 10; j++) 
                for (k = 0; k < 10; k++) {
                    s = i*10000 + j*1000 + k*100 + j*10 + i;
                    if (!np[s]) { ans[n++] = s; }
                }
    } else if (ndigit == 7) {
        for (i = 1; i < 10; i += 2)
            for (j = 0; j < 10; j++)
                for (k = 0; k < 10; k++)
                    for (l = 0; l < 10; l++) {
                        s = i*1000000 + j*100000 + k*10000 + l*1000 + k*100 + j*10 + i;
                        if (prime(s)) { ans[n++] = s; }
                    }
    }
}

int main()
{
    FILE *fin = fopen("pprime.in", "r");
    FILE *fout = fopen("pprime.out", "w");
    int i;
    
    init();
    fscanf(fin, "%d %d", &a, &b);
    ans[n++] = 5; ans[n++] = 7; ans[n++] = 11;
    solve(3); solve(5); solve(7);
    
    for (i = 0; i < n; i++) {
        if (ans[i] >= a && ans[i] <= b) fprintf(fout, "%d\n", ans[i]);
    }
    return 0;
}
