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
#define RI(X) scan_d(X)
#define DRI(X) int (X); scan_d(X)
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
void update(PII *z,PII w){
	if(w>=z[0]){
		z[1]=z[0];
		z[0]=w;
	}else cmax(z[1],w);
}
int head[MXN],etot;
struct Edge {
    int v,w,next;
} G[MXN<<1];

void add_edge(int u,int v,int w) {
    G[etot].v = v; G[etot].w=w;
    G[etot].next = head[u]; head[u] = etot ++;
}

int f[MXN],g[MXN],h[MXN],p[MXN];
PII z[MXN][2];
void dfsf(int u,int fa){
	rep(i,0,2)z[u][i].AA=z[u][i].BB=-1;
	g[u]=f[u]=0;
	for (int i = head[u]; i != -1; i = G[i].next){
		int v=G[i].v;
		int w=G[i].w;
		if(v==fa)continue;
		cmax(g[u],g[v]+w);
		cmax(f[u],f[v]);
		update(z[u],MP(g[v]+w,v));
	}
	cmax(f[u],g[u]);
	if(~z[u][1].AA)
		cmax(f[u],z[u][0].AA+z[u][1].AA);
}
PII pre[MXN][2],suf[MXN][2];
int pf[MXN],sf[MXN];
PII son[MXN];
int nson;
template <class T>inline bool scan_d(T &ret) {
	char c; 
	int sgn;
	if((c=getchar())==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}
inline void out(int x) {
	if(x>9) out(x/10);
	putchar(x%10+'0');
}
void dfsh(int u,int fa){
	nson=0;
	for (int i = head[u]; i != -1; i = G[i].next){
		int v=G[i].v;
		int w=G[i].w;
		if(v==fa)continue;
		son[nson++]=(MP(v,w));
	}
	int i=0;
	memset(pre[i],-1,sizeof pre[i]),pf[i]=-1;
	memset(suf[i],-1,sizeof suf[i]),sf[i]=-1;
	rep(i,0,nson){
		int v=son[i].AA;
		int w=son[i].BB;
		memcpy(pre[i+1], pre[i], sizeof(pre[i]));
		pf[i+1]=pf[i];
		cmax(pf[i+1],f[v]);
		update(pre[i+1],MP(g[v]+w,v));
	}
	rep(i,0,nson){
		int v=son[nson-1-i].AA;
		int w=son[nson-1-i].BB;
		memcpy(suf[i+1], suf[i], sizeof(suf[i]));
		sf[i+1]=sf[i];
		cmax(sf[i+1],f[v]);
		update(suf[i+1],MP(g[v]+w,v));
	}
	rep(i,0,nson){
		int I=nson-1-i;
		int v=son[i].AA;
		int w=son[i].BB;
		p[v]=p[u]+w;
		rep(j,0,1)if(~pre[i][j].BB)cmax(p[v],pre[i][j].AA+w);
		rep(j,0,1)if(~suf[I][j].BB)cmax(p[v],suf[I][j].AA+w);
		h[v]=max(h[u],p[u]);
		cmax(h[v],pf[i]);
		cmax(h[v],sf[I]);
		rep(j,0,1)if(~pre[i][j].BB)
			rep(k,0,1)if(~suf[I][k].BB)
				cmax(h[v],pre[i][j].AA+suf[I][k].AA);
		if(~pre[i][0].BB&&~pre[i][1].BB)
			cmax(h[v],pre[i][0].AA+pre[i][1].AA);
		if(~suf[I][0].BB&&~suf[I][1].BB)
			cmax(h[v],suf[I][0].AA+suf[I][1].AA);
		rep(j,0,1)if(~pre[i][j].BB)cmax(h[v],p[u]+pre[i][j].AA);
		rep(j,0,1)if(~suf[I][j].BB)cmax(h[v],p[u]+suf[I][j].AA);
		//cout<<v<<" p"<<p[v]<<" h"<<h[v]<<"\n";
	}
}
int q[MXN],ql,qr;
int fq[MXN];
void solve(){
	DRI(n);
	etot=0;
	rep(i,1,n+1)head[i]=-1,fq[i]=-1;
	rep(i,1,n){
		DRI(u);
		DRI(v);
		DRI(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	ql=qr=0;
	q[qr++]=1;
	while(qr>ql){
		int u=q[ql++];
		for (int i = head[u]; i != -1; i = G[i].next){
			int v=G[i].v;
			if(v==fq[u])continue;
			q[qr++]=v;
			fq[v]=u;
		}
	}
	repd(i,n-1,0)dfsf(q[i],fq[q[i]]);
	h[1]=p[1]=0;
	rep(i,0,n)dfsh(q[i],fq[q[i]]);
	LL ans=0;
	rep(i,2,n+1)ans+=max(f[i],h[i]);
	printf("%I64d\n",ans);
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