#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define INF 1000000000
#define MXN 1010
#define PB push_back
#define MP make_pair
char c[MXN];
int r[MXN], tb[MXN], tp[MXN], tbp[MXN], add[MXN];
int n, m, src, dst;
vector<pair<int, int> >G[MXN];
queue<pair<int, int> >Q;

long long dp[MXN];
int pre[MXN];
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
	int u0 = add[u] + t;
	u0 %= tbp[u];
	int v0 = add[v] + t;
	v0 %= tbp[v];
	int du = u0 < tb[u] ? tb[u] - u0 : tbp[u] - u0;
	int dv = v0 < tb[v] ? tb[v] - v0 : tbp[v] - v0;
	int dt = min (du, dv);
	if (same (u, v, t + dt)) return dt;
	int fu = u0 < tb[u] ? tbp[u] - u0 : tbp[u] + tb[u] - u0;
	int fv = v0 < tb[v] ? tbp[v] - v0 : tbp[v] + tb[v] - v0;
	dt = min (fu, fv);
	if (same (u, v, t + dt)) return dt;
	return INF;
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
	for (i = 1; i <= n; i++) {
		char ch[20];
		scanf ("%s %d%d%d%*c", ch, &r[i], &tb[i], &tp[i]);
		c[i] = ch[0];
		tbp[i] = tb[i] + tp[i];
		add[i] = (c[i] == 'B') ? tb[i] - r[i] : tbp[i] - r[i];
	}
	for (i = 1; i <= m; i++) {
		scanf ("%d%d%d", &u, &v, &d);
		G[u].PB (MP (v, d));
		G[v].PB (MP (u, d));
	}
	SPFA();
	long long ans = dp[dst];
	if (ans == INF)
	{printf ("0\n"); return 0;}
	int now = dst;
	vector<int>L;
	while (now != src)
	{now = pre[now]; L.push_back (now);}
	printf ("%lld\n", ans);
	for (i = L.size() - 1; i >= 0; i--) printf ("%d ", L[i]);
	printf ("%d\n", dst);
	return 0;
}
