/*
ID: nasiles1
LANG: C
TASK: castle
*/
#include <stdio.h>
#include <string.h>

int m, n, map[55][55], visit[55][55], nroom = 0;
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int vertex[2600];
char adj[2600][2600];
int maxspace = -1, from, to;

void dfs(int i, int j)
{
    int k, di, dj;

    for (k = 0; k < 4; k++) {
        di = i + dir[k][0];
        dj = j + dir[k][1];
        if (!(map[i][j] & (1 << k)) && !visit[di][dj]) {
            visit[di][dj] = nroom;
            vertex[nroom]++;
            dfs(di, dj);
        }
    }
}

int main()
{
    FILE *fin = fopen("castle.in", "r");
    FILE *fout = fopen("castle.out", "w");
    int i, j, k, di, dj, flag = 0, largest;
    
    fscanf(fin, "%d %d", &m, &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            fscanf(fin, "%d", &map[i][j]);

    memset(visit, 0, sizeof(visit));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (!visit[i][j]) {
                visit[i][j] = ++nroom;
                vertex[nroom] = 1;
                dfs(i, j);
            }
        }
    }
    fprintf(fout, "%d\n", nroom);
    
    largest = -1;
    for (i = 1; i <= nroom; i++)
        if (largest < vertex[i]) largest = vertex[i];
    fprintf(fout, "%d\n", largest);
    
    memset(adj, 0, sizeof(adj));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < 4; k++) {
                if (map[i][j] & (1<<k)) {
                    di = i + dir[k][0];
                    dj = j + dir[k][1];
                    if (di >= 0 && dj >= 0 && di < n && dj < m && visit[i][j] != visit[di][dj]) {
                        adj[visit[i][j]][visit[di][dj]] = adj[visit[di][dj]][visit[i][j]] = 1;
                    }
                }
            }
        }
    }
    
    for (i = 1; i <= nroom; i++) {
        for (j = 1; j < i; j++) {
            if (adj[i][j] && (vertex[i]+vertex[j] > maxspace)) {
                maxspace = vertex[i] + vertex[j];
            }
        }
    }
    fprintf(fout, "%d\n", maxspace);
    
    for (j = 0; j < m && !flag; j++) {
        for (i = n-1; i >= 0 && !flag; i--) {
            for (k = 1; k <= 2; k++) {
                if (map[i][j] & (1<<k)) {
                    di = i + dir[k][0];
                    dj = j + dir[k][1];
                    if (di >= 0 && dj >= 0 && di < n && dj < m) {
                        if (vertex[visit[i][j]] + vertex[visit[di][dj]] == maxspace) {
                            fprintf(fout, "%d %d %c\n", i+1, j+1, k==1 ? 'N' : 'E');
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
