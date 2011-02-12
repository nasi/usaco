/*
ID: nasiles1
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <string.h>

int search(char *a, int n, int p, int dir)
{
    int i, k;
    char color = a[p];

    for (i = 0; i < n; i++) {
        k = p + i*dir;
        if (color == 'w' && a[k] != 'w') color = a[k];
        if (a[k] != color && a[k] != 'w') break;
    }

    return i;
}

int solve(char *a, int n, int start)
{
    int pivot = start + n, left, right;
    right = search(a, n, pivot, 1);
    left = search(a, n, pivot-1, -1);
    return (left + right>n) ? n : (left+right);
}

int main()
{
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    int i, n, m = -1, r; char a[1500], b[500];

    fscanf(fin, "%d", &n);
    fscanf(fin, "%s", b);
    strcpy(a, b); strcat(a, b); strcat(a, b);

    for (i = 0; i < n; i++) {
        r = solve(a, n, i);
        if (r > m) m = r; 
    }
    fprintf(fout, "%d\n", m);

    return 0;
}
