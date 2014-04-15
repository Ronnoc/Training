#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int ch[23];
int n, m;
vector<int>N[23];
vector<int>B[23];
int res;
int check() {
	int local[23];
	int i, j;
	for (i = 1; i <= m; i++) local[ch[i]] = i;
	int ret = 1;
	for (i = 1; i <= n; i++) {
		int xmin = 23, xmax = -1;
		for (j = 0; j < N[i].size(); j++) xmin = min (xmin, local[N[i][j]]);
		for (j = 0; j < N[i].size(); j++) xmax = max (xmax, local[N[i][j]]);
		ret = max (ret, xmax - xmin + 1);
		}
	return ret;
	}
int IDA (int t, int x) {
	ch[t] = x;
	int i, j, k;
	int did[23];
	for (i = 1; i <= m; i++) did[i] = 0;
	for (i = 1; i <= t; i++) did[ch[i]] = 1;
	for (j = t + 1; j <= m; j++) {
		int ok = 0;
		for (i = 0; !ok && i < B[ch[j - 1]].size(); i++) {
			int q = B[ch[j - 1]][i];
			for (k = 0; !ok && k < N[q].size(); k++) 
				if (!did[N[q][k]]) {
					ok = 1;
					did[N[q][k]] = 1;
					ch[j] = N[q][k];
					}
			}
		if (!ok) 
			for (i = 1; i <= m; i++) 
				if (!did[i]) {
					ch[j] = i;
					did[i] = 1;
					break;
					}
		}
	return check();
	}
int get_best (int t, int x) {
	ch[t] = x;
	int local[23];
	int i, j;
	for (i = 1; i <= m; i++) local[i] = t + 1;
	for (i = 1; i <= t; i++) local[ch[i]] = i;
	int match[23];
	for (i = 1; i <= m; i++) match[i] = 23;
	int ret = 1;
	vector<int >L;
	L.clear();
	for (i = 1; i <= n; i++) {
		int xmin = 23, xmax = -1;
		for (j = 0; j < N[i].size(); j++) xmin = min (xmin, local[N[i][j]]);
		for (j = 0; j < N[i].size(); j++) xmax = max (xmax, local[N[i][j]]);
		for (j = 0; j < N[i].size(); j++)
			if (local[N[i][j]] == t + 1)
				match[N[i][j]] = min (match[N[i][j]], xmin);
		ret = max (ret, xmax - xmin + 1);
		}
	for (i = 1; i <= m; i++)
		if (match[i] < t + 1)
			L.push_back (match[i]);
	sort (L.begin(), L.end());
	int cut = 1;
	for (i = 0; i < L.size(); i++)
		cut = max (cut, t + 1 + i - L[i] + 1);
	return max (ret, cut);
	return ret;
	}
bool can (int t, int x) {
	int i;
	for (i = 1; i < t; i++) if (ch[i] == x) return 0;
	return 1;
	}
void dfs (int t) {
	if (t > m) res = min (res, check());
	else {
		int ida[23];
		int i, j;
		for (i = 1; i <= m; i++) ida[i] = 23;
		for (i = 1; i <= m; i++)
			if (can (t, i))
				ida[i] = get_best (t, i);	//neerly impossible best
		vector<pair<int, int> >L;
		for (i = 1; i <= m; i++)
			if (ida[i] != 23) L.push_back (make_pair (ida[i], i));
		sort (L.begin(), L.end());
		for (i = 0; i < L.size(); i++)
			if (get_best (t, L[i].second) < res) {
				ch[t] = L[i].second;
				dfs (t + 1);
				}
		}
	}
int main() {
	int i, j;
	while (cin >> m >> n) {
		for (i = 1; i <= n; i++) N[i].clear();
		for (j = 1; j <= m; j++) B[j].clear();
		for (j = 1; j <= m; j++) 
			for (i = 1; i <= n; i++) {
				int x;
				cin >> x;
				if (x) {
					B[j].push_back (i);
					N[i].push_back (j);
					}
				}
		res = IDA (1, 1);
		dfs (0);
		cout << res - 1 << endl;
		}
	return 0;
	}
