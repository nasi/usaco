/*
ID: nasiles1
LANG: C
TASK: crypt1
*/
#include <stdio.h>
#include <string.h>

int a[10], b[10] = {0}, n, p[10], nsol = 0;

int check(int val, int len)
{
    char i, s[10], l;
    sprintf(s, "%d", val);
    l = strlen(s);
    if (l != len) return 0;
    for (i = 0; i < l; i++) 
        if (!b[s[i] - '0']) return 0;
    return 1;
}

void solve(int idx)
{
    int i, x, y;
    if (idx == 5) {
        x = p[0]*100 + p[1]*10 + p[2];
        y = p[3]*10 + p[4];
        if (check(x*y, 4) && check(p[4]*x, 3) && check(p[3]*x, 3)) nsol++;
    } else {
        for (i = 0; i < n; i++) {
            p[idx] = a[i];
            solve(idx+1);
        }
    }
}

int main()
{
    FILE *fin = fopen("crypt1.in", "r");
    FILE *fout = fopen("crypt1.out", "w");
    int i;

    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d", a+i);
        b[a[i]] = 1;
    }
    solve(0);
    fprintf(fout, "%d\n", nsol);
    return 0;
}
