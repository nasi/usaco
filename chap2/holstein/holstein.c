/*
ID: nasiles1
LANG: C
TASK: holstein
*/
#include <stdio.h>

int m, n, lim[30], t[30], v[20][30];

int main()
{
    FILE *fin = fopen("holstein.in", "r");
    FILE *fout = fopen("holstein.out", "w");
    int i, j, k, ans = 0, p[30], best = 30, sol[30];

    fscanf(fin, "%d", &m);
    for (i = 0; i < m; i++)
        fscanf(fin, "%d", lim+i);
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            fscanf(fin, "%d", &v[i][j]);

    for (i = 1; i < (1<<n); i++) {
        for (j = 0; j < m; j++) t[j] = lim[j];
        for (j = 0; j < n; j++) {
            if (i & (1<<j)) {
                for (k = 0; k < m; k++) {
                    t[k] -= v[j][k];
                }
            }
        }
        for (j = 0; j < m; j++) {
            if (t[j] > 0) break;
        }
        if (j == m) {
            for (ans = k = 0; k < n; k++) {
                if (i & (1<<k)) {
                    p[ans] = k+1;
                    ans++;
                }
            }
            
            if (ans < best) {
                best = ans;
                for (k = 0; k < best; k++) sol[k] = p[k];
            }
        }
    }
    
    fprintf(fout, "%d", best);
    for (k = 0; k < best; k++) {
        fprintf(fout, " %d", sol[k]);
    }
    fprintf(fout, "\n");
    
    return 0;
}
