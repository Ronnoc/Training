//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
pair<int,int>p[3500];
ll dp[2][10005];
bool cmp (pair<int,int>a,pair<int,int>b) {
	if (a.second*b.first == a.first*b.second) return a.first<b.first;
	return a.second*b.first>a.first*b.second;
}
int main() {
	int n,t,i,j;
	while (scanf ("%d%d",&n,&t) !=EOF) {
		for (i = 1; i<=n; i++) {
			int a,b;
			scanf ("%d%d",&a,&b);
			p[i] = make_pair (a,b);
		}
		sort (p+1,p+n+1,cmp);
		memset (dp,-1,sizeof (dp));
		dp[0][t] = 0;
		for (i = 0; i<n; i++) {
			for (j = t; j>=0; j--) {
				if (dp[i&1][j] == -1) continue;
				if (j-p[i+1].first>=0) dp[1- (i&1)][j-p[i+1].first] = max (dp[1- (i&1)][j-p[i+1].first],dp[i&1][j]+j*p[i+1].second);
				dp[1- (i&1)][j] = max (dp[i&1][j],dp[1- (i&1)][j]);
			}
		}
		ll ans = 0;
		for (i = 0; i<=t; i++) ans = max (ans,dp[n&1][i]);
		printf ("%lld\n",ans);
	}
	return 0;
}
