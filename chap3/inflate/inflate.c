/*
ID: nasiles1
LANG: C
TASK: inflate
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct prob {
    int point, minute;
} p[10005];

int n, tot, a[10005];

int cmp(const void *p1, const void *p2)
{
    struct prob *pp1 = (struct prob *)p1;
    struct prob *pp2 = (struct prob *)p2;
    return pp1->minute - pp2->minute;
}

int main()
{
    FILE *fin = fopen("inflate.in", "r");
    FILE *fout = fopen("inflate.out", "w");
    int i, j, m, t, ans = -1;
    
    fscanf(fin, "%d %d", &tot, &n);
    memset(a, 0, n * sizeof(int));
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &p[i].point, &p[i].minute);
        a[p[i].minute] = p[i].point;
    }
    qsort(p, n, sizeof(struct prob), cmp);
    
    for (i = 1; i <= tot; i++) {
        if (a[i] == 0) continue;
        for (j = 0; j < n; j++) {
            m = i + p[j].minute;
            if (m > tot) break;
            t = a[i] + p[j].point;
            if (t > a[m]) a[m] = t;
        }
        if (a[i] > ans) ans = a[i];
    }
    
    fprintf(fout, "%d\n", ans);
    
    return 0;
}
