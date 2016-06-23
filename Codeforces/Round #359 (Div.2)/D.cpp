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
const int MXN = 300000+5;
vector<int>G[MXN];
int fa[MXN];
int q[MXN],lq,rq;
int sz[MXN];
int mxs[MXN];
int oo[MXN];
int main(){
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=2;i<=n;i++)
			scanf("%d",&fa[i]);
		for(int i=1;i<=n;i++)
			G[i].clear();
		rep(i,2,n+1)G[fa[i]].PB(i);
		lq=rq=0;
		q[rq++]=1;
		while(rq>lq){
			int u=q[lq++];
			for(auto v:G[u])
				q[rq++]=v;
		}
		for(int i=n-1;i>=0;i--){
			int u=q[i];
			sz[u]=1;
			mxs[u]=0;
			int id=-1;
			for(auto v:G[u]){
				sz[u]+=sz[v];
				if(sz[v]>mxs[u])
					mxs[u]=sz[id=v];
			}
			if(sz[u]==1)oo[u]=u;
			else {
				oo[u]=oo[id];
				while(max(sz[u]-sz[oo[u]],mxs[oo[u]])*2>sz[u])
					oo[u]=fa[oo[u]];
			}
		}
		while(m--){
			scanf("%d",&k);
			printf("%d\n",oo[k]);
		}
	}
	return 0;
}