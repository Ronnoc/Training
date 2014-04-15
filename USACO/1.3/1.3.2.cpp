/*
ID: kybconn1
PROG: barn1
LANG: C++
*/
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen ("barn1.in", "r", stdin);
	freopen ("barn1.out", "w", stdout);
	int m, s, c;
	int i, j, z;
	vector<int>L;
	scanf ("%d%d%d", &m, &s, &c);
	int dp[222][222];
	memset (dp, 0, sizeof (dp));
	for (i = 1; i <= c; i++) {
		scanf ("%d", &z);
		L.push_back (z);
	}
	sort (L.begin(), L.end());
	dp[0][1] = 1;
	for (i = 1; i < L.size(); i++) {
		dp[i][1] = dp[i - 1][1] + L[i] - L[i - 1];
		for (j = 2; j <= m; j++) {
			if(j>=(i+1))dp[i][j]=i+1;
			else dp[i][j]=min(dp[i-1][j]+L[i]-L[i-1],dp[i-1][j-1]+1);
		}
	}
	printf ("%d\n", dp[c - 1][m]);
	return 0;
}
