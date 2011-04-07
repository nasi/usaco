/*
ID: nasiles1
LANG: C
TASK: concom
*/
#include <stdio.h>
#include <string.h>

int n, c[101][101], m = -1;

int main()
{
    FILE *fin = fopen("concom.in", "r");
    FILE *fout = fopen("concom.out", "w");
    int i, j, k, a, b, p, s, t, ii, jj;

    memset(c, 0, sizeof(c));
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d %d %d", &a, &b, &p);
        c[a][b] = p;
        m = (m > a) ? m : a;
        m = (m > b) ? m : b;
    }
    
    for (i = 1; i <= m; i++) {
        c[i][i] = 100;
    }
    
    for (t = 0; t < 10; t++) {
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= m; j++) {
                s = 0;
                for (k = 1; k <= m; k++) {
                    //if (i == 4 && j == 30 && k == 46) printf("kkk\n");
                    if (c[i][k] > 50) s += c[k][j];
                }
                if (s > 100) s = 100;
                if (s > 50) c[i][j] = s;                
            }
        }
    }
    
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= m; j++) {
            if (i == j) continue;
            if (c[i][j] > 50) fprintf(fout, "%d %d\n", i, j);
        }
    }
    
    return 0;
}
