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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const int MOD = 1000000007;
vector<int>G[160005];
int n;
int dp[160005];
int ans[160005];
void dfsdp(int u,int f){
	dp[u]=1;
	for(int i=0;i<G[u].SZ;i++){
		int v=G[u][i];
		if(v==f)continue;
		dfsdp(v,u);
		dp[u]+=dp[v];
	}
}
void solve(int u,int f,int d){
	ans[u]=d;
	for(int i=0;i<G[u].SZ;i++){
		int v=G[u][i];
		if(v==f)continue;
		solve(v,u,dp[u]-dp[v]+d);
		cmax(ans[u],dp[v]);
	}
}
int main(){
	int i,j,u,v;
//	while(~){
	scanf("%d",&n);
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			G[u].PB(v);
			G[v].PB(u);
		}
		dfsdp(1,-1);
		solve(1,-1,0);
		int now=n,cnt=0;
		for(i=1;i<=n;i++)cmin(now,ans[i]);
		for(i=1;i<=n;i++)if(ans[i]==now)cnt++;
		printf("%d %d\n",now,cnt);
		vector<int>L;
		for(i=1;i<=n;i++)if(ans[i]==now)L.PB(i);
		SORT(L);
		printf("%d",L[0]);
		for(i=1;i<L.SZ;i++)printf(" %d",L[i]);
		puts("");
//	}
	return 0;
}
