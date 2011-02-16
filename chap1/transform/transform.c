/*
ID: nasiles1
LANG: C
TASK: transform
*/
#include <stdio.h>
#include <string.h>

typedef struct _ { char p[20][20]; } square;

int is_same(square a, square b, int n)
{
    int i;
    for (i = 0; i < n; i++) 
        if (strcmp(a.p[i], b.p[i])) return 0;
    return 1;
}

void clone(square a, square *b, int n)
{
    int i;
    for (i = 0; i < n; i++) 
        strcpy(b->p[i], a.p[i]);
}

void _strrev(char *s)
{
    int i, l; char c;
    l = strlen(s);
    for(i = 0; i < l/2; i++) {
        c = s[i]; s[i] = s[l-i-1]; s[l-i-1] = c;
    }
}

void reflect(square *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        _strrev(a->p[i]);
}

void rotate90(square *a, int n)
{
    int i, j; square t;
    clone(*a, &t, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a->p[j][n-i-1] = t.p[i][j];  
}

int main()
{
    FILE *fin = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");
    int i, n, res = 7; square a, b, c;
    
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) fscanf(fin, "%s", a.p[i]);
    for (i = 0; i < n; i++) fscanf(fin, "%s", b.p[i]);

    /* rotated */
    clone(a, &c, n); rotate90(&c, n);
    if (is_same(c, b, n)) { res = 1; goto output; }
    clone(a, &c, n); rotate90(&c, n); rotate90(&c, n);
    if (is_same(c, b, n)) { res = 2; goto output; }
    clone(a, &c, n); rotate90(&c, n);
    rotate90(&c, n); rotate90(&c, n);
    if (is_same(c, b, n)) { res = 3; goto output; }
        
    /* reflection */    
    clone(a, &c, n); reflect(&c, n);
    if (is_same(c, b, n)) { res = 4; goto output; }

    /* combination */
    clone(a, &c, n); reflect(&c, n); rotate90(&c, n);
    if (is_same(c, b, n)) { res = 5; goto output; }
    clone(a, &c, n); reflect(&c, n);
    rotate90(&c, n); rotate90(&c, n);
    if (is_same(c, b, n)) { res = 5; goto output; }
    clone(a, &c, n); reflect(&c, n);
    rotate90(&c, n); rotate90(&c, n); rotate90(&c, n);
    if (is_same(c, b, n)) { res = 5; goto output; }

    /* same */
    if (is_same(a, b, n)) { res = 6; goto output; }

output:
    fprintf(fout, "%d\n", res);  
    
    return 0;
}
