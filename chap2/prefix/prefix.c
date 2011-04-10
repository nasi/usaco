/*
ID: nasiles1
LANG: C
TASK: prefix
*/
#include <stdio.h>
#include <string.h>

struct TrieNode {
    int next[26];
    int fin;
} node[2000];
int top = 0, nprims = 0;
char prim[201][11], str[200001];
int flag[200001];

int node_alloc()
{
    int i;
    for (i = 0; i < 26; i++) node[top].next[i] = -1;
    node[top].fin = 0;
    return top++;
}


void insert(char *s, int idx)
{
    int n1, c;
    
    if (*s == '\0') {
        node[idx].fin = 1;
        return;
    }
    
    c = *s - 'A';
    if (node[idx].next[c] < 0) {
        n1 = node_alloc();
        node[idx].next[c] = n1;
        insert(s+1, n1);
    } else {
        insert(s+1, node[idx].next[c]);
    }
}


void search(char *s, int idx, int base, int offset)
{
    int c, i;
    
    if (node[idx].fin) {
        flag[base + offset] = 2;
        for (i = base; i < base+offset; i++) {
            if (!flag[i]) flag[i] = 1;
        }
    }
    
    if (*(s+1) != '\0') {
        c = *(s+1) - 'A';
        if (node[idx].next[c] >= 0) {
            search(s+1, node[idx].next[c], base, offset+1);
        }
    }
}


int main()
{
    FILE *fin = fopen("prefix.in", "r");
    FILE *fout = fopen("prefix.out", "w");
    char t[80];
    int root, i, l, c;
    
    // Input
    while (1) {
        fscanf(fin, "%s", prim[nprims]);
        if (strcmp(prim[nprims], ".") == 0) break;
        nprims++;
    }
    str[0] = '\0';
    while (fscanf(fin, "%s", t) > 0) {
        strcat(str, t);
    }
    
    // Build Trie
    root = node_alloc();
    for (i = 0; i < nprims; i++)
        insert(prim[i], root);

    // Sequence Search
    memset(flag, 0, sizeof(flag));
    l = strlen(str);
    for (i = 0; i < l; i++) {
        c = *(str+i) - 'A';
        if (node[0].next[c] >= 0) {
            search(str+i, node[0].next[c], i, 0);
        }
    }
    
    for (i = 0; i < l; i++) {
        if (!flag[i]) break;
    }
    fprintf(fout, "%d\n", i);
    
    return 0;
}
