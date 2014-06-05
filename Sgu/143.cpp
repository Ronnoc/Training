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
const int MOD = 2000000007;
int dp[16005][2];
vector<int>G[16005];
int n;
int w[16005];
void dfsdp(int u,int f){
	int i,v;
	dp[u][0]=-MOD;
	dp[u][1]=w[u];
	for(i=0;i<G[u].SZ;i++){
		int v=G[u][i];
		if(v==f)continue;
		dfsdp(v,u);
		cmax(dp[u][0],dp[v][0]);
		cmax(dp[u][0],dp[v][1]);
		cmax(dp[u][1],dp[u][1]+dp[v][1]);
	}
}
int main(){
	int i,j,u,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++)G[i].clear();
	for(i=1;i<=n;i++)scanf("%d",&w[i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].PB(v);
		G[v].PB(u);
	}
	dfsdp(1,-1);
	int ans=-MOD;
	for(i=1;i<=n;i++)cmax(ans,dp[i][0]);
	for(i=1;i<=n;i++)cmax(ans,dp[i][1]);
	printf("%d\n",ans);
	return 0;
}
