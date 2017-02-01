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
VI G[33];
LL x[33],y[33];
LL dx[]={1,-1,0,0};
LL dy[]={0,0,1,-1};
void dfs(int u,int f,int z,LL xx,LL yy,LL len){
	//cout<<u<<" "<<f<<" "<<z<<" "<<xx<<" "<<yy<<" "<<len<<"\n";
	x[u]=xx;
	y[u]=yy;
	int mask = 0;
	if(~z)mask|=1<<(z^1);
	rep(i,0,sz(G[u])){
		int v=G[u][i];
		if(v==f)continue;
		rep(j,0,4){
			if(mask>>j&1)continue;
			dfs(v,u,j,xx+dx[j]*len,yy+dy[j]*len,len/2);
			mask|=1<<j;
			break;
		}
	}
}
void solve(){
	DRI(n);
	rep(i,0,n)G[i].clear();
	rep(i,1,n){
		DRI(u);DRI(v);
		u--;v--;
		G[u].PB(v);
		G[v].PB(u);
	}
	int fail=0;
	rep(i,0,n)if(sz(G[i])>4)fail=1;
	if(fail)
		cout<<"NO\n";
	else {
		cout<<"YES\n";
		dfs(0,-1,-1,0,0,1LL<<40);
		rep(i,0,n)cout<<x[i]<<" "<<y[i]<<"\n";
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