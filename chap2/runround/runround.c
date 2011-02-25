/*
ID: nasiles1
LANG: C
TASK: runround
*/
#include <stdio.h>
#include <string.h>

int runround(int x)
{
    char s[100], a[10];
    int len, i, k, cur;

    sprintf(s, "%d", x);
    len = strlen(s);
    memset(a, 0, sizeof(a));
    for (i = 0; i < len; i++) {
        k = s[i] - '0';
        if (!k || a[k]) return 0;
        a[k] = 1;
    }
    
    cur = 0;
    for (i = 0; i < len; i++) {
        k = s[cur] - '0';
        if (!k) return 0;
        s[cur] = '0';
        cur = (cur + k) % len;
    }
    return (cur == 0);
}

int main()
{
    FILE *fin = fopen("runround.in", "r");
    FILE *fout = fopen("runround.out", "w");
    int i, n;
    
    fscanf(fin, "%d", &n);
    
    i = n + 1;
    while (1) {
        if (runround(i)) { fprintf(fout, "%d\n", i); break; }
        i++;
    }

    return 0;
}
