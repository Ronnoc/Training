//Lquartz
//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define N 310
#define M 80100
#define LEN 100100
#define INF (1210000000)
#define eINF (1e6)
#define CLRINF 0x3f
#define EPS 1e-10
#define STEP 20
#define KIND 26
#define SYSTEM 2
#define clr(a,b) memset(a, b, sizeof(a))
#define PB push_back
#define A first
#define B second

typedef long long LL;
typedef vector < int > vecI;
typedef set < int > setI;
typedef stack < int > staI;
typedef queue < int > queI;
typedef pair < int, int > pairII;
typedef set < pairII > setII;
typedef map < string, int > mapSI;
typedef map < int, int > mapII;
/*SAP*/

struct node {
	int u, v, c, next;
} edge[M];
struct point {
	int x, y, z, l, f;
} pts[N];
int g[N*N];
int last[N], tot;
int n, S, T;
int dist[N][N];

void addedge (int s, int t, int v) {
	edge[tot].u = s, edge[tot].v = t, edge[tot].c = v;
	edge[tot].next = last[s], last[s] = tot ++ ;
	edge[tot].u = t, edge[tot].v = s, edge[tot].c = 0;
	edge[tot].next = last[t], last[t] = tot ++ ;
}
int dis[N], cur[N], gap[N], pre[N];
int SAP (int s, int t, int n) {
	memset (dis, 0, sizeof (dis));
	memset (cur, 0, sizeof (cur));
	for (int i = 0; i < n; i ++)
		cur[i] = last[i];
	memset (gap, 0, sizeof (gap));
	int v = s, maxflow = 0;
	gap[0] = n;
	while (dis[s] <= n) {
		bool flag = false;
		for (int i = cur[v]; i != -1; i = edge[i].next)
			if (edge[i].c > 0 && dis[v] == dis[edge[i].v] + 1) {
				flag = true;
				pre[edge[i].v] = v;
				cur[v] = i;
				v = edge[i].v;
				break;
			}
		if (flag) {
			if (v == t) {
				int det = INF;
				for (int i = v; i != s; i = pre[i])
					det = min (det, edge[cur[pre[i]]].c);
				for (int i = v; i != s; i = pre[i]) {
					edge[cur[pre[i]]].c -= det;
					edge[cur[pre[i]] ^ 1].c += det;
				}
				maxflow += det;
				v = s;
			}
		} else {
			int mind = n;
			for (int i = last[v]; i != -1; i = edge[i].next)
				if (edge[i].c > 0 && dis[edge[i].v] < mind) {
					mind = dis[edge[i].v];
					cur[v] = i;
				}
			if ( (-- gap[dis[v]]) == 0) break;
			gap[dis[v] = mind + 1] ++ ;
			if (v != s) v = pre[v];
		}
	}
	return maxflow;
}

void makegraph (int lab) {
	int d = g[lab];
	//cout << lab << " " << d << endl;
	memset (last, -1, sizeof (last));
	tot = 0;
	for (int i = 1; i <= n; i++) {
		addedge (S, i, pts[i].f);
		addedge (i, i + n, pts[i].l);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (d >= dist[i][j]) {
				addedge (i + n, j, INF);
				//cout << "YY " << i << " " << j << endl;
			}
		}
}

int main() {
	while (scanf ("%d", &n) != EOF) {
		int sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d%d%d%d%d", & (pts[i].x),& (pts[i].y),& (pts[i].z),& (pts[i].f),& (pts[i].l));
			sum += pts[i].f;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				int d = (pts[i].x - pts[j].x) * (pts[i].x - pts[j].x) +
								(pts[i].y - pts[j].y) * (pts[i].y - pts[j].y) +
								(pts[i].z - pts[j].z) * (pts[i].z - pts[j].z) ;
				dist[i][j] = d;
				g[cnt++] = d;
			}
		g[cnt++] = 0;
		sort (g, g + cnt);
		
		S = 0; T = 1;
		makegraph (cnt-1);
		if (sum > SAP (S, T, 2*n +10)) {
			printf ("-1\n");
			continue;
		}
		int l = 0, r = cnt - 1, mid;
		while (l != r) {
			mid = (l + r) / 2;
			makegraph (mid);
			if (sum == SAP (S, T, 2*n + 3)) {
				r = mid;
			} else {
				l = mid+1;
			}
			//cout << "xx " << mid << endl;
		}
		int ans = g[r];
		printf ("%.7lf\n", sqrt (ans));
	}
	return 0;
}
