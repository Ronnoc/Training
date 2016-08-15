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
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
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
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
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
VPII G[MXN];
int fa[MXN],cfa[MXN];
int val[MXN];
int db[MXN];//back
int fb[MXN];
int fd[MXN];
int dd[MXN][2];//down
int idd[MXN][2];
int ans[MXN];
void update(int *d,int *id,int w,int v){
	if(w>d[0]){
		d[1]=d[0],id[1]=id[0];
		d[0]=w,id[0]=v;
	}else if(w>d[1]){
		d[1]=w,id[1]=v;
	}
}
void dfsfa(int u,int ff){
	rep(i,0,sz(G[u])){
		int v=G[u][i].AA;
		if(v==ff)continue;
		int w=G[u][i].BB;
		fa[v]=u,cfa[v]=w;
		dfsfa(v,u);
	}
}
void dfsdb(int u,int ff){
	rep(i,0,sz(G[u])){
		int v=G[u][i].AA;
		if(v==ff)continue;
		dfsdb(v,u);
	}
	db[u]=val[u];
	rep(i,0,sz(G[u])){
		int v=G[u][i].AA;
		if(v==ff)continue;
		cmax(db[u],db[u]+db[v]-2*cfa[v]);
	}
}
void dfsfb(int u,int ff){
	fb[u]=0;
	if(~ff){
		cmax(fb[u],fb[ff]+db[ff]-2*cfa[u]-max(0,db[u]-2*cfa[u]));
	}
	rep(i,0,sz(G[u])){
		int v=G[u][i].AA;
		if(v==ff)continue;
		dfsfb(v,u);
	}
}
void dfsdd(int u,int ff){
	rep(i,0,sz(G[u])){
		int v=G[u][i].AA;
		if(v==ff)continue;
		dfsdd(v,u);
	}
	rep(k,0,2)dd[u][k]=val[u],idd[u][k]=-1;
	rep(i,0,sz(G[u])){
		int v=G[u][i].AA;
		if(v==ff)continue;
		update(dd[u],idd[u],dd[v][0]-cfa[v]+db[u]-max(0,db[v]-2*cfa[v]),v);
	}
}
void dfsfd(int u,int ff){
	fd[u]=0;
	if(~ff){
		if(u!=idd[ff][0]){
			cmax(fd[u],-cfa[u]+dd[ff][0]-max(0,db[u]-2*cfa[u])+fb[ff]);
		}
		else {
			cmax(fd[u],-cfa[u]+dd[ff][1]-max(0,db[u]-2*cfa[u])+fb[ff]);
		}
		cmax(fd[u],-cfa[u]+db[ff]-max(0,db[u]-2*cfa[u])+fd[ff]);
	}
	ans[u]=dd[u][0]+fb[u];
	cmax(ans[u],fd[u]+db[u]);
	rep(i,0,sz(G[u])){
		int v=G[u][i].AA;
		if(v==ff)continue;
		dfsfd(v,u);
	}
}
void solve(){
	DRI(n);
	rep(i,1,n+1)G[i].clear();
	rep(i,1,n+1)RI(val[i]);
	rep(i,1,n){
		DRI(p);DRI(q);DRI(w);
		G[p].PB(MP(q,w));
		G[q].PB(MP(p,w));
	}
	fa[1]=-1,cfa[1]=0;
	dfsfa(1,-1);
	//rep(i,1,n+1)cout<<fa[i]<<" ";cout<<" fa\n";
	//rep(i,1,n+1)cout<<cfa[i]<<" ";cout<<" cfa\n";
	dfsdb(1,-1);
	//rep(i,1,n+1)cout<<db[i]<<" ";cout<<" db\n";
	dfsfb(1,-1);
	//rep(i,1,n+1)cout<<fb[i]<<" ";cout<<" fb\n";
	dfsdd(1,-1);
	//rep(i,1,n+1)cout<<dd[i][0]<<" ";cout<<" ddi0\n";
	//rep(i,1,n+1)cout<<idd[i][0]<<" ";cout<<" iddi0\n";
	//rep(i,1,n+1)cout<<dd[i][1]<<" ";cout<<" ddi1\n";
	//rep(i,1,n+1)cout<<idd[i][1]<<" ";cout<<" iddi1\n";
	dfsfd(1,-1);
	//rep(i,1,n+1)cout<<fd[i]<<" ";cout<<" fd\n";
	rep(i,1,n+1)printf("%d\n",ans[i]);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d:\n",CA+1);
		solve();
	}
	return 0;
}