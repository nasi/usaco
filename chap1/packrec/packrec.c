/*
ID: nasiles1
LANG: C
TASK: packrec
*/
#include <stdio.h>
#include <string.h>

#define max(x, y)  ((x) > (y)) ? (x) : (y)
#define min(x, y)  ((x) < (y)) ? (x) : (y)

typedef struct _ {
	int w, h;
} rect;

rect a[4]; int tot = 0;
int ans = 9999, map[101];

void record(int w, int h)
{
	if (w*h >= tot) {
		if (w*h < ans) {
			ans = w * h;
			memset(map, 0, sizeof(map));
		} else if (w*h == ans) {
			map[min(w, h)] = 1;
		}
	}
}

void check()
{
	int w, h, i;

	/* pattern 1 */
	w = h = 0;
	for (i = 0; i < 4; i++) {
		w += a[i].w; h = max(h, a[i].h);
	}
	record(w, h);

	/* pattern 2 */
	w = h = 0;
	for (i = 0; i < 3; i++) {
		w += a[i].w; h = max(h, a[i].h);
	}
	h += a[3].h; w = max(w, a[3].w);
	record(w, h);

	/* pattern 3 */
	w = a[0].w + a[1].w; h = max(a[0].h, a[1].h);
	h += a[2].h; w = max(w, a[2].w);
	w += a[3].w; h = max(h, a[3].h);
	record(w, h);

	/* pattern 4 & 5 */
	w = a[0].w + a[1].w; h = max(a[0].h, a[1].h);
	w += max(a[2].w, a[3].w); h = max(h, a[2].h + a[3].h);
	record(w, h);

	/* pattern 6 */
	h = max(a[0].h + a[2].h, a[1].h + a[3].h);
	w = a[0].w + a[1].w;
	if (a[0].h < a[1].h) w = max(w, a[2].w + a[1].w);
	if (a[0].h + a[2].h > a[1].h) w = max(w, a[2].w + a[3].w);
	if (a[1].h < a[0].h) w = max(w, a[0].w + a[3].w);
	w = max(w, a[2].w); w = max(w, a[3].w);
	record(w, h);
}

void rotate(int idx)
{
	rect t;
	if (idx == 4) {
		check();
	} else {
		rotate(idx+1);
		t.w = a[idx].h; t.h = a[idx].w; a[idx] = t;
		rotate(idx+1);
		t.w = a[idx].h; t.h = a[idx].w; a[idx] = t;
	}
}

void solve(int idx)
{
	int i; rect t;
	if (idx == 4) { rotate(0); }
	else {
		for (i = idx; i < 4; i++) {
			t = a[idx]; a[idx] = a[i]; a[i] = t;
			solve(idx+1);
			t = a[idx]; a[idx] = a[i]; a[i] = t;
		}
	}
}

int main()
{
    FILE *fin = fopen("packrec.in", "r");
    FILE *fout = fopen("packrec.out", "w");
    int i, w, h, m;

    for (i = 0; i < 4; i++) {
    	fscanf(fin, "%d %d", &w, &h);
    	a[i].w = w; a[i].h = h; tot += w * h;
    }
    solve(0);
    fprintf(fout, "%d\n", ans);
    for(i = 0; i <= 100; i++)
    	if (map[i]) fprintf(fout, "%d %d\n", i, ans/i);

    return 0;
}
