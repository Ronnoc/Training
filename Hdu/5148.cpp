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
const double PI=acos( -1. );
const LL MOD = 1000000007;

vector<PII>G[2005];
LL dp[2005][55];
int K,n;
void get_dp(int u,int f){
	int i,j;
	for(i=0;i<G[u].SZ;i++){
		int v=G[u][i].AA;
		if(v==f)continue;
		get_dp(v,u);
	}
	for(i=1;i<=K;i++)
		dp[u][i]=1LL<<61;
	dp[u][1]=0;
	for(int z=0;z<G[u].SZ;z++){
		int v=G[u][z].AA;
		if(v==f)continue;
		LL w=2LL*G[u][z].BB,f[55];
		for(i=1;i<=K;i++)f[i]=dp[u][i];
		for(i=1;i<=K;i++)if(f[i]!=1LL<<61)
			for(j=1;j+i<=K;j++)if(dp[v][j]!=1LL<<61){
				//cerr<<u<<","<<i+j<<" f"<<i<<" "<<v<<","<<j<<" +"<<w<<"*"<<j*(K-j)<<"\n";
				cmin(dp[u][i+j],f[i]+dp[v][j]+w*j*(K-j));
			}
		//cerr<<u<<" "<<v<<": ";
		//for(i=1;i<=K;i++)if(dp[u][i]!=1LL<<61)
		//	cerr<<dp[u][i]<<" ";
		//cerr<<"\n";
	}
}
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--){
		scanf("%d%d",&n,&K);
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			G[u].PB(MP(v,w));
			G[v].PB(MP(u,w));
		}
		get_dp(1,-1);
		LL ans=1LL<<61;
		for(i=1;i<=n;i++)cmin(ans,dp[i][K]);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
2
2 2
1 2 1
3 3
1 2 1
2 3 2
*/
