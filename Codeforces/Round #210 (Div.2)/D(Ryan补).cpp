#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()

typedef long long LL;
typedef pair<int, int> PII;
LL a[2222], dp[2010], n, k;
const LL INF = 2000000010LL;
bool check (LL d) {
	LL i,j,ans;
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		dp[i]=i-1;
		for(j=1;j<i;j++)
		{
			if(a[i]-a[j]>d*(i-j) || a[j]-a[i]>d*(i-j))continue;
			dp[i]=min(dp[j]+(i-j-1),dp[i]);
		}
	}
	for(i=1;i<=n;i++)
		if(dp[i]+n-i<=k)return 1;
	return 0;
}
void solve() {
	while (~scanf ("%I64d%I64d", &n, &k)) {
		int i;
		for (i = 1; i <= n; i++) scanf ("%I64d", &a[i]);
		LL p = INF, q = -INF;
		for (i = 1; i <= n; i++) if (a[i] > q) q = a[i];
		for (i = 1; i <= n; i++) if (a[i] < p) p = a[i];
		LL l = 0, r = q - p;
		LL ans;
		while (l <= r) {
			if (r - l <= 1) {
				if (check (l)) ans = l;
				else ans = r;
				break;
			}
			LL mid = (l + r) / 2;//l/2+r/2+(l&1+r&1)/2;
			if (check (mid)) r = mid;
			else l = mid;
		}
		printf ("%I64d\n", ans);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
/*
5 2
4 7 4 7 4
3 1
-100 0 100
6 3
1 2 3 7 8 9
*/
