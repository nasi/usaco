/*
ID: nasiles1
LANG: C
TASK: calfflac
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *fin = fopen("calfflac.in", "r");
    FILE *fout = fopen("calfflac.out", "w");
    char s[20050], a[20050], line[100];
    int len, max = 0, b, e, mb, me, l, p[20050], n = 0, i;    

    s[0] = '\0';
    while (fgets(line, sizeof(line), fin)) {
        strcat(s, line);
    }
    len = strlen(s);
    for (i = 0; i < len; i++) {
        if (isupper(s[i])) { a[n] = tolower(s[i]); p[n] = i; n++; }
        if (islower(s[i])) { a[n] = s[i]; p[n] = i; n++; }
    }

    for (i = 0; i < n; i++) {
        /* pattern 1: madam */
        b = i-1; e = i+1;
        while (b >= 0 && e < n && a[b] == a[e]) { b--; e++; }
        b++; e--; l = e - b + 1;
        if (l > max) { max = l; mb = b; me = e; }

        /* pattern 2: calfflac */
        if (i < n-1 && a[i] == a[i+1]) {
            b = i-1; e = i+2;
            while (b >= 0 && e < n && a[b] == a[e]) { b--; e++; }
            b++; e--; l = e - b + 1;
            if (l > max) { max = l; mb = b; me = e; }
        }
    }
    fprintf(fout, "%d\n", max);
    for (i = p[mb]; i <= p[me]; i++) fprintf(fout, "%c", s[i]);
    fprintf(fout, "\n");
    return 0;
}
