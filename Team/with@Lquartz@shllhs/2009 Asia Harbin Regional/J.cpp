//Lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define N 1100
#define M 20000
#define INF (1<<25)
struct node {
	int u, v, c, w, next;
} edge[M];
int tot, last[N];
int dist[N], pre[N];
bool visit[N];
int S, T, src, des, n, m;
int flow, cost, value;
int goal[7][8] = {
	{1,2,1,1,2,1,1,2},
	{1,2,1,1,3,1,1,1},
	{1,2,1,1,3,0,0,3},
	{1,3,0,0,3,1,1,2},
	{1,3,0,0,4,1,1,1},
	{1,3,1,1,3,0,0,2},
	{1,4,1,1,3,0,0,1}
};
char str[7][10] = {"A","B","C","D","E","F","China"};
int a[N][10];

queue <int> Q;

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
		edge[p^1].c += mi;
		cost += mi * edge[p].w;
	}
	flow += mi;
}

void MinCostMaxFlow (int src, int des) {
	flow = cost = 0;
	while (spfa (src, des)) {
		ChangeFlow (src, des);
	}
}

int main() {
	char s[1000];
	while (scanf ("%d",&n) &&n) {
		for (int i = 1; i<=n; i++) {
			scanf ("%s%d%d%d%d%d%d%d%d",s,&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5],&a[i][6],&a[i][7]);
		}
		vector<int> ans1;
		int ans2 = -1;
		S = src = 0; T = des = n + 10;
		for (int i = 0; i < 7; i++) {
			memset (last, -1, sizeof (last));
			tot = 0;
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < 8; k++)
					addedge (j, n + k + 1, 1, -a[j][k]);
				addedge (S, j, 1, 0);
			}
			for (int j = 0; j < 8; j++) {
				addedge (n + 1 + j, T , goal[i][j], 0);
			}
			MinCostMaxFlow (S, T);
			//if(!flag) continue;
			cost = -cost;
			if (ans2 < cost) {
				ans1.clear();
				ans1.push_back (i);
				ans2 = cost;
			} else if (ans2 == cost) {
				ans1.push_back (i);
			}
		}
		for (int i = 0; i < ans1.size(); i++) {
			printf ("Formation %s has the highest points %d.\n",str[ans1[i]],ans2);
		}
		printf ("\n");
	}
	return 0;
}
