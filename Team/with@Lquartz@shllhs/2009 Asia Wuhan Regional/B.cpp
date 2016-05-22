//Lquartz kybconnor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
#define INF (1LL<< 50)
#define N 2100
#define M 210000
struct node {
	int u, v, next;
} edge[3][M];
int tot[3], last[3][N];
int n, R, Case = 1;
queue < int > Q, top[3];
int ind[3][N];
int ans[3][N];
void addedge (int o, int u, int v) {
	ind[o][v]++;
	edge[o][tot[o]].u = u; edge[o][tot[o]].v = v; edge[o][tot[o]].next = last[o][u]; last[o][u] = tot[o]++;
}

bool check (int o) {
	while (!Q.empty()) Q.pop();
	while (!top[o].empty()) top[o].pop();
	for (int i = 1; i <= 2*n; i++)
		if (ind[o][i] == 0)
			Q.push (i);
	int cnt = 0;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		top[o].push (now);
		cnt++;
		for (int j = last[o][now]; j != -1; j = edge[o][j].next) {
			int v = edge[o][j].v;
			ind[o][v]--;
			if (ind[o][v] == 0)
				Q.push (v);
		}
	}
	if (cnt < 2*n) return false;
	return true;
}

int main() {
	while (scanf ("%d%d", &n, &R) != EOF && n) {
		memset (tot, 0, sizeof (tot));
		memset (last, -1, sizeof (last));
		memset (ind, 0, sizeof (ind));
		char opt[10];
		int u, v;
		for (int i = 0; i < R; i++) {
			scanf ("%s%d%d", opt, &u, &v);
			if (opt[0] == 'I') {
				for (int j = 0; j < 3; j++) {
					addedge (j, u, v + n);
					addedge (j, v, u + n);
				}
			} else {
				addedge (opt[0] - 'X', u + n, v);
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				addedge (j, i, i + n);
		int flag = 0;
		for (int i = 0; i < 3; i++) {
			if (check (i)) flag++;
		}
		printf ("Case %d: ", Case++);
		if (flag < 3) {
			printf ("IMPOSSIBLE\n");
		} else {
			printf ("POSSIBLE\n");
			for (int i = 0; i < 3; i++) {
				int cnt = 0;
				while (!top[i].empty()) {
					int u = top[i].front();
					top[i].pop();
					ans[i][u] = cnt++;
				}
			}
			for (int i = 1; i <= n; i++)
				printf ("%d %d %d %d %d %d\n", ans[0][i], ans[1][i], ans[2][i], ans[0][i+n], ans[1][i+n], ans[2][i+n]);
		}
		printf ("\n");
	}
	return 0;
}

/*
2 2
I 1 2
X 1 2
*/
