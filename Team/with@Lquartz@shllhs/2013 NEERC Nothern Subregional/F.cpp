//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 1005
#define inf 0x7f7f7f7f
using namespace std;
int dp[N][60],c[N][N];
int a[N],vis[N];
void update (int x) {
	while (x<N) {
		a[x]+=1;
		x+=x&-x;
	}
}
int query (int x) {
	int ret = 0;
	while (x>=1) {
		ret+=a[x];
		x-=x&-x;
	}
	return ret;
}
int main() {
	freopen ("flight.in","r",stdin);
	freopen ("flight.out","w",stdout);
	int n,s,k,i,j,x,p,mx;
	while (scanf ("%d%d%d",&n,&s,&k) !=EOF) {
		memset (c,0,sizeof (c));
		memset (a,0,sizeof (a));
		memset (vis,0,sizeof (vis));
		mx = 0;
		for (i = 1; i<=n; i++) {
			scanf ("%d",&x);
			mx = max (mx,x);
			update (x);
			for (j = 1; j<=x; j++) c[j][x]+=query (x-1)-query (j-1);
		}
		for (i = 1; i<=s; i++) {
			for (j = i; j<=s; j++) {
				if (i!=j)
					c[i][j]+=c[i][j-1];
			}
		}
		memset (dp,0x7f,sizeof (dp));
		dp[0][0] = 0;
		for (i = 1; i<=mx; i++) {
			if (c[0][i] == -1) continue;
			dp[i][0] = min (dp[i][0],c[1][i]);
			for (j = 1; j<k; j++) {
				for (p = 1; p<i; p++) {
					if (dp[p][j-1] == inf) continue;
					dp[i][j] = min (dp[i][j],dp[p][j-1]+c[p+1][i]);
				}
			}
		}
		int ans = inf;
		for (i = 0; i<k; i++) ans = min (ans,dp[mx][i]);
		printf ("%d\n",ans);
	}
	return 0;
}
