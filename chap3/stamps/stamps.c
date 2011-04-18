/*
ID: nasiles1
LANG: C
TASK: stamps
*/
#include <stdio.h>
#include <string.h>

int n, k, s[55], a[2000000];

int main()
{
    FILE *fin = fopen("stamps.in", "r");
    FILE *fout = fopen("stamps.out", "w");
    int i, j, t;
    
    fscanf(fin, "%d %d", &k, &n);
    memset(a, 0, n*sizeof(int));
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d", s+i);
        a[s[i]] = 1;
    }
    
    i = 1;
    while (a[i] > 0) {
        for (j = 0; j < n; j++) {
            t = i + s[j];
            if (a[i] < k && (!a[t] || a[t] > a[i] + 1)) {
                a[t] = a[i] + 1;
            }
        }
        i++;
    }

    fprintf(fout, "%d\n", i-1);
    return 0;
}
