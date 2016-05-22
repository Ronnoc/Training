//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#define inf 0x7f7f7f7f
using namespace std;
int dp[2][105][10][1<<9];
int a[105],hash[105],h[105],num[105];
int main() {
	int n,m,i,j,k,s,cas = 1;
	while (scanf ("%d%d",&n,&m) &&n&&m) {
		int cnt = 0;
		memset (num,0,sizeof (num));
		memset (hash,0,sizeof (hash));
		for (i = 1; i<=n; i++) {
			scanf ("%d",&a[i]);
			if (!hash[a[i]]) {
				hash[a[i]] = 1;
				h[a[i]] = ++cnt;
			}
			num[h[a[i]]]++;
		}
		memset (dp[0],0x7f,sizeof (dp[0]));
		dp[0][0][0][0] = 0;
		for (i = 0; i<n; i++) {
			int x = i&1,y = 1- (i&1);
			memset (dp[y],0x7f,sizeof (dp[y]));
			for (j = 0; j<=m&&j<=i; j++)
				for (k = 0; k<=cnt; k++)
					for (s = 0; s<1<<cnt; s++) {
						if (dp[x][j][k][s]==inf) continue;
						int kk = h[a[i+1]];
						if (kk == k) dp[y][j][kk][s] = min (dp[y][j][kk][s],dp[x][j][k][s]);
						else dp[y][j][kk][s| (1<< (kk-1))] = min (dp[y][j][kk][s| (1<< (kk-1))],dp[x][j][k][s]+1);
						if (j!=m) dp[y][j+1][k][s] = min (dp[y][j+1][k][s],dp[x][j][k][s]);
					}
		}
		int ans = 1<<20;
		for (j = 0; j<=m; j++)
			for (k = 0; k<=cnt; k++)
				for (s = 0; s<1<<cnt; s++) {
					int ret = dp[n&1][j][k][s];
					if (ret == inf) continue;
					for (i = 1; i<=cnt; i++)
						if ( (s& (1<< (i-1))) == 0) ret+=num[i];
					ans = min (ans,ret);
				}
		printf ("Case %d: %d\n\n",cas++,ans);
	}
	return 0;
}
