//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
int d[MXN];
VI G[MXN];
int U[MXN],V[MXN],W[MXN];
int q[MXN],ql,qr;
typedef int ft;
const ft inf = 0x20202020;
const int M = 500000+5,N = 20000+5;
namespace SAP{
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
	ft f[M];
	int S,T,tot,Tn;
	void init(int s,int t,int tn){
		tot=1;
		fill(fst,fst+tn,0);
		fill(dis,dis+tn,0);
		S=s;T=t;Tn=tn;
	}
	void add(int u,int v,ft c1,ft c2=0){
		tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
		tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
	}
	ft sap(){
		int u=S,t=1;ft flow=0;
		rep(i,0,t){
			int u=q[i];
			for(int j=fst[u];j;j=nxt[j])
				if(dis[y[j]]>dis[u]+1&&f[j^1])
					q[t++]=y[j],dis[y[j]]=dis[u]+1;
		}
		rep(i,0,Tn)gap[dis[i]]++;
		while(dis[S]<=Tn){
			while(c[u]&&(!f[c[u]]||dis[y[c[u]]]+1!=dis[u]))
				c[u]=nxt[c[u]];
			if(c[u]){
				pre[y[c[u]]]=c[u]^1;
				u=y[c[u]];
				if(u==T){
					ft minf=inf;
					for(int p=pre[T];p;p=pre[y[p]])
						cmin(minf,f[p^1]);
					for(int p=pre[T];p;p=pre[y[p]])
						f[p^1]-=minf,f[p]+=minf;
					flow+=minf;u=S;
				}
			}else {
				if(!(--gap[dis[u]]))break;
				int mind=Tn;
				c[u]=fst[u];
				for(int j=fst[u];j;j=nxt[j])
					if(f[j]&&dis[y[j]]<mind)
						mind=dis[y[j]],c[u]=j;
				dis[u]=mind+1;
				gap[dis[u]]++;
				if(u!=S)u=y[pre[u]];
			}
		}
		return flow;
	}
};
void solve(){
	DRI(n);
	DRI(m);
	rep(i,0,n)G[i].clear();
	rep(k,0,m)scanf("%d%d%d",&U[k],&V[k],&W[k]);
	rep(k,0,m)U[k]--,V[k]--;
	rep(k,0,m)G[U[k]].PB(V[k]),G[V[k]].PB(U[k]);
	rep(i,0,n)d[i]=-1;
	ql=qr=0;
	d[0]=0;
	q[qr++]=0;
	while(qr>ql){
		int u=q[ql++];
		rep(i,0,sz(G[u])){
			int v=G[u][i];
			if(d[v]==-1){
				d[v]=d[u]+1;
				q[qr++]=v;
			}
		}
	}
	SAP::init(0, n-1, n);
	rep(k,0,m){
		if(d[U[k]]==d[V[k]]+1){
			SAP::add(V[k], U[k], W[k]);
		}
		if(d[V[k]]==d[U[k]]+1){
			SAP::add(U[k], V[k], W[k]);
		}
	}
	int ans=SAP::sap();
	printf("%d\n",ans);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}