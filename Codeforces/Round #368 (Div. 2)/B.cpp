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
LL d[MXN];
void solve(){
	DRI(n);DRI(m);DRI(Z);
	rep(i,1,n+1)G[i].clear();
	while(m--){
		DRI(u);DRI(v);DRI(w);
		G[u].PB(MP(v,w));
		G[v].PB(MP(u,w));
	}
	memset(d,-1,sizeof d);
	set<pair<LL,int> >S;
	while(Z--){
		DRI(k);
		S.insert(MP(d[k]=0,k));
	}
	while(!S.empty()){
		auto tp=*S.OP;
		S.erase(S.OP);
		int u=tp.BB;
		rep(i,0,sz(G[u])){
			int v=G[u][i].AA;
			LL nd=d[u]+G[u][i].BB;
			if(d[v]==-1)S.insert(MP(d[v]=nd,v));
			else if(d[v]>nd){
				S.erase(MP(d[v],v));
				S.insert(MP(d[v]=nd,v));
			}
		}
	}
	LL ans=-1;
	rep(i,1,n+1)if(d[i]>0){
		if(~ans)cmin(ans,d[i]);
		else ans=d[i];
	}
	cout<<ans<<"\n";
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}