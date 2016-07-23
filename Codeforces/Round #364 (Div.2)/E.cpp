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

vector<int>G[200005];
int u[200005];
int q[200005],ql,qr;
int vis[200005];
int fa[200005];
int ns[200005];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)u[i]=0,G[i].clear(),vis[i]=0,fa[i]=-1;
	rep(i,0,2*m){
		int x;
		scanf("%d",&x);
		u[x]=1;
	}
	rep(i,0,n-1){
		int p,q;
		scanf("%d%d",&p,&q);
		G[p].PB(q),G[q].PB(p);
	}
	ql=qr=0;
	q[qr++]=1;
	vis[1]=1;
	while(qr>ql){
		int x=q[ql++];
		rep(i,0,sz(G[x])){
			int y=G[x][i];
			if(vis[y])continue;
			vis[y]=1;
			q[qr++]=y;
			fa[y]=x;
		}
	}
	LL ans=0;
	for(int i=n-1;i>=0;i--){
		int x=q[i];
		ns[x]=u[x];
		rep(j,0,sz(G[x])){
			int y=G[x][j];
			if(y==fa[x])continue;
			ns[x]+=ns[y];
		}
		ans+=min(ns[x],2*m-ns[x]);
	}
	printf("%I64d\n",ans);
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}