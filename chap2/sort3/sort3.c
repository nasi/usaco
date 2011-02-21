/*
ID: nasiles1
LANG: C
TASK: sort3
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _ { int start, end; } Edge;

int n, a[1001], b[1001], ans = 0;
int nedge = 0, visit[1001], start, length, flag;
Edge edge[1001];


int cmp1(const void *p, const void *q)
{
    return *(int*)p - *(int*)q;
}

int cmp2(const void *p, const void *q)
{
    Edge pp = *(Edge *)p;
    Edge qq = *(Edge *)q;
    
    if (pp.start != qq.start)
        return pp.start - qq.start;
    else
        return pp.end - qq.end;
}

void solve(int idx, int length)
{
    int i;
    
    if (edge[idx].end == edge[start].start) {
        ans += length;
        flag = 1;
        return;
    }
    
    for (i = 0; i < nedge; i++) {
        if (!visit[i] && edge[idx].end == edge[i].start) {
            visit[i] = 1;
            solve(i, length+1);
            if (flag) break;
        }
    }
}

int main()
{
    FILE *fin = fopen("sort3.in", "r");
    FILE *fout = fopen("sort3.out", "w");
    int i, j;
    
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d", a+i);
    }
    memcpy(b, a, n*sizeof(int));
    qsort(b, n, sizeof(int), cmp1);
    
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            edge[nedge].start = a[i];
            edge[nedge].end = b[i];
            nedge++;
        }
    }
    memset(visit, 0, sizeof(visit));
    qsort(edge, nedge, sizeof(Edge), cmp2);
    for (i = 0; i < nedge; i++) {
        if (!visit[i]) {
            flag = 0;
            visit[i] = 1;
            start = i;
            solve(i, 0);
        }
    }
    
    fprintf(fout, "%d\n", ans);
    
    return 0;
}
