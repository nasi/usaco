/*
ID: nasiles1
LANG: C
TASK: numtri
*/
#include <stdio.h>

int n, a[1000][1000];

int max(int x, int y) { return (x > y) ? x : y; }

int main()
{
    FILE *fin = fopen("numtri.in", "r");
    FILE *fout = fopen("numtri.out", "w");
    int i, j, t, ans = 0;

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
    	for (j = 0; j <= i; j++) {
    		fscanf(fin, "%d", &t);
    		if (!i) a[i][j] = t; else {
    			if (j == 0) a[i][j] = t + a[i-1][j];
    			else if (j == i) a[i][j] = t + a[i-1][j-1];
    			else a[i][j] = t + max(a[i-1][j-1], a[i-1][j]);
    		}
    	}
    }
    for (i = 0; i< n; i++) ans = max(ans, a[n-1][i]);
    fprintf(fout, "%d\n", ans);
    return 0;
}
