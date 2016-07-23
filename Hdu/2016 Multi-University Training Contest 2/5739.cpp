#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int N = 100005;
vector<int>G[N];
int dfn[N],low[N],timestamp,ins[N];
stack<int>sta;
LL dp[N];
int w[N],belong[N],nson[N],fa[N];
void tarjan(int u,int root){
	dfn[u]=low[u]=++timestamp;
	belong[u]=root;
	sta.push(u);ins[u]=1;
	dp[u]=w[u];
	nson[u]=1;
	rep(i,0,sz(G[u])){
		int v=G[u][i];
		if(!dfn[v]){
			fa[v]=u;
			tarjan(v,root);
			dp[u]=(dp[u]*dp[v])%MOD;
			nson[u]+=nson[v];
			cmin(low[u],low[v]);
		}else if(ins[v])
			cmin(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int v;
		do{
			v=sta.top();
			sta.pop();
			ins[v]=0;
		}while(u!=v);
	}
}

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n)scanf("%d",&w[i]);
	rep(i,0,n)G[i].clear(),low[i]=dfn[i]=ins[i]=0,fa[i]=-1;
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].PB(v),G[v].PB(u);
	}
	timestamp=0;
	LL all=0;
	rep(i,0,n)if(!dfn[i]){
		tarjan(i,i);
		all+=dp[i];
	}
	all%=MOD;
	LL ans=0;
	rep(u,0,n)ins[u]=-1;
	rep(u,0,n){
		LL add=all-dp[belong[u]];
		if(u==belong[u]){
			rep(i,0,sz(G[u])){
				int v=G[u][i];
				if(fa[v]==u&&ins[v]!=u){
					ins[v]=u;
					add+=dp[v];
				}
			}
		}else {
			LL out=dp[belong[u]]*modPow(w[u],MOD-2,MOD)%MOD;
			rep(i,0,sz(G[u])){
				int v=G[u][i];
				if(fa[v]==u&&ins[v]!=u){
					ins[v]=u;
					if(dfn[u]<=low[v]){
						add+=dp[v];
						out=out*modPow(dp[v],MOD-2,MOD)%MOD;
					}
				}
			}
			add+=out;
		}
		//cout<<u<<" "<<add<<"\n";
		add%=MOD;
		ans+=(u+1LL)*add%MOD;
	}
	ans=ans%MOD+MOD;
	printf("%d\n",(int)(ans%MOD));
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}
/*
1
10 10
433 660 320 17 292 919 172 91 666 575
9 1
9 5
6 7
9 5
9 7
2 4
6 4
10 7
2 10
6 1

0 931119685
1 480568055
2 174642912
3 716155876
4 332790286
5 125326465
6 53341358
7 174643141
8 875875769
9 168999791
40132587
*/