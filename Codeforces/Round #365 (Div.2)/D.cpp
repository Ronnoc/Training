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

const int MXN = 1000005;
int c[MXN];
int Z[MXN];
int id[MXN];
int cnt[MXN];
vector<PII>G[MXN];
int nxt[MXN];
int _[MXN];
int ans[MXN];
inline int LB(int x) {return x & (-x);}
int query(int w) {
	int ret = 0;
	for (w += 2; w > 0; w -= LB(w))ret ^= _[w];
	return ret;
}
void update(int w, LL d,int n) {
	for (w += 2; w < n; w += LB(w))_[w] ^= d;
}
void solve(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&c[i]);
	int iz=0;
	rep(i,0,n)Z[iz++]=c[i];
	sort(Z,Z+iz);
	iz=unique(Z,Z+iz)-Z;
	rep(i,0,n)id[i]=lower_bound(Z,Z+iz,c[i])-Z;
	rep(i,0,n)G[i].clear();
	int m;
	scanf("%d",&m);
	rep(i,0,m){
		int l,r;
		scanf("%d%d",&l,&r);
		l--,r--;
		G[l].PB(MP(i,r));
	}
	rep(i,0,iz)nxt[i]=-1;
	rep(i,0,n+3)_[i]=0;
	for(int l=n-1;l>=0;l--){
		if(~nxt[id[l]])
			update(nxt[id[l]],Z[id[l]],n+3);
		nxt[id[l]]=l;
		rep(i,0,sz(G[l]))
			ans[G[l][i].AA]=query(G[l][i].BB);
	}
	rep(i,0,m)printf("%d\n",ans[i]);
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}