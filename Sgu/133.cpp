#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 40000
int BI[MAX + 10];
int LB (int x) {
	return x & (-x);
	}
int get_sum (int x) {
	int ret = 0;
	for (; x; x -= LB (x)) ret += BI[x];
	return ret;
	}
void update (int x, int a) {
	for (; x < MAX; x += LB (x)) BI[x] += a;
	}
vector<int>Z;
vector<int>::iterator iter;
int BF (int x) {
	iter = lower_bound (Z.begin(), Z.end(), x);
	return iter - Z.begin() + 2;
	}
int solve() {
	vector< pair<int, int> >L;
	L.clear();
	memset (BI, 0, sizeof (BI));
	int n, i, x, y, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x >> y;
		Z.push_back (y);
		L.push_back (make_pair (x, y));
		}
	sort (Z.begin(), Z.end());
	iter = unique (Z.begin(), Z.end());
	Z.erase (iter, Z.end());
	sort (L.begin(), L.end());
	int res = 0;
	for (i = 0; i < L.size(); i=j) {
		x = L[i].first;
		y = L[i].second;
		j = i;
		while (L[j].first == x) j++;
		for (k = i; k < j; k++) {
			int tot = get_sum (BF (y));
			if (tot != i) {
				res++;
//				cout << L[k].first << " " << L[k].second << endl;
				}
			}
		for (k = i; k < j; k++)
			update (BF (L[k].second), 1);
		}
	return res;
	}
int main() {
#ifndef ONLINE_JUDGE
#endif
	cout << solve() << endl;
	return 0;
	}
