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
#define NAME "dual"
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;
const int MXN = 100005;
int n;
vector<int>G[MXN];
int fa[MXN];
int sz[MXN];
void dfsz(int u,int f) {
	sz[u]=1;
	for(int i=0; i<G[u].SZ; i++) {
		int v=G[u][i];
		if(v==f)continue;
		dfsz(v,u);
		sz[u]+=sz[v];
	}
}
set<PII>A,B,a[2],b[2];
set<PII>::iterator it;
inline void del(set<PII>&A,PII t) {
	it=A.find(t);
	if(it!=A.ED)A.erase(it);
}
inline PII is(int v) {
	return MP(-sz[v],v);
}
int main() {
	freopen(NAME".in","r",stdin);
	freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	while(~scanf("%d",&n)) {
		for(i=0; i<=n; i++)G[i].clear();
		for(i=1; i<=n; i++) {
			scanf("%d",&fa[i]);
			G[fa[i]].PB(i);
		}
		dfsz(0,-1);
		int u;
		u=0;
		A.clear(),B.clear();
		for(i=0; i<2; i++)a[i].clear(),b[i].clear();
		for(int i=0; i<G[u].SZ; i++) {
			int v=G[u][i];
			A.insert(is(v));
			B.insert(is(v));
		}
		int x=0;
		int rem=n;
		vector<PII>ans;
		while(rem) {
			for(it=a[x].OP; it!=a[x].ED; ++it)A.insert(*it);
			for(it=b[x].OP; it!=b[x].ED; ++it)B.insert(*it);
			a[x].clear(),b[x].clear();
			PII ta=MP(0,0),tb=MP(0,0);
			if(!A.empty()&&B.SZ>1) {
				PII tp=ta=*A.OP;
				del(A,tp),del(B,tp),del(a[0],tp),del(a[1],tp),del(b[0],tp),del(b[1],tp);
				rem--;
			}
			if(!B.empty()&&A.SZ>1) {
				PII tp=tb=*B.OP;
				del(A,tp),del(B,tp),del(a[0],tp),del(a[1],tp),del(b[0],tp),del(b[1],tp);
				rem--;
			}
			if(!A.empty()&&ta.BB==0) {
				PII tp=ta=*A.OP;
				del(A,tp),del(B,tp),del(a[0],tp),del(a[1],tp),del(b[0],tp),del(b[1],tp);
				rem--;
			}
			if(!B.empty()&&tb.BB==0) {
				PII tp=tb=*B.OP;
				del(A,tp),del(B,tp),del(a[0],tp),del(a[1],tp),del(b[0],tp),del(b[1],tp);
				rem--;
			}
			if(ta.BB) {
				u=ta.BB;
				for(int i=0; i<G[u].SZ; i++) {
					int v=G[u][i];
					A.insert(is(v));
					b[x].insert(is(v));
				}
			}
			if(tb.BB) {
				u=tb.BB;
				for(int i=0; i<G[u].SZ; i++) {
					int v=G[u][i];
					B.insert(is(v));
					a[x].insert(is(v));
				}
			}
			x^=1;
			ans.PB(MP(ta.BB,tb.BB));
		}
		printf("%d\n",ans.SZ);
		for(i=0;i<ans.SZ;i++)printf("%d %d\n",ans[i].AA,ans[i].BB);
	}
	return 0;
}
/*
100
0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 11 11 12 12 13 13 14 14 15 15 16 16 17 17 18 18 19 19 20 20 21 21 22 22 23 23 24 24 25 25 26 26 27 27 28 28 29 29 30 30 31 31 32 32 33 33 34 34 35 35 36 36 37 37 38 38 39 39 40 40 41 41 42 42 43 43 44 44 45 45 46 46 47 47 48 48 49 49 50
*/
