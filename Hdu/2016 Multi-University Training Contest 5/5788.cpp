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
#define repd(i,a,b,d) for(int i=(a);i!=(b);i+=d)
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
struct SEG {
	int l, r;
	LL sum;
	SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN*27];
int nextid;
int root[MXN];
inline void update(SEG &de,SEG &l,SEG &r){
	de.sum=l.sum+r.sum;
}
void build(int id,int le,int re){
	SEG &de=SGT[id];
	if(re-le==1){
		de.sum=0;
		return;
	}
	int me=(le+re)>>1;
	build(de.l=nextid++,le,me);
	build(de.r=nextid++,me,re);
	update(de,SGT[de.l],SGT[de.r]);
}
void dfs(int id,int le,int re,int c,int w){
	SEG &de=SGT[id];
	int me=(le+re)/2;
	if(re-le==1){
		de.sum+=w;
		return;
	}
	if(c<me){
		SGT[nextid]=SGT[de.l];
		dfs(de.l=nextid++,le,me,c,w);
	}else {
		SGT[nextid]=SGT[de.r];
		dfs(de.r=nextid++,me,re,c,w);
	}
	update(de,SGT[de.l],SGT[de.r]);
	//cout<<de.sum<<" "<<le<<"~"<<re<<"\n";
}
int query(int pid,int qid,int le,int re,int c){
	int me=(le+re)/2;
	int sum=SGT[qid].sum-SGT[pid].sum;
	if(sum<c)return -1;
	if(re-le==1)return le;
	int lesum=SGT[SGT[qid].l].sum-SGT[SGT[pid].l].sum;
	if(c<=lesum)
		return query(SGT[pid].l,SGT[qid].l,le,me,c);
	else 
		return query(SGT[pid].r,SGT[qid].r,me,re,c-lesum);
}
LL qsum(int id,int le,int re,int pe,int qe){//[pe,qe)
	//cout<<"qsum "<<id<<" "<<le<<" "<<re<<" "<<pe<<" "<<qe<<"\n";
	SEG &de=SGT[id];
	int me=(le+re)/2;
	if(le==pe&&re==qe)return de.sum;
	if(qe<=me)return qsum(de.l,le,me,pe,qe);
	if(pe>=me)return qsum(de.r,me,re,pe,qe);
	return qsum(de.l,le,me,pe,me)+qsum(de.r,me,re,me,qe);
}
void qadd(int id,int le,int re,int c,int w){
	//cout<<"qadd "<<id<<" "<<le<<" "<<re<<" "<<c<<" "<<w<<"\n";
	SEG &de=SGT[id];
	int me=(le+re)/2;
	if(re-le==1){
		de.sum+=w;
		return;
	}
	if(c<me)qadd(de.l,le,me,c,w);
	else qadd(de.r,me,re,c,w);
	update(de,SGT[de.l],SGT[de.r]);
}
int a[MXN],fa[MXN];
VI G[MXN];
int TL[MXN],itl;
int lt[MXN],rt[MXN];
void dfsTree(int u){
	TL[++itl]=u;
	lt[u]=itl;
	rep(i,0,sz(G[u]))
		dfsTree(G[u][i]);
	rt[u]=itl;
}
int Z[MXN],iz;
LL ans;
int zm[MXN],da[MXN];
void dfsAns(int u){
	//cout<<"dfsAns "<<u<<"\n";
	qadd(root[itl+1],0,iz,0,da[u]);
	qadd(root[itl+1],0,iz,zm[u]+1,-da[u]);
	LL now=qsum(root[itl+1],0,iz,0,zm[u]+1);
	cmax(ans,now);
	//cout<<"Ans "<<u<<" "<<now<<"\n";
	rep(i,0,sz(G[u]))
		dfsAns(G[u][i]);
	qadd(root[itl+1],0,iz,0,-da[u]);
	qadd(root[itl+1],0,iz,zm[u]+1,da[u]);
}
void solve(){
	int n;
	while(~scanf("%d",&n)){
		rep(i,1,n+1)scanf("%d",&a[i]);
		rep(i,2,n+1)scanf("%d",&fa[i]);
		rep(i,1,n+1)G[i].clear();
		rep(i,2,n+1)G[fa[i]].PB(i);
		itl=0;
		dfsTree(1);
		//cout<<"Tree done\n";
		iz=0;
		Z[iz++]=100000;
		Z[iz++]=100001;
		rep(i,1,n+1)Z[iz++]=a[i];
		sort(Z,Z+iz);
		iz=unique(Z,Z+iz)-Z;
		nextid=0;
		build(root[0]=nextid++,0,iz);
		rep(i,1,itl+1){
			int u=TL[i];
			int iu=lower_bound(Z,Z+iz,a[u])-Z;
			//cout<<"+"<<u<<" "<<iu<<"\n";
			SGT[nextid]=SGT[root[i-1]];
			dfs(root[i]=nextid++,0,iz,iu,1);
		}
		build(root[itl+1]=nextid++,0,iz);
		//cout<<"SGT done\n";
		rep(i,1,n+1){
			int cnt=rt[i]-lt[i]+1;
			if(cnt==1){
				zm[i]=lower_bound(Z,Z+iz,a[i])-Z;
				da[i]=100000-Z[zm[i]];
			}else {
				zm[i]=query(root[lt[i]-1],root[rt[i]],0,iz,(cnt+1)/2);
				da[i]=query(root[lt[i]-1],root[rt[i]],0,iz,(cnt+1)/2+1);
				//cout<<SGT[root[rt[i]]].sum<<"-"<<SGT[root[lt[i]-1]].sum<<"?"<<lt[i]<<"~"<<rt[i]<<" ";
				//cout<<zm[i]<<","<<Z[zm[i]]<<" "<<da[i]<<" "<<Z[da[i]]<<"\n";
				da[i]=Z[da[i]]-Z[zm[i]];
			}
			//cout<<i<<"@"<<zm[i]<<"?"<<Z[zm[i]]<<"+"<<da[i]<<" "<<lt[i]<<"~"<<rt[i]<<"\n";
		}
		//cout<<"zmda done\n";
		ans=0;
		dfsAns(1);
		//cout<<"dfsAns done\n";
		rep(i,1,n+1)ans+=Z[zm[i]];
		cout<<ans<<"\n";
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}