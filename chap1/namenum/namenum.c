/*
ID: nasiles1
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <string.h>

typedef struct _ { char n[20]; } name_t;
char letters[10][10] = {
    "", "", "ABC", "DEF", "GHI", "JKL",
    "MNO", "PRS", "TUV", "WXY"
};
name_t name[5000], res; int l = 0, flag = 0, reslen;

void solve(char *s, int len, int idx, FILE *fout)
{
    int i, cur; char *p;
    if (len == 0) {
        for (i = 0; i < l; i++) {
            if (!strcmp(name[i].n, res.n)) {
                fprintf(fout, "%s\n", name[i].n);
                flag = 1;
            }
        } 
    } else {
        cur = s[0] - '0';
        for (p = letters[cur]; *p; p++) {
            res.n[idx] = *p;
            solve(s+1, len-1, idx+1, fout);
        }
    }
}

int main()
{
    FILE *fin = fopen("namenum.in", "r");
    FILE *fout = fopen("namenum.out", "w");
    FILE *dict = fopen("dict.txt", "r");
    char s[20], t[20]; int i;

    fscanf(fin, "%s", s); reslen = strlen(s);
    while (fscanf(dict, "%s", t) != EOF) {
        if (strlen(t) == reslen) {
            strcpy(name[l].n, t); l++;
        }
    }
    solve(s, strlen(s), 0, fout);
    if (!flag) fprintf(fout, "NONE\n");
    return 0;
}
