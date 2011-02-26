/*
ID: nasiles1
LANG: C
TASK: zerosum
*/
#include <stdio.h>

int n, p[10];

void solve(int idx, FILE *fout)
{
    int i, t = 1, sum = 0;
    if (idx == n-1) {
        for (i = 2; i <= n; i++) {
            switch (p[i-2]) {
                case 0: t *= 10; t = (t >= 0) ? (t+i) : (t-i); break;
                case 1: sum += t; t = i; break;
                case 2: sum += t; t = -i; break;
            }
        }
        sum += t;
        if (sum == 0) {
            fprintf(fout, "1");
            for (i = 0; i < n-1; i++) {
                switch(p[i]) {
                    case 0: fprintf(fout, " "); break;
                    case 1: fprintf(fout, "+"); break;
                    case 2: fprintf(fout, "-"); break;
                }
                fprintf(fout, "%d", i+2);
            }
            fprintf(fout, "\n");
        }
        
        return;
    }
    
    for (i = 0; i < 3; i++) { p[idx] = i; solve(idx + 1, fout); }
}

int main()
{
    FILE *fin = fopen("zerosum.in", "r");
    FILE *fout = fopen("zerosum.out", "w");

    fscanf(fin, "%d", &n);
    solve(0, fout);

    return 0;
}
