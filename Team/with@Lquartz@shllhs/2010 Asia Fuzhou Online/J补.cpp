//Lquartz
/*
注意！！！INF 和dist[t]的比较来判断是否有增广路,
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
#define N 41000
#define M 401000
#define Maxm 401005
#define Maxn 41000
#define INF (1LL << 55)
struct edge {
	int u, v, next;
	LL c;
} e[Maxm];
int last[Maxn], cnt;
int n, m, S, T;
void addedge (int s, int t, LL v) {
	e[cnt].u = s, e[cnt].v = t, e[cnt].c = v;
	e[cnt].next = last[s], last[s] = cnt ++ ;
	e[cnt].u = t, e[cnt].v = s, e[cnt].c = 0;
	e[cnt].next = last[t], last[t] = cnt ++ ;
}
int dis[Maxn], cur[Maxn], gap[Maxn], pre[Maxn];
LL SAP (int s, int t, int n) {
	/*可预先加dinic的BFS减少部分时间复杂度*/
	memset (dis, 0, sizeof (dis));
	memset (cur, 0, sizeof (cur));
	for (int i = 0; i < n; i ++)
		cur[i] = last[i];
	memset (gap, 0, sizeof (gap));
	int v = s;
	LL maxflow = 0;
	gap[0] = n;
	while (dis[s] <= n) {
		bool flag = false;
		for (int i = cur[v]; i != -1; i = e[i].next)
			if (e[i].c > 0 && dis[v] == dis[e[i].v] + 1) {
				flag = true;
				pre[e[i].v] = v;
				cur[v] = i;
				v = e[i].v;
				break;
			}
		if (flag) {
			if (v == t) {
				LL det = INF;
				for (int i = v; i != s; i = pre[i])
					det = min (det, e[cur[pre[i]]].c);
				for (int i = v; i != s; i = pre[i]) {
					e[cur[pre[i]]].c -= det;
					e[cur[pre[i]] ^ 1].c += det;
				}
				maxflow += det;
				v = s;
			}
		} else {
			int mind = n;
			for (int i = last[v]; i != -1; i = e[i].next)
				if (e[i].c > 0 && dis[e[i].v] < mind) {
					mind = dis[e[i].v];
					cur[v] = i;
				}
			if ( (-- gap[dis[v]]) == 0) break;
			gap[dis[v] = mind + 1] ++ ;
			if (v != s) v = pre[v];
		}
	}
	return maxflow;
}

int Test = 0, Case = 1;
int main() {
	scanf ("%d", &Test);
	while (Test--) {
		memset (last, -1, sizeof (last));
		cnt = 0;
		scanf ("%d%d", &n, &m);
		S = 0; T = m + n + 1;
		LL sum = 0;
		for (int i = 1; i <= n; i++) {
			int l;
			scanf ("%d", &l);
			for (int j = 0; j < l; j++) {
				int x;
				scanf ("%d", &x);
				addedge (i, n + x, INF);
			}
			scanf ("%d", &l);
			addedge (S, i, l);
			sum += l;
		}
		for (int i = 1; i <= m; i++) {
			int x;
			scanf ("%d", &x);
			addedge (i + n, T, x);
		}
		sum -= SAP (S, T, T+1);
		if (sum < 0L) sum = 0L;
		printf ("Case %d: %I64d\n", Case++, sum);
	}
	return 0;
}
