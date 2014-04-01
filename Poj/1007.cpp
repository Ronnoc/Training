#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;
vector<int>L;
int mp[6][6], map[6][6];
int n, m, b;
int ch[20];
int ans, up;
bool check (int t) {
	int  i, j;
	for (i = 1; i < t; i++) if (ch[i] == ch[t]) return 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			mp[i][j] = map[i][j];
	for (i = 1; i <= t; i++)
		mp[L[ch[i]] / 10][L[ch[i]] % 10] = 2;
	for (i = 1; i <= t; i++) {
		int x = L[ch[i]] / 10;
		int y = L[ch[i]] % 10;
		int flag = 0;
		for (j = 1; j + y < m; j++) {
			if (!flag && mp[x][j + y]) flag = 1;
			else if (flag && mp[x][j + y] == 2) return 0;
			else if (flag && mp[x][j + y]==1) break;
		} flag = 0;
		for (j = 1; j + x < n; j++) {
			if (!flag && mp[x + j][y]) flag = 1;
			else if (flag && mp[x + j][y] == 2) return 0;
			else if (flag && mp[x + j][y]==1) break;
		} flag = 0;
		for (j = 1; y - j >= 0; j++) {
			if (!flag && mp[x][y - j]) flag = 1;
			else if (flag && mp[x][y - j] == 2) return 0;
			else if (flag && mp[x][y - j]==1) break;
		} flag = 0;
		for (j = 1; x - j >= 0; j++) {
			if (!flag && mp[x - j][y]) flag = 1;
			else if (flag && mp[x - j][y] == 2) return 0;
			else if (flag && mp[x - j][y]==1) break;
		}
	}
	return 1;
}
void dfs (int t) {
	int i;
	for (i = ch[t - 1]; i < L.size(); i++) {
		ch[t] = i;
		if (check (t)) {
			ans = max (ans, t);
			dfs (t + 1);
		}
	}
}
int main() {
	while (scanf ("%d%d%d", &n, &m, &b) != EOF) {
		int i, j, x, y;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				map[i][j] = 0;
		for (i = 1; i <= b; i++) {
			scanf ("%d%d", &x, &y);
			map[x][y] = 1;
		}
		L.clear();
		for (i = 0; i < n; i++) for (j = 0; j < m; j++)
				if (map[i][j] == 0) L.push_back (i * 10 + j);
		ans = 0;
		ch[0] = 0;
		dfs (1);
		printf ("%d\n", ans);
	}
	return 0;
}
