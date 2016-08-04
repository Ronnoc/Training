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
	int l, r, sum;
	SEG( int _l = 0, int _r = 0 ) {l = _l, r = _r;}
} SGT[MXN<<4];
int nextid;
int root[MXN];
int c[MXN],q[MXN];
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
}
int query(int id,int le,int re,int pe,int qe){
	SEG &de=SGT[id];
	int me=(le+re)/2;
	if(pe==le&&qe==re)return de.sum;
	if(qe<me)return query(de.l,le,me,pe,qe);
	if(pe>=me)return query(de.r,me,re,pe,qe);
	return query(de.l,le,me,pe,me)+query(de.r,me,re,me,qe);
}
char s[MXN];
struct node{
	int next[26];
	int id;
	node(){init();}
	void init(){memset(next,-1,sizeof next);id=-1;}
}f[MXN<<1];
int nodeid;
int vis[MXN];
int cnt[MXN];
void solve(){
	int n;
	while(~scanf("%d",&n)){
		nextid=nodeid=0;
		build(root[0]=1,0,n);
		int trie;
		f[trie=nodeid++].init();
		rep(i,0,n)vis[i]=-1,cnt[i]=0;
		rep(i,0,n){
			SGT[root[i]=nextid++]=SGT[root[i-1]];
			scanf("%s",s);
			int len=strlen(s);
			int at=trie;
			VI L;
			rep(j,0,len){
				int c=s[j]-'a';
				if(f[at].next[c]==-1)
					f[f[at].next[c]=nodeid++].init();
				at=f[at].next[c];
				if(~f[at].id){
					if(vis[f[at].id]!=i){
						vis[f[at].id]=i;
						cnt[f[at].id]=0;
						L.PB(f[at].id);
					}
					cnt[f[at].id]--;
				}
				f[at].id=i;
				if(vis[f[at].id]!=i){
					vis[f[at].id]=i;
					cnt[f[at].id]=0;
					L.PB(f[at].id);
				}
				cnt[f[at].id]++;
			}
			rep(j,0,sz(L))
				dfs(root[i],0,n,L[j],cnt[L[j]]);
		}
		int Z=0;
		int Q;scanf("%d",&Q);
		while(Q--){
			int L,R;
			scanf("%d%d",&L,&R);
			L=(L+Z)%n,R=(R+Z)%n;
			if(L>R)swap(L,R);
			Z=query(root[R],0,n,L,n);
			printf("%d\n",Z);
		}
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