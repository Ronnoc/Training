#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define OP begin()
#define ED end()
#define BB second
#define AA first
#define SZ size()
typedef pair<int,int> PII;
typedef long long LL;
const double PI = acos(-1.);
const double eps = 1e-8;
const LL MOD = 1000000007;
LL dp[105][105];
LL S[205][205];
int main(){
	freopen("treasures.in","r",stdin);
	int i,j,T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		int n,m,z;
		int qx,qy;
		scanf("%d%d%d%d%d",&n,&m,&z,&qx,&qy);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%I64d",&dp[i][j]);
		for(int t=1;t<z;t++){		//dis <=t
			for(i=0;i<=n+m;i++)
				for(j=0;j<=n+m;j++)
					S[i][j]=0;
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					S[i+j-1][i-j+m]=dp[i][j];
			for(i=0;i<=n+m;i++)
				for(j=1;j<=n+m;j++)
					S[i][j]+=S[i][j-1];
			for(i=1;i<=n+m;i++)
				for(j=0;j<=n+m;j++)
					S[i][j]+=S[i-1][j];
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++){
					int x=i+j-1;
					int y=i-j+m;
					LL &T=dp[i][j];
					T= S[min(x+t,n+m)][min(y+t,n+m)];
					T+=S[max(x-t-1,0)][max(y-t-1,0)];
					T-=S[min(x+t,n+m)][max(y-t-1,0)];
					T-=S[max(x-t-1,0)][min(y+t,n+m)];
					T=(T%MOD+MOD)%MOD;
				}
		}
		printf("Case %d: %I64d\n",CA,dp[qx][qy]);
	}
	return 0;
}
