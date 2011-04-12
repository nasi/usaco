/*
ID: nasiles1
LANG: C
TASK: maze1
*/
#include <stdio.h>
#include <string.h>

#define INF 9999999

int width, height, n;
char map[210][100];
int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};


int ans[4000], path[4000], visit[4000];
int head, tail, queue[4000];

int is_exit(int x, int y)
{
    int k, xx, yy;
    
    if (x == 0 || y == 0 || x == height-1 || y == width-1) {
        for (k = 0; k < 4; k++) {
            xx = 2*x + 1 + d[k][0];
            yy = 2*y + 1 + d[k][1];
            
            if (map[xx][yy] == ' ') {
                if (xx == 0 || yy == 0) return 1;
                if (xx == 2*height || yy == 2*width) return 1;
            }
        }
    }

    return 0;
}


int main()
{
    FILE *fin = fopen("maze1.in", "r");
    FILE *fout = fopen("maze1.out", "w");
    int i, j, k, idx, ii, jj, x, y, a; char ch;
    
    fscanf(fin, "%d %d", &width, &height);
    fscanf(fin, "%c", &ch); // for linefeed
    for (i = 0; i < 2*height + 1; i++) {
        for (j = 0; j < 2*width + 1; j++) {
            fscanf(fin, "%c", &ch);
            map[i][j] = ch;
        }
        fscanf(fin, "%c", &ch); // for linefeed
    }

    n = width * height;
    for (i = 0; i < n; i++)
        ans[i] = INF;
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (is_exit(i, j)) {
                for (k = 0; k < n; k++) path[k] = INF;
                memset(visit, 0, sizeof(visit));
                
                // BFS
                head = 0; tail = 1; idx = i*width + j;
                queue[head] = idx;
                path[idx] = 1;
                visit[queue[head]] = 1;
                
                while (head < tail) {
                    for (k = 0; k < 4; k++) {
                        ii = queue[head] / width + d[k][0];
                        jj = queue[head] % width + d[k][1];
                        if (ii >= 0 && jj >= 0 && ii < height && jj < width) {
                            x = 2 * (queue[head] / width) + 1;
                            y = 2 * (queue[head] % width) + 1;
                            if (map[x+d[k][0]][y+d[k][1]] != ' ') continue;
                            if (visit[ii*width+jj]) continue;
                            queue[tail++] = ii*width + jj;
                            path[ii*width+jj] = path[queue[head]] + 1;
                            visit[ii*width+jj] = 1;
                        }
                    }
                    head++;
                }
                
                for (k = 0; k < n; k++) {
                    if (path[k] < ans[k]) ans[k] = path[k];
                }
            }
        }
    }

    a = -1;
    for (i = 0; i < n; i++)
        if (ans[i] > a) a = ans[i];
    fprintf(fout, "%d\n", a);

    return 0;
}
