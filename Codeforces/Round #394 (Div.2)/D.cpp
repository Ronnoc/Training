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
int a[MXN];
int p[MXN];
int pq[MXN];
VPLL G[MXN];
LL d[MXN];
int ct[MXN];
int inq[MXN];
void solve(){
	int n,l,r;
	while(cin>>n>>l>>r){
		rep(i,1,n+1)RI(a[i]);
		rep(i,1,n+1)RI(p[i]);
		rep(i,1,n+1)pq[p[i]]=i;
		rep(i,0,n+2)G[i].clear();
		//G[x].PB(MP(y,z))
		//d[y]<=d[x]+z
		G[0].PB(MP(n+1,r-l));//d[n+1]<=d[0]+r-l
		G[n+1].PB(MP(0,l-r));//d[0]<=d[n+1]+l-r
		rep(i,1,n+1){
			//d[0]<=d[i]<=d[n+1]
			int id=pq[i];
			G[id].PB(MP(0,0));
			G[n+1].PB(MP(id,0));
		}
		bool fail = 0;
		LL prefix = 0;
		LL best = 0;
		rep(i,1,n){
			int ix=pq[i],iy=pq[i+1];
			//b[ix]<=b[iy]+a[ix]-a[iy]-1
			G[iy].PB(MP(ix,a[ix]-a[iy]-1));
			prefix+=a[ix]-a[iy]-1;
			if(prefix-best+r-l<0)fail=1;
			cmax(best,prefix);
		}
		rep(i,0,n+2)d[i]=1LL<<60,inq[i]=0;
		int u=0;
		d[u]=l;
		deque<int>Q;
		Q.push_back(u);
		inq[u]=1;
		while(!Q.empty() && !fail){
			int u=Q.front();
			Q.pop_front();
			inq[u]=0;
			rep(i,0,sz(G[u])){
				PLL tp=G[u][i];
				LL v=tp.AA;
				LL w=tp.BB;
				if(d[v]>d[u]+w){
					d[v]=d[u]+w;
					if(!inq[v]){
						Q.push_front(v);
						inq[v]=1;
					}
				}
			}
		}
		if(fail)cout<<"-1";
		else rep(i,1,n+1)cout<<d[i]<<" ";
		cout<<"\n";
	}
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