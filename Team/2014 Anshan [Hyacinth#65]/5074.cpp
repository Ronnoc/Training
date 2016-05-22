#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))

int dp[105][55];
int g[55][55];
int a[105];
int main() {
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(dp,-1,sizeof dp);
		for(i=1;i<=m;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&g[i][j]);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		if(~a[1])dp[2][a[1]]=0;
		else {
			for(i=1;i<=n;i++)
				dp[2][i]=0;
		}
		for(i=2;i<=n;i++)for(j=1;j<=m;j++)if(~dp[i][j]){
			if(~a[i]){
				cmax(dp[i+1][a[i]],dp[i][j]+g[j][a[i]]);
			}else {
				for(k=1;k<=m;k++)
					cmax(dp[i+1][k],dp[i][j]+g[j][k]);
			}
		}
		int ans=-1;
		for(i=1;i<=m;i++)
			cmax(ans,dp[n+1][i]);
		printf("%d\n",ans);
	}
	return 0;
}
/*
2
5 3
83 86 77
15 93 35
86 92 49
3 3 3 1 2
10 5
36 11 68 67 29
82 30 62 23 67
35 29 2 22 58
69 67 93 56 11
42 29 73 21 19
-1 -1 5 -1 4 -1 -1 -1 4 -1

*/
