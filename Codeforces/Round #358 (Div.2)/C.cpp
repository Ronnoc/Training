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
const int N = 100000+5;
int vis[N];
int a[N];
LL d[N];
int Q[N],fa[N];
vector<PII>G[N];
int main(){
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)){
		rep(i,1,n+1)vis[i]=0,G[i].clear();
		rep(i,1,n+1)scanf("%d",&a[i]);
		rep(i,1,n){
			scanf("%d%d",&j,&k);
			G[j].PB(MP(i+1,k)),G[i+1].PB(MP(j,k));
		}
		int lq=0,rq=0;
		Q[rq++]=1;vis[1]=1;fa[1]=-1;
		while(rq>lq){
			int u=Q[lq++];
			for(auto v:G[u])if(!vis[v.AA]){
				Q[rq++]=v.AA;
				vis[v.AA]=1;
				fa[v.AA]=u;
			}
		}
		d[1]=0;
		rep(i,0,rq){
			int u=Q[i];
			if(~fa[u])vis[u]&=vis[fa[u]];
			if(vis[u]){
				for(auto e:G[u]){
					int v=e.AA;
					if(v==fa[u])continue;
					d[v]=max(d[u]+e.BB,1LL*e.BB);
					if(d[v]>a[v])vis[v]=0;
				}
			}
			//cout<<u<<" "<<vis[u]<<" "<<d[u]<<">"<<a[u]<<"\n";
		}
		int sum=n;
		rep(i,1,n+1)sum-=vis[i];
		printf("%d\n",sum);
	}
	return 0;
}