//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define inf 1<<30
using namespace std;
int p[15],v[15][15],b[15][15];
int bn[2050],fn[2050][15];
int dp[15][2050];
int main() {
	int n,m,i,j,k;
	while (scanf ("%d%d",&n,&m) &&n&&m) {
		for (i = 1; i<=m; i++) scanf ("%d",&p[i]);
		for (i = 0; i<n; i++)
			for (j = 1; j<=m; j++)
				scanf ("%d",&v[i][j]);
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				scanf ("%d",&b[i][j]);
		memset (fn,0,sizeof (fn));
		for (i = 0; i< (1<<n); i++) {
			bn[i] = 0;
			for (j = 0; j<n; j++) {
				for (k = j+1; k<n; k++) {
					if ( (i& (1<<j)) && (i& (1<<k))) bn[i]+=b[j][k];
				}
				for (k = 1; k<=m; k++) {
					if (i& (1<<j)) fn[i][k]+=v[j][k];
				}
			}
		}
		for (i = 0; i<=m; i++)
			for (j = 0; j<= (1<<n); j++)
				dp[i][j] = -inf;
		dp[0][ (1<<n)-1] = 0;
		for (i = 0; i<m; i++) {
			for (j = 0; j< (1<<n); j++) {
				if (dp[i][j] == -inf) continue;
				for (k = j; k; k = (k-1) &j) {
					dp[i+1][k] = max (dp[i+1][k],dp[i][j]+bn[k]+fn[k][i+1]-p[i+1]*__builtin_popcount (k));
				}
				dp[i+1][0] = max (dp[i+1][0],dp[i][j]);
			}
		}
		int ans = -inf;
		for (i = 0; i< (1<<n); i++)
			ans = max (ans,dp[m][i]);
		if (ans<=0) printf ("STAY HOME\n");
		else printf ("%d\n",ans);
	}
	return 0;
}
