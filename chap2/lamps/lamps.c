/*
ID: nasiles1
LANG: C
TASK: lamps
*/
#include <stdio.h>
#include <string.h>

int n, c, flip[4] = {63, 21, 42, 36}, on = 0, off = 0, sol[64];

int bit(int x, int b)
{
    return (x >> b) & 1;
}

void solve(int light, int i, int depth)
{
    int k;
    if (depth == 0) {
        for (k = 0; k < 6; k++) {
            if (bit(light, k) == 0 && bit(on, k) == 1) return;
            if (bit(light, k) == 1 && bit(off, k) == 1) return;
        }
        
        sol[light] = 1;
        return;
    }
    
    for (; i < 4; i++) solve(light ^ flip[i], i+1, depth-1);
}

void print(int light, FILE *fout)
{
    int i; char s[101];
    
    for (i = 0; i < n; i++) 
        s[i] = (light & (1<<(5 - i%6))) ? '1' : '0'; 
    s[n] = '\0';
    fprintf(fout, "%s\n", s);
}

int main()
{
    FILE *fin = fopen("lamps.in", "r");
    FILE *fout = fopen("lamps.out", "w");
    int i, t, flag = 1;
    
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &c);
    while (1) {
        fscanf(fin, "%d", &t);
        if (t == -1) break;
        t--; t %= 6; on |= 1 << (5 - t);
    }
    while (1) {
        fscanf(fin, "%d", &t);
        if (t == -1) break;
        t--; t %= 6; off |= 1 << (5 - t);
    }
    
    memset(sol, 0, sizeof(sol));
    if (c > 4) {
        if (c % 2) c = 3; else c = 4;
    }
    while (c >= 0) {
        solve(63, 0, c);
        c -= 2;
    }

    for (i = 0; i < 64; i++) {
        if (sol[i]) { print(i, fout); flag = 0; } 
    }
    if (flag) fprintf(fout, "IMPOSSIBLE\n");
    return 0;
}
