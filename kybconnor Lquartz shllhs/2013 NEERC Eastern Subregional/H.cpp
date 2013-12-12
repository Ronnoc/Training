//Lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 1010
#define M 500000
struct node {
	int u, v, next;
} edge[M];
int tot, last[N];
int n, m;
int a, b, t;
vector <int> zero, one;
int matchx[N], matchy[N];
int visit[N];

void addedge (int u, int v) {
	edge[tot].u = u; edge[tot].v = v; edge[tot].next = last[u]; last[u] = tot++;
}

bool dfs (int u) {
	int v;
	for (int j = last[u]; -1 != j; j = edge[j].next) {
		v = edge[j].v;
		if (visit[v]) continue;
		visit[v] = true;
		if (-1 == matchy[v] || dfs (matchy[v])) {
			matchy[v] = u;
			matchx[u] = v;
			return true;
		}
	}
	return false;
}

int main() {
	while (scanf ("%d%d", &a, &b) != EOF) {
		scanf ("%d", &t);
		zero.clear(); one.clear();
		for (int i = 0; i < t; i++) {
			int x, y;
			scanf ("%d%d", &x, &y);
			if (y == 0) zero.push_back (x);
			else if (y == 1) one.push_back (x);
		}
		tot = 0;
		memset (last, -1, sizeof (last));
		n = zero.size(); m = one.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (zero[i] <= one[j]) {
					int delta = one[j] - zero[i];
					if (delta <= b || delta >= a) {
						addedge (i, n + j);
					}
				}
			}
		}
		int ans = 0;
		memset (matchx, -1, sizeof (matchx));
		memset (matchy, -1, sizeof (matchy));
		for (int i = 0; i < n; i++) {
			if (-1 == matchx[i]) {
				memset (visit, 0, sizeof (visit));
				if (dfs (i)) ans++;
			}
		}
		if (n == m && ans == n) {
			printf ("No reason\n");
			for (int i = 0; i < n; i++) {
				printf ("%d %d\n", zero[i], one[matchx[i]-n]);
			}
		} else {
			printf ("Liar\n");
		}
	}
	return 0;
}
