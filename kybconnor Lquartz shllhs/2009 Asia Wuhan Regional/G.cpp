//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int dp[2][2][502][52];
struct node {
	int p,h,s;
} a[305];
int main() {
	int v1,v2,n,i,j,k,q,cas = 1;
	while (scanf ("%d%d%d",&v1,&v2,&n) &&v1&&v2&&n) {
		for (i = 1; i<=n; i++) {
			scanf ("%d%d%d",&a[i].p,&a[i].h,&a[i].s);
		}
		memset (dp[0],-1,sizeof (dp[0]));
		dp[0][0][v1][v2] = 0;
		for (i = 0; i<n; i++) {
			memset (dp[1- (i&1)],-1,sizeof (dp[i- (i&1)]));
			for (j = 0; j<=v1; j++) {
				for (k = 0; k<=v2; k++) {
					for (q = 0; q<=1; q++) {
						if (dp[i&1][q][j][k] == -1) continue;
						if (q == 0) dp[1- (i&1)][1][j][k] = max (dp[1- (i&1)][1][j][k],dp[i&1][0][j][k]+a[i+1].h);
						if (a[i+1].p<=j) dp[1- (i&1)][q][j-a[i+1].p][k] = max (dp[1- (i&1)][q][j-a[i+1].p][k],dp[i&1][q][j][k]+a[i+1].h);
						if (a[i+1].p<=k) dp[1- (i&1)][q][j][k-a[i+1].p] = max (dp[1- (i&1)][q][j][k-a[i+1].p],dp[i&1][q][j][k]+a[i+1].h);
						if (a[i+1].s == 0) dp[1- (i&1)][q][j][k] = max (dp[1- (i&1)][q][j][k],dp[i&1][q][j][k]);
						
					}
				}
			}
		}
		int ans = -1;
		for (i = 0; i<=v1; i++)
			for (j = 0; j<=v2; j++)
				for (k = 0; k<=1; k++)
					ans = max (ans,dp[n&1][k][i][j]);
		printf ("Case %d: %d\n\n",cas++,ans);
	}
	return 0;
}
