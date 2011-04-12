/*
ID: nasiles1
LANG: C
TASK: comehome
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define INF 99999999

int a[60][60], p, visit[60], d[60];

int ord(char c)
{
    if (islower(c)) return c - 'a';
    else return c - 'A' + 26;
}

int main()
{
    FILE *fin = fopen("comehome.in", "r");
    FILE *fout = fopen("comehome.out", "w");
    int i, j, k, u, v, sd, nd, wt, min, ans; char c1[10], c2[10];
    
    for (i = 0; i < 52; i++) {
        for (j = 0; j < 52; j++) a[i][j] = INF;
    }
    
    fscanf(fin, "%d", &p);
    for (i = 0; i < p; i++) {
        fscanf(fin, "%s %s %d", c1, c2, &wt);
        u = ord(c2[0]); v = ord(c1[0]);
        k = (wt < a[u][v]) ? wt : a[u][v];
        a[u][v] = a[v][u] = k;
    }
    
    memset(visit, 0, sizeof(visit));
    for (i = 0; i < 60; i++) d[i] = INF;
    
    d[ord('Z')] = 0;
    while (1) {
        u = -1; sd = INF;
        for (i = 0; i < 52; i++) {
            if (!visit[i] && d[i] < sd) { sd = d[i]; u = i; }
        }
        if (u == -1) break;
        
        visit[u] = 1;
        for (v = 0; v < 52; v++) {
            if (u == v) continue;
            nd = d[u] + a[u][v];
            if (nd < d[v]) d[v] = nd;
        }
    }
    
    ans = -1; min = INF;
    for (i = 26; i < 51; i++) {
        if (d[i] < min) { min = d[i], ans = i; }
    }
    fprintf(fout, "%c %d\n", 'A'+ans-26, min);
    
    return 0;
}
