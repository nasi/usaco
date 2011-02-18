/*
ID: nasiles1
LANG: C
TASK: sprime
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int prime[100000], n = 100000;
int ndigit;
int sol[10];

int check(int x)
{
	int i;
	if (x < n) return !prime[x]; else {
		for (i = 2; i <= (int)sqrt(x); i++) if (x % i == 0) return 0;
		return 1;
	}
}

void solve(int idx, int ans, FILE *fout)
{
	int i, t;
	if (idx == ndigit) {
		for (i = 0; i < ndigit; i++) fprintf(fout, "%d", sol[i]);
		fprintf(fout, "\n");
	} else {
		for (i = 1; i < 10; i++) {
			t = ans * 10 + i;
			if (check(t)) {
				sol[idx] = i;
				solve(idx+1, t, fout);
			}
		}
	}
}

int mark()
{
	memset(prime, 0, sizeof(prime));
	int i, j, k = 0;
	prime[0] = prime[1] = 1;
	for (i = 2; i < n; i++) {
		if (!prime[i]) {
			for (j = i+i; j < n; j += i) prime[j] = 1;
		}
	}
}

int main()
{
    FILE *fin = fopen("sprime.in", "r");
    FILE *fout = fopen("sprime.out", "w");
    mark();
    fscanf(fin, "%d", &ndigit);
    solve(0, 0, fout);
    
    return 0;
}
