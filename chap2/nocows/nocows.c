/*
ID: nasiles1
LANG: C
TASK: nocows
*/
#include <stdio.h>
#include <string.h>

int n, k;
unsigned long long ans[200][100];

int main()
{
    FILE *fin = fopen("nocows.in", "r");
    FILE *fout = fopen("nocows.out", "w");
    int i, j, m, h, exit = 0;
    unsigned long long t1, t2, s, d;
    
    memset(ans, 0, sizeof(ans));
    fscanf(fin, "%d %d", &n, &k);
    
    ans[1][1] = 1;
    
    for (i = 2; i <= k && !exit; i++) {
        for (m = 2*i-1; m <= n && !exit; m+=2) {
            s = 0;
            for (j = 1; j <= m-2; j+=2) {
                for (t1 = 0, h = 1; h < i-1; h++) { t1 += ans[j][h]; }
                for (t2 = 0, h = 1; h < i-1; h++) { t2 += ans[m-j-1][h]; }
                
                d = (t1 * ans[m-j-1][i-1]) + (ans[j][i-1] * t2);
                d += ans[j][i-1] * ans[m-j-1][i-1];
                s += d;
            }
            ans[m][i] = s % 9901;
            if (m == n && i == k) exit = 1;
        }
    }
    fprintf(fout, "%lld\n", ans[n][k] % 9901);
    
    return 0;
}
