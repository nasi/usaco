/*
ID: nasiles1
LANG: C
TASK: checker
*/
#include <stdio.h>
#include <string.h>

int n, a[15], l[30], r[30], p[15];
int ans = 0, cnt = 0;

void solve(int i, int limit, FILE *fout)
{
    int j;
    if (i == n) {
        if (cnt++ < 3) {
            fprintf(fout, "%d", p[0]+1);
            for (j = 1; j < n; j++)
                fprintf(fout, " %d", p[j]+1);
            fprintf(fout, "\n");
        }
        ans++;
        if (n > 6 && p[0] < n/2) ans++;
    } else {
        for (j = 0; j < limit; j++) {
            if (!a[j] && !l[i+j] && !r[n-1-i+j]) {
                a[j] = l[i+j] = r[n-1-i+j] = 1;
                p[i] = j;
                solve(i+1, n, fout);
                a[j] = l[i+j] = r[n-1-i+j] = 0;
            }
        }
    }
}

void init()
{
    memset(a, 0, sizeof(a));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
}

int main()
{
    FILE *fin = fopen("checker.in", "r");
    FILE *fout = fopen("checker.out", "w");
    int i, j, k;
    
    init();
    fscanf(fin, "%d", &n);
    solve(0, (n>6) ? (n+1)/2 : n, fout);
    fprintf(fout, "%d\n", ans);

    return 0;
}
