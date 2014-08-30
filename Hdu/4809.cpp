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
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

vector<int>G[333];
LL dp[305][605][3];		//0 not this col;1 this col with odd;2 this col with even
LL tp[605][3];
int le[305],re[305];
int n;
void dfs_dp(int u,int f) {
	int i,j,k,l;
	for(i=0; i<G[u].SZ; i++) {
		int v=G[u][i];
		if(v==f)continue;
		dfs_dp(v,u);
	}
	dp[u][n][0]=2;
	dp[u][n][1]=1;
	dp[u][n][2]=0;
	le[u]=n;
	re[u]=n+1;
	for(i=0; i<G[u].SZ; i++) {
		int v=G[u][i];
		if(v==f)continue;
		memset(tp,0,sizeof tp);
		for(k=le[u];k<=re[u];k++)for(j=le[v]; j<=re[v]; j++){
			tp[j+k-n  ][0]+=dp[u][k][0]*dp[v][j][0]%MOD;
			tp[j+k-n+1][0]+=dp[u][k][0]*dp[v][j][1]%MOD;
			tp[j+k-n-1][0]+=dp[u][k][0]*dp[v][j][2]%MOD;
			tp[j+k-n  ][1]+=dp[u][k][1]*dp[v][j][0]%MOD;
			tp[j+k-n  ][2]+=dp[u][k][1]*dp[v][j][1]%MOD;
			tp[j+k-n  ][1]+=dp[u][k][1]*dp[v][j][2]%MOD;
			tp[j+k-n  ][2]+=dp[u][k][2]*dp[v][j][0]%MOD;
			tp[j+k-n  ][1]+=dp[u][k][2]*dp[v][j][1]%MOD;
			tp[j+k-n  ][2]+=dp[u][k][2]*dp[v][j][2]%MOD;
		}
		le[u]=2*n+1,re[u]=-1;
		for(j=0;j<=2*n;j++)for(k=0;k<3;k++){
			dp[u][j][k]=tp[j][k]%MOD;
			if(tp[j][k])cmax(re[u],j),cmin(le[u],j);
		}
	}
}
LL gao(LL A,int t){
	if(t<=0)return 0;
	return A*t%MOD;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T,u,v;
	while(~scanf("%d",&n)) {
		for(i=1; i<=n; i++)G[i].clear();
		memset(dp,0,sizeof dp);
		for(i=1; i<n; i++) {
			scanf("%d%d",&u,&v);
			G[u].PB(v),G[v].PB(u);
		}
		dfs_dp(1,-1);
		LL ANS=0;
		for(i=le[1];i<=re[1];i++){
			ANS+=gao(dp[1][i][0],i-n);
			ANS+=gao(dp[1][i][1],i+1-n);
			ANS+=gao(dp[1][i][2],i-1-n);
			ANS%=MOD;
		}
		ANS*=3;
		ANS%=MOD;
		printf("%d\n",(int)ANS);
	}
	return 0;
}

