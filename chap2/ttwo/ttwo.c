/*
ID: nasiles1
LANG: C
TASK: ttwo
*/
#include <stdio.h>

char map[11][11];
int n = 10, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int xf, yf, ff = 0, xc, yc, fc = 0;

int main()
{
    FILE *fin = fopen("ttwo.in", "r");
    FILE *fout = fopen("ttwo.out", "w");
    int i, j, ans = 0, x, y;
    
    for (i = 0; i < n; i++) {
        fscanf(fin, "%s", map[i]);
        for (j = 0; j < n; j++) {
            if (map[i][j] == 'C') { xc = i; yc = j; }
            if (map[i][j] == 'F') { xf = i; yf = j; }
        }
    }
    
    while (1) {
        x = xc + dir[fc][0];
        y = yc + dir[fc][1];
        if (x >= 0 && y >= 0 && x < n && y < n && map[x][y] != '*') {
            xc = x; yc = y; 
        } else {
            fc = (fc + 1) % 4; 
        }
        
        x = xf + dir[ff][0];
        y = yf + dir[ff][1];
        if (x >= 0 && y >= 0 && x < n && y < n && map[x][y] != '*') {
            xf = x; yf = y; 
        } else {
            ff = (ff + 1) % 4;
        }
        
        ans++;
        if (xf == xc && yf == yc) break;
        if (ans > 10000) { ans = 0; break; } 
    }
    
    fprintf(fout, "%d\n", ans);
    return 0;
}
