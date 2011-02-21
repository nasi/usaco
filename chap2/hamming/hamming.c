/*
ID: nasiles1
LANG: C
TASK: hamming
*/
#include <stdio.h>
#include <string.h>

int h[300][300], path[100];
int n, b, d, flag = 0;
int visit[300];

int bitcount(int x)
{
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}

int far(int x, int m)
{
    int i;
    for (i = 0; i < m; i++)
        if (h[x][path[i]] < d) return 0;
    return 1;
}

void solve(int idx, FILE *fout)
{
    int i;
    if (flag) return;
    if (idx == n) {
        for (i = 0; i < n; i++) {
            fprintf(fout, "%d", path[i]);
            if (i < n-1) {
                fprintf(fout, "%c", ((i+1) % 10 == 0) ? '\n' : ' ');
            }
        }
        fprintf(fout, "\n");
        
        flag = 1;
    } else {
        for (i = 0; i < b; i++) {
            if (!visit[i] && far(i, idx)) {
                visit[i] = 1;
                path[idx] = i;
                solve(idx+1, fout);
                visit[i] = 0;
            }
        }
    }
}

int main()
{
    FILE *fin = fopen("hamming.in", "r");
    FILE *fout = fopen("hamming.out", "w");
    int i, j;
    
    fscanf(fin, "%d %d %d", &n, &b, &d);
    memset(visit, 0, sizeof(visit));
    b = 1 << b;
    for (i = 0; i < b; i++) {
        for (j = 0; j < b; j++)
            h[i][j] = bitcount(i ^ j);
    }
    solve(0, fout);
    return 0;
}
