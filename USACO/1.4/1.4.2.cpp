/*
ID: kybconn1
PROG: packrec
LANG: C++
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<pair<int, int> >ans[10001];
int x[5], y[5];
int dx[5], dy[5], ux[5], uy[5];
int mp[201][201];
int sum[201][201];
int nxt[201];
bool dfs (int cnt, int did, int l, int r) {
	int i, j, k;
	int Stack = 1;
	if (cnt > 4) return 1;
	for (int kk = 1; kk <= 4; ++kk) {
		if (did >> kk & 1) continue;
		if (Stack) {
			for (i = 1; i <= l; ++i) for (j = 1; j <= r; ++j) mp[i][j] = 1;
			for (k = 1; k < cnt; ++k)
				for (i = dx[k]; i <= ux[k]; ++i) for (j = dy[k]; j <= uy[k]; ++j)
						mp[i][j] = 0;
			for (i = 1; i <= l; ++i) nxt[i] = 1;
			for (k = 1; k < cnt; ++k) for (i = dx[k]; i <= ux[k]; ++i)
					if (dx[k] == 1) nxt[i] = max (nxt[i], uy[k] + 1);
			for (i = 1; i <= l; ++i)
				for (j = 1; j <= r; ++j)
					sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mp[i][j];
			Stack = 0;
		}
		int p[2], q[2], z, pro = x[kk] * y[kk];
		p[0] = x[kk], q[0] = y[kk];
		p[1] = y[kk], q[1] = x[kk];
		int up = (x[kk] == y[kk]) ? 1 : 2, ii, jj;
		for (z = 0; z < up; ++z)
			for (i = 1; i + p[z] - 1 <= l; ++i) {
				int flag = 0;
				ii = i + p[z] - 1;
				for (j = nxt[i]; j + q[z] - 1 <= r; ++j) {
					jj = j + q[z] - 1;
					if (sum[ii][jj] - pro + sum[i - 1][j - 1] == sum[i - 1][jj] + sum[ii][j - 1]) {
						dx[cnt] = i, dy[cnt] = j;
						ux[cnt] = ii, uy[cnt] = jj;
						if (dfs (cnt + 1, did | (1 << kk), l, r)) return 1;
						flag = 1;
						Stack = 1;
						break;
					}
				}
				if (flag) break;
			}
	}
	return 0;
}
bool can (int l, int r) {
	for (int t = 1; t <= 4; ++t) {
		if (x[t] > l || y[t] > r) continue;
		ux[1] = x[t], uy[1] = y[t];
		if (dfs (2, 1 << t, l, r)) return 1;
	}
	if (l < r) return can (r, l);
	return 0;
}
int main() {
	freopen ("packrec.in", "r", stdin);
	freopen ("packrec.out", "w", stdout);
	while (~scanf ("%d%d", &x[1], &y[1])) {
		int i, j;
		for (i = 1; i <= 200; ++i) for (j = 1; j <= 200; ++j) mp[i][j] = 1;
		for (i = 2; i <= 4; ++i) scanf ("%d%d", &x[i], &y[i]);
		int gcd = __gcd (x[1], y[1]);
		if (gcd > 1) for (i = 2; gcd > 1 && i <= 4; ++i) gcd = __gcd (y[i], __gcd (x[i], gcd));
		if (gcd > 1) for (i = 1; i <= 4; ++i) x[i] /= gcd, y[i] /= gcd;
		for (i = 1; i <= 4; ++i) if (x[i] > y[i]) swap (x[i], y[i]);
		int s = 0, len = 0, tp = 0, now = 10000, z;
		for (i = 1; i <= 4; ++i) s += x[i] * y[i];
		for (i = 1; i <= 4; ++i) tp = max (tp, x[i]);
		for (i = 1; i <= 4; ++i) len += y[i];
		now = tp * len,	dx[1] = 1, dy[1] = 1;
		for (i = tp; i < len; ++i)
			for (j = max (i, (s % i == 0) ? s / i : s / i + 1); (z = j * i) <= now; ++j)
				if (can (i, j)) {ans[z].push_back (make_pair (i, j)); now = min (now, z); break;}
		printf ("%d\n", now * gcd * gcd);
		for (j = 0; j < ans[now].size(); ++j)
			printf ("%d %d\n", ans[now][j].first * gcd, ans[now][j].second * gcd);
	}
	return 0;
}
