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
#define NAME ""
#define ppt(x) __builtin_popcount(x)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
vector<int>G[22];
vector<PII>E;
int g[22][22];
int ne[1<<15];
int n,m;
LL cnt[1<<15];
LL dp[1<<15][16];
LL two[333];
bool vis[1<<15];
int solve(int mk,int lim);
void build(int mk){
	if(vis[mk])return;
	vis[mk]=1;
	if(mk==0)return;
	int ppt=__builtin_popcount(mk);
	int i,u=__builtin_ctz(mk);
	int mask=mk^(1<<u);
	int sub=mask;
	dp[mk][ppt]=cnt[mk];
	do{
		int now=sub|(1<<u);
		int rem=mk^now;
		int len=ppt(now);
		for(i=1;i<=len&&i<ppt;i++)
			dp[mk][len]+=cnt[now]*solve(rem,i)%MOD;
		for(i=len+1;i<ppt;i++)
			dp[mk][i]+=cnt[now]*solve(rem,i)%MOD;
		sub=(sub-1)&mask;
	}while(sub!=mask);
	for(i=1;i<=ppt;i++)
		dp[mk][i]=(dp[mk][i]%MOD+MOD)%MOD;
}
int solve(int mk,int lim){
	build(mk);
	return dp[mk][lim];
}
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int u,v;
	for(two[0]=i=1;i<=300;i++)two[i]=two[i-1]*2%MOD;
	while(~scanf("%d%d",&n,&m)){
		E.clear(),memset(g,0,sizeof g),memset(ne,0,sizeof ne),memset(vis,0,sizeof vis);
		for(i=0;i<=n;i++)G[i].clear();
		for(i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			u--,v--;
			if(u>v)swap(u,v);
			G[u].PB(v);
			G[v].PB(u);
			g[u][v]=g[v][u]=1;
			E.PB(MP(u,v));
			int mask=((1<<n)-1)^(1<<u)^(1<<v);
			int sub=mask;
			do{
				ne[sub|(1<<u)|(1<<v)]++;
				sub=(sub-1)&mask;
			}while(sub!=mask);
		}
		for(int mk=1;mk<1<<n;mk++){
			vector<int>W;
			for(j=0;j<n;j++)if(mk>>j&1)W.PB(j);
			u=W[0];
			cnt[mk]=two[ne[mk]];
			int mask=mk^(1<<u);
			int sub=mask;
			do{
				int now=sub|(1<<u);
				if(now!=mk)
					cnt[mk]-=cnt[now]*two[ne[mk^now]]%MOD;
				sub=(sub-1)&mask;
			}while(sub!=mask);
			cnt[mk]%=MOD;
			cnt[mk]+=MOD;
			cnt[mk]%=MOD;
		}
		memset(dp,0,sizeof dp);
		for(k=1;k<=n;k++)
			printf("%d\n",solve((1<<n)-1,k));
	}
	return 0;
}
