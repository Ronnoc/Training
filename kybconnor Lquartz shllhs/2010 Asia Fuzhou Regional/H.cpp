//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 1050
using namespace std;
pair<int,int>a[N];
int dp[4000];
bool cmp (pair<int,int>x,pair<int,int>y) {
	if (x.second == y.second) return x.first<y.first;
	return x.second<y.second;
}
int main() {
	int n,i,j;
	while (scanf ("%d",&n) &&n) {
		for (i = 1; i<=n; i++) {
			scanf ("%d%d",&a[i].first,&a[i].second);
			a[i].first*=2;
			a[i].second*=2;
		}
		sort (a+1,a+n+1,cmp);
		memset (dp,-1,sizeof (dp));
		for (i = 0; i<=3015; i++) dp[i] = 0;
		for (i = 1; i<=n; i++) {
			for (j = 3015; j>=0; j--) {
				//if(j>0)dp[j] = max(dp[j],dp[j-1]);
				if (a[i].first<j&&a[i].second>j) {
					dp[j] = max (dp[j],1);
					if (j>=10&&dp[j-10]!=-1) dp[j] = max (dp[j],dp[j-10]+1);
				}
			}
		}
		int ans = 0;
		for (i = 0; i<=3015; i++) {
			ans = max (ans,dp[i]);
		}
		printf ("%d\n",ans);
	}
	return 0;
}
