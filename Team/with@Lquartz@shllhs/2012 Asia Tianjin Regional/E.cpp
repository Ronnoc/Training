//Lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define sqr(x) (x)*(x)
#define N 150
#define eps 1e-5
int n, D;
int xx[N], yy[N];
int dist[N][N];
struct Node {
	int u, v, d;
} edge[N*N];
int used[N];
int node, tot;
int fa[N];
void addedge (int u, int v) {
	edge[tot].u = u; edge[tot].v = v; tot++;
}
int getfa (int x) {
	if (x == fa[x]) return x;
	return (fa[x] = getfa (fa[x]));
}
int bfs() {
	tot = 0;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (!used[j]) {
				if (dist[i][j] <= D)
					addedge (i, j);
			} else {
				if (2*dist[i][j] <= D)
					addedge (i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) fa[i] = i;
	node = 1;
	for (int i = 0; i < tot; i++) {
		int x = getfa (edge[i].u), y = getfa (edge[i].v);
		if (x != y) fa[x] = y, node++;
	}
}

int main() {
	while (scanf ("%d%d", &n, &D) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf ("%d%d", &xx[i], &yy[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int d = sqr (xx[i] - xx[j]) + sqr (yy[i] - yy[j]);
				dist[i][j] = (int) (sqrt (d) + 1.0 - eps);
			}
		}
		memset (used, false, sizeof (used));
		bfs();
		if (node < n) {
			printf ("-1\n");
			continue;
		}
		int t = 0;
		
		for (int t = n - 1; t >= 1; t--) {
			used[t] = true;
			bfs();
			if (node < n) {
				used[t] = false;
			}
		}
		while (used[n-1]) n--;
		for (int i = n - 1; i >= 0; i--)
			if (!used[i]) printf ("1");
			else printf ("0");
		printf ("\n");
	}
	return 0;
}
