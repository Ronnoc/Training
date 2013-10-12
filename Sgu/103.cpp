#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define INF (int)(1e9+7)
#define MXN 510
#define PB push_back
#define MP make_pair
char c[MXN];
int r[MXN], tb[MXN], tp[MXN],tbp[MXN], add[MXN];
int n, m, src, dst;
vector<pair<int, int> >G[MXN];
queue<pair<int, int> >Q;

int dp[MXN], pre[MXN];
int stt (int u, int t) {
	return (t + add[u]) % tbp[u];
}
bool same (int u, int v, int t) {
	int f1 = stt (u, t) < tb[u];
	int f2 = stt (v, t) < tb[v];
	return f1 == f2;
}

int when (int u, int v, int t) {
	if (same (u, v, t)) return 0;
	int gcd = __gcd (tbp[u], tbp[v]);
	if(gcd==0)return INF;
	int hu = tbp[v] / gcd, hv = tbp[u] / gcd;
	int u0 = stt (u, t), v0 = stt (v, t);
	int ret = INF, k, dt;
	for (k = 0; k <= hu; k++) {
		dt = max (k * tbp[u] - u0, 0);
		if (ret < dt) break;
		if (same (u, v, t + dt)) ret = min (ret, dt);
		dt = max (k * tbp[u] - u0 + tb[u], 0);
		if (ret < dt) break;
		if (same (u, v, t + dt)) ret = min (ret, dt);
	}
	for (k = 0; k <= hv; k++) {
		dt = max (k * tbp[v] - v0, 0);
		if (ret < dt) break;
		if (same (u, v, t + dt)) ret = min (ret, dt);
		dt = max (k * tbp[v] - v0 + tb[v], 0);
		if (ret < dt) break;
		if (same (u, v, t + dt)) ret = min (ret, dt);
	}
	return ret;
}

void SPFA() {
	int i, j;
	for (i = 1; i <= n; i++) dp[i] = INF;
	Q.push (MP (0, src)), dp[src] = 0;
	while (!Q.empty()) {
		int u = Q.front().second, t = Q.front().first;
		Q.pop();
		if (dp[u] < t) continue;
		for (i = 0; i < G[u].size(); i++) {
			int v = G[u][i].first, d = G[u][i].second;
			int wait = when (u, v, t);
			if (wait < INF && dp[v] > dp[u] + wait + d) {
				pre[v] = u;
				dp[v] = dp[u] + wait + d;
				Q.push (MP (dp[v], v));
			}
		}
	}
}

int main() {
	int i, j, u, v, d;
	scanf ("%d%d%d%d%*c", &src, &dst, &n, &m);
	  for (i = 1; i <= n; i++){
    char ch[20];
    scanf ("%s %d %d %d%*c", ch, &r[i], &tb[i], &tp[i]);
    c[i]=ch[0];
    }
	for (i = 1; i <= m; i++) {
		scanf ("%d%d%d", &u, &v, &d);
		G[u].PB (MP (v, d));
		G[v].PB (MP (u, d));
	}
	for (i = 1; i <= n; i++) 
		tbp[i] = tb[i] + tp[i];
	for (i = 1; i <= n; i++)
		add[i] = (c[i] == 'B') ? tb[i] - r[i] : tbp[i] - r[i];
	SPFA();
	int ans = dp[dst];
	if (ans == INF)
	{printf ("0\n"); return 0;}
	int now = dst;
	vector<int>L;
	while (now != src)
	{now = pre[now]; L.push_back (now);}
	printf ("%d\n", ans);
	for (i = L.size() - 1; i >= 0; i--) printf ("%d ", L[i]);
	printf ("%d\n", dst);
	return 0;
}
