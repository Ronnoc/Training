//Lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 2000
#define M 600000
#define eps (1e-10)
#define INF (1<<28)
struct node {
	int u, v, c, w, next;
} edge[M], edge1[M];
int tot, tot1, last[N], last1[N];
int Test, man, land[10], n, m, B, Case=1;
int S, T, src, des, flow, cost, ans;
queue < int > Q;
int dist[N], pre[N], value;
bool visit[N];

void addedge (int u, int v, int c, int w) {
	edge[tot].u = u; edge[tot].v = v; edge[tot].c = c; edge[tot].w = w; edge[tot].next = last[u]; last[u] = tot++;
	edge[tot].u = v; edge[tot].v = u; edge[tot].c = 0; edge[tot].w = -w; edge[tot].next = last[v]; last[v] = tot++;
}

bool spfa (int src, int des) {
	for (int i = 0; i <= des; i++) {
		dist[i] = INF;
		visit[i] = false;
	}
	while (!Q.empty()) Q.pop();
	dist[src] = 0;
	Q.push (src);
	visit[src] = true;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		visit[u] = false;
		for (int j = last[u]; j != -1; j = edge[j].next) {
			int v = edge[j].v, c = edge[j].c, w = edge[j].w;
			if (c > 0 && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pre[v] = j;
				if (!visit[v]) {
					visit[v] = true;
					Q.push (v);
				}
			}
		}
	}
	if (dist[des] == INF) return false;
	return true;
}

void ChangeFlow (int src, int des) {
	int p, mi = INF;
	for (int u = des; u != src; u = edge[p ^ 1].v) {
		p = pre[u];
		mi = min (mi, edge[p].c);
	}
	for (int u = des; u != src; u = edge[p ^ 1].v) {
		p = pre[u];
		edge[p].c -= mi;
		edge[p ^ 1].c += mi;
		cost += mi * edge[p].w;
	}
	flow += mi;
}

void MinCostMaxFlow (int src, int des) {
	flow = cost = 0;
	while (spfa (src, des)) {
		//cout << "xx" << endl;
		ChangeFlow (src, des);
	}
}

int main() {
	int x, y;
	scanf ("%d", &Test);
	while (Test--) {
		memset (last, -1, sizeof (last));
		tot = 0;
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf ("%d%d", &x, &y);
			addedge (x + n, y, 1, 0);
			addedge (y + n, x, 1, 0);
		}
		scanf ("%d", &man);
		for (int i = 0; i < 2 * man; i++)
			scanf ("%d", &land[i]);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			addedge (i, i + n, 1, x);
			sum += x;
		}
		tot1 = tot;
		for (int i = 0; i < N; i++)
			last1[i] = last[i];
		for (int i = 0; i <= tot; i++)
			edge1[i] = edge[i];
		ans = -1;
		S = src = 2*n;
		T = des = 2*n + 1;
		for (int i = 1; i < (1 << 2*man); i++) {
			y = i; x = 0;
			if (y > ( (1 << 2 * man) - y)) continue;
			while (y > 0) {
				if (y & 1) x++;
				y >>= 1;
			}
			if (x == man) {
				tot = tot1;
				for (int j = 0; j < N; j++)
					last[j] = last1[j];
				for (int j = 0; j <= tot; j++)
					edge[j] = edge1[j];
				for (y = 0; y < 2*man; y++)
					if (i & (1 << y))
						addedge (S, land[y], 1, 0);
					else addedge (land[y] + n, T, 1, 0);
				MinCostMaxFlow (S, T);
				if (flow == man)
					ans = max (ans, sum - cost);
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}

/*

9 7
0 1
2 3
4 5
6 7
5 7
5 8
4 6
3 0 1 2 3 6 8
1 1 1 1 1 1 1 1 1

*/
