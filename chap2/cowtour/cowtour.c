/*
ID: nasiles1
LANG: C
TASK: cowtour
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 1e10

struct _coord {
    int x, y;
} coord[150];

int ncomponent;
struct _component {
    int vertex[150], nvertex;
    double diameter;
    double far[150];
} component[150];

int n, adj[150][150], visit[150];


double distance(int u, int v)
{
    double d1 = coord[u].x - coord[v].x;
    double d2 = coord[u].y - coord[v].y;
    return sqrt(d1*d1 + d2*d2);
}

void input(FILE *fin)
{
    int i, j; char s[200];
    
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fin, "%d %d", &coord[i].x, &coord[i].y);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%s", s);
        for (j = 0; j < n; j++) {
            adj[i][j] = (s[j] == '1') ? 1 : 0;
        }
    }
}

void mark(int idx)
{
    int i;
    visit[idx] = 1;
    component[ncomponent].vertex[component[ncomponent].nvertex++] = idx;
    for (i = 0; i < n; i++) {
        if (!visit[i] && adj[idx][i]) mark(i);
    }
}

void find_component()
{
    int i, j, k, z;
    double dist[150][150], td;
    struct _component c;
    
    // find component
    memset(visit, 0, sizeof(visit));
    for (i = 0; i < n; i++) {
        if (visit[i]) continue;
        mark(i);
        ncomponent++;
    }
    
    // find diameter
    for (z = 0; z < ncomponent; z++) {
        c = component[z];
        // init
        for (i = 0; i < c.nvertex; i++) {
            for (j = 0; j < c.nvertex; j++) {
                if (i == j)
                    dist[i][j] = 0.0;
                else if (adj[c.vertex[i]][c.vertex[j]])
                    dist[i][j] = distance(c.vertex[i], c.vertex[j]);
                else
                    dist[i][j] = INF;
            }
        }
        
        // floyd-warshall
        for (k = 0; k < c.nvertex; k++) {
            for (i = 0; i < c.nvertex; i++) {
                for (j = 0; j < c.nvertex; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        // find max distance
        c.diameter = 0.0;
        for (i = 0; i < c.nvertex; i++) {
            for (j = 0; j < c.nvertex; j++) {
                if (dist[i][j] > c.diameter)
                    c.diameter = dist[i][j]; 
            }
        }
        
        // find far distance
        for (i = 0; i < c.nvertex; i++) {
            td = 0.0;
            for (j = 0; j < c.nvertex; j++) {
                if (dist[i][j] > td)
                    td = dist[i][j];
            }
            c.far[i] = td;
        }
        
        component[z] = c;
     }
}

void solve(FILE *fout)
{

    
    int ii, jj, i, j, k;
    double d, ans = INF, nd, td;
    struct _component c1, c2;
    
    for (ii = 0; ii < ncomponent; ii++) {
        for (jj = 0; jj < ii; jj++) {
            c1 = component[ii]; c2 = component[jj];
            d = (c1.diameter > c2.diameter) ? c1.diameter : c2.diameter;
            
            td = INF;
            for (i = 0; i < c1.nvertex; i++) {
                for (j = 0; j < c2.nvertex; j++) {
                    nd = c1.far[i] + c2.far[j] + distance(c1.vertex[i], c2.vertex[j]);
                    if (nd < td) td = nd;
                }
            }
            if (td > d) d = td;
            if (d < ans) ans = d;
        }
    }
  
    fprintf(fout, "%.6f\n", ans);
}

int main()
{
    FILE *fin = fopen("cowtour.in", "r");
    FILE *fout = fopen("cowtour.out", "w");

    input(fin);
    find_component();
    solve(fout);
    
    return 0;
}
