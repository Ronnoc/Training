#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int MXN = 100005;
VI G[MXN];
int isleaf[MXN];
int leaves[MXN];
LL dp[MXN][3][2];
void update(LL &tp,LL w){
	if(~w){
		if(~tp)cmin(tp,w);
		else tp=w;
	}
}
void dfs(int u,int fa){
	isleaf[u]=1;
	rep(i,0,sz(G[u])){
		int v=G[u][i];
		if(v!=fa)dfs(v,u),isleaf[u]=0;
	}
	leaves[u]=isleaf[u];
	rep(i,0,sz(G[u])){
		int v=G[u][i];
		if(v!=fa)leaves[u]+=leaves[v];
	}
	if(isleaf[u]){
		dp[u][0][1]=0;
		dp[u][1][0]=0;
		return;
	}
	LL f[2][3][2];
	memset(f,-1,sizeof f);
	int x=0,y=1;
	f[x][0][0]=0;
	rep(i,0,sz(G[u])){
		int v=G[u][i];
		if(v==fa)continue;
		memset(f[y],-1,sizeof f[y]);
		rep(j,1,3)rep(k,0,2)if(~dp[v][j][k]){
			rep(p,0,3)rep(q,0,2-k)if(~f[x][p][q]){
				int jj=p+j,kk=k+q,w=dp[v][j][k]+f[x][p][q]+j;
				while(jj>=3)jj-=2;
				update(f[y][jj][kk],w);
				if(jj>=1&&kk==0)update(f[y][jj-1][kk+1],w);
				if(jj>=2)update(f[y][jj-2][kk],w);			
			}
		}
		swap(x,y);
	}
	rep(j,0,3)rep(k,0,2)dp[u][j][k]=f[x][j][k];
}
void solve(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)G[i].clear();
	rep(i,1,n+1)rep(j,0,3)rep(k,0,2)dp[i][j][k]=-1;
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].PB(v),G[v].PB(u);
	}
	if(n<=3){
		printf("%d\n",n-1);
		return;
	}
	int root;
	rep(i,1,n+1)if(sz(G[i])>1)root=i;
	dfs(root,-1);
	int kk=leaves[root]%2;
	cout<<dp[root][0][kk]<<"\n";
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}