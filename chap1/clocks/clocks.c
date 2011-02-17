/*
ID: nasiles1
LANG: C
TASK: clocks
*/
#include <stdio.h>
#include <string.h>
#define MAXSIZE 1000000

int c, orig = 0, map[265000], queue[MAXSIZE], prev[MAXSIZE], op[MAXSIZE], head, tail, curr;
int m[9] = {27, 7, 54, 73, 186, 292, 216, 448, 432};

void display(int x)
{
	int i, t;
	for (i = 0; i < 9; i++) {
		t = (x>>(i*2) & 3) * 3;
		if (t == 0) t = 12;
		printf("%d ", t);
		if ((i+1) % 3 == 0) printf("\n");
	}
	printf("\n");
}

int move(int curr, int i)
{
	int j, t;
	for (j = 0; j < 9; j++) {
		if (m[i]>>j & 1) {
			t = ((curr>>(j*2) & 3) + 1) % 4;
			curr = (curr & ~(3<<(j*2))) | (t << (j*2));
		}
	}
	return curr;
}

int main()
{
    FILE *fin = fopen("clocks.in", "r");
    FILE *fout = fopen("clocks.out", "w");
    int i, j, flag = 0, last, path[10000], npath = 0;

    for (i = 0; i < 9; i++) {
    	fscanf(fin, "%d", &c);
    	c = (c / 3) % 4;
    	orig |= c << (i*2);
    }
    memset(map, 0, sizeof(map));

    map[orig] = 1; head = 0; tail = 1; queue[0] = orig; prev[0] = -1;
    while (head < tail) {
    	for (i = 0; i < 9; i++) {
    		curr = move(queue[head], i);
    		if (curr == 0) { last = i; flag = 1; break; }
    		if (!map[curr]) {
    			map[curr] = 1;
    			prev[tail] = head;
    			op[tail] = i;
    			queue[tail++] = curr;
    		}
    	}
    	if (flag) break;
		head++;
    }

    while (prev[head] >= 0) {
    	path[npath++] = op[head];
    	head = prev[head];
    }

    for (i = npath-1; i >= 0; i--) fprintf(fout, "%d ", path[i]+1);
    fprintf(fout, "%d\n", last+1);

	return 0;
}
