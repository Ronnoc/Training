//Lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
#define INF (1LL<< 50)
#define N 310
int combine[N];
LL edge[N][N], g[N][N];
int node[N];
int S, T;
LL minCut, k;
int top, sta[N];
LL maxi;
int n, m;
int visit[N];

LL Search (int n) {
	int vis[N];
	LL wet[N];
	memset (vis, 0, sizeof (vis));
	memset (wet, 0, sizeof (wet));
	LL minCut = 0;
	int temp = -1;
	S = -1; T = -1;
	int top = 0;
	for (int i = 0; i < n; i++) {
		LL maxi = -INF;
		for (int j = 0; j < n; j++) {
			int u = node[j];
			if (!combine[u] && !vis[u] && wet[u] > maxi) {
				temp = u;
				maxi = wet[u];
			}
		}
		sta[top++] = temp;
		vis[temp] = true;
		//cout << "yy " << i << temp << endl;
		if (i == n-1)
			minCut = maxi;
		for (int j = 0; j < n; j++) {
			int u = node[j];
			if (!combine[u] && !vis[u]) {
				wet[u] += edge[temp][u];
			}
		}
	}
	S = sta[top - 2];
	T = sta[top - 1];
	for (int i = 0; i< top; i++)
		node[i] = sta[i];
	//printf("XX %")
	return minCut;
}

LL StoerWagner (int n) {
	LL ans = INF;
	memset (combine, 0, sizeof (combine));
	for (int i = 0; i < n; i++)
		node[i] = i;
	for (int i = 1; i < n; i++) {
		k = n - i + 1;
		LL cur = Search (k);
		//printf("xx %d %lld\n", i, cur);
		if (cur < ans) {
			ans = cur;
		}
		if (ans == 0) return ans;
		combine[T] = true;
		for (int j = 0; j < n; j++) {
			if (j == S) continue;
			if (!combine[j]) {
				edge[S][j] += edge[T][j];
				edge[j][S] += edge[j][T];
			}
		}
	}
	return ans;
}

int main() {
	int src;
	while (scanf ("%d %d %d", &n, &m, &src) != EOF && n && m && src) {
		memset (edge, 0, sizeof (edge));
		for (int i = 0; i < m; i++) {
			int u, v, z;
			scanf ("%d %d %d", &u, &v, &z);
			u--; v--;
			edge[u][v] += z;
			edge[v][u] += z;
		}
		printf ("%lld\n", StoerWagner (n));
	}
	return 0;
}
