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

vector<int>G[2005];
int w[2005];
bool v[2005];
vector<PII>L;
int n,d;
LL dp[2005];
LL dfs(int r,int u,int f=-1) {
	int i,v;
	dp[u]=1;
	for(i=0; i<G[u].SZ; i++) {
		v=G[u][i];
		if(v==f)continue;
		if(w[v]>w[r])continue;
		if(w[r]-w[v]>d)continue;
		if(::v[v])continue;
		dfs(r,v,u);
		dp[u]*=dp[v]+1;
		if(dp[u]>=MOD)dp[u]%=MOD;
	}
	return dp[u];
}
int fa[115];
int getfa(int u) {return fa[u]==u?u:fa[u]=getfa(fa[u]);}
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	while(~scanf("%d%d",&d,&n)) {
		L.clear();
		for(i=1; i<=n; i++)scanf("%d",&w[i]),G[i].clear(),v[i]=0;
		for(i=1; i<n; i++) {
			scanf("%d%d",&k,&j);
			G[j].PB(k);
			G[k].PB(j);
		}
		L.PB(MP(-1,-1));
		for(i=1; i<=n; i++)L.PB(MP(w[i],i));
		sort(L.OP,L.ED);
		LL ans=0;
		for(i=1; i<L.SZ; i++) {
			if(L[i].AA!=L[i-1].AA)for(j=1; j<=n; j++)v[j]=0;
			v[L[i].BB]=1;
			LL add=dfs(L[i].BB,L[i].BB);
//			cerr<<L[i].BB<<"~"<<add<<"\n";
			ans+=add;
			if(ans>=MOD)ans-=MOD;
		}
		cout<<ans%MOD<<"\n";
//		map<int,int>MA;
//		for(i=1; i<1<<n; i++) {
//			for(j=0; j<n; j++)fa[j]=j;
//			for(j=0; j<n; j++)if(i>>j&1)
//					for(k=0; k<G[j+1].SZ; k++)if(i>>(G[j+1][k]-1)&1)
//							fa[getfa(j)]=getfa(G[j+1][k]-1);
//			set<int>S;
//			vector<PII>L;
//			for(j=0; j<n; j++)if(i>>j&1)S.insert(getfa(j)),L.PB(MP(w[j+1],-j-1));
//			if(S.SZ==1) {
//				sort(L.OP,L.ED);
//				if(L[L.SZ-1].AA-L[0].AA<=d)MA[-L[L.SZ-1].BB]++;
//			}
//		}
//		for(i=1; i<=n; i++)
//			cerr<<i<<" "<<MA[i]<<"\n";
	}
	return 0;
}
