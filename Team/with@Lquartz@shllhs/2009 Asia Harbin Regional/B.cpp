#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//Lquartz
#include <vector>
using namespace std;
#define N 101000
#define INF (1 << 10)
int n, m, t;
int pre[N], x[N], a[N], dp[N];

int main() {
	while (scanf ("%d", &n) != EOF && n) {
		memset (x, 0, sizeof (x));
		for (int i = 1; i<= n; i++) {
			scanf ("%d", &a[i]);
			pre[i] = x[a[i]];
			x[a[i]] = i;
		}
		memset (dp, 0, sizeof (dp));
		for (int i = n; i > 0; i--) {
			dp[i-1] = max (dp[i], dp[i-1]);
			if (pre[i] != 0)
				dp[pre[i]] = max (dp[pre[i]], dp[i] + (a[i] == 999 ? 3 : 1));
		}
		int dmax = 0;
		printf ("%d\n", dp[0]);
	}
	return 0;
}
