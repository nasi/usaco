/*
ID: nasiles1
LANG: C
TASK: milk3
*/
#include <stdio.h>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

int a, b, c, p[21][21][21] = {0};


void solve(int x, int y, int z)
{
    int t;
    if (x < 0 || y < 0 || z < 0) return;
    if (!p[x][y][z]) {
        p[x][y][z] = 1;
        t = min(x, b-y); solve(x-t, y+t, z);
        t = min(x, c-z); solve(x-t, y, z+t);
        t = min(y, a-x); solve(x+t, y-t, z);
        t = min(y, c-z); solve(x, y-t, z+t);
        t = min(z, a-x); solve(x+t, y, z-t);
        t = min(z, b-y); solve(x, y+t, z-t);
    }
}

int main()
{
    FILE *fin = fopen("milk3.in", "r");
    FILE *fout = fopen("milk3.out", "w");
    int i, j, f, res[21], top = 0;

    fscanf(fin, "%d %d %d", &a, &b, &c);
    solve(0, 0, c);
    for (i = 0; i <= 20; i++) {
        f = 0;
        for (j = 0; j <= 20; j++) f += p[0][j][i];
        if (f) res[top++] = i;
    }
    for (i = 0; i < top; i++) {
        if (i) fprintf(fout, " %d", res[i]); else fprintf(fout, "%d", res[i]);
    }
    fprintf(fout, "\n");
    return 0;
}
