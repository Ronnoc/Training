#include <bits/stdc++.h>

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
const LL MOD = 1000000007;
int dp[10005][2];
int ep[10005][2];
int n;
vector<PII>G[10005];
void dfsdp(int u,int f){
	int i,v,d;
	dp[u][0]=0;
	for(i=0;i<G[u].SZ;i++){
		v=G[u][i].AA;
		d=G[u][i].BB;
		if(v==f)continue;
		dfsdp(v,u);
		if(dp[v][0]+d>dp[u][1])dp[u][1]=dp[v][0]+d,ep[u][1]=v;
		if(dp[u][0]<dp[u][1])swap(dp[u][0],dp[u][1]),swap(ep[u][0],ep[u][1]);
	}
}
int ans[10005];
void solve(int u,int f,int pre){
	cmax(ans[u],dp[u][0]);
	cmax(ans[u],dp[u][1]);
	cmax(ans[u],pre);
//	cout<<ans[u]<<" "<<pre<<" "<<dp[u][0]<<" "<<dp[u][1]<<" ~~~"<<u<<endl;
	int i,v,d;
	for(i=0;i<G[u].SZ;i++){
		v=G[u][i].AA;
		d=G[u][i].BB;
		if(v==f)continue;
		if(v==ep[u][0])solve(v,u,max(dp[u][1],pre)+d);
		else solve(v,u,max(dp[u][0],pre)+d);
	}
}
int main(){
	int i,j,u,v;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)G[i].clear();
		for(i=2;i<=n;i++){
			scanf("%d%d",&u,&v);
			G[u].PB(MP(i,v));
			G[i].PB(MP(u,v));
		}
		memset(dp,-1,sizeof dp);
		memset(ep,-1,sizeof ep);
		memset(ans,0,sizeof ans);
		dfsdp(1,-1);
		solve(1,-1,0);
		for(i=1;i<=n;i++)printf("%d\n",ans[i]);
	}
	return 0;
}
