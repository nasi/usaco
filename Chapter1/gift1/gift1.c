/*
ID: nasiles1
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>

int n;
char name[20][15];
int  money[20];

int find(char *s)
{
    int i;
    for (i = 0; i < n; i++)
        if (strcmp(s, name[i]) == 0)
            return i;
    return -1;
}

void solve()
{
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");

    int i, j, init, nfriends;
    int share, residual;
    char from[15], to[15];
    int f, t;

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%s", name[i]);
        money[i] = 0;
    }
    for (i = 0; i < n; i++) {
        fscanf(fin, "%s", from);
        fscanf(fin, "%d %d", &init, &nfriends);
        f = find(from);
        if (nfriends > 0) {
            share = init / nfriends;
            residual = init % nfriends;
        } else {
            share = residual = 0;
        }
        for (j = 0; j < nfriends; j++) {
            fscanf(fin, "%s", to);
            t = find(to);
            money[t] += share;
        }
        money[f] += residual - init;
    }
    for (i = 0; i < n; i++) {
        fprintf(fout, "%s %d\n", name[i], money[i]);
    }
}


int main()
{
    solve();
    return 0;
}
