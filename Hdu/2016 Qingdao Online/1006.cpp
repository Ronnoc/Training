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
VI G[MXN];
int q[MXN],ql,qr;
int vis[MXN];
int a[MXN];
void solve(){
	DRI(n);
	DRI(m);
	rep(i,0,n)G[i].clear(),vis[i]=0;
	rep(i,0,n)RI(a[i]);
	int wtf=0;
	rep(j,0,m){
		DRI(u);
		DRI(v);
		u--;v--;
		if(u!=v){
			G[u].PB(v);
			G[v].PB(u);
		}else wtf^=a[u];
	}
	ql=qr=0;
	q[qr++]=0;
	vis[0]=1;
	while(qr>ql){
		int u=q[ql++];
		rep(i,0,sz(G[u])){
			int v=G[u][i];
			if(!vis[v]){
				vis[v]=1;
				q[qr++]=v;
			}
		}
	}
	int fail=0;
	int cnt=0;
	rep(i,0,n){
		fail|=!vis[i];
		cnt+=sz(G[i])&1;
	}
	if(!fail&&cnt<=2){
		if(cnt){
			int ans=0;
			rep(i,0,n){
				int k=sz(G[i]);
				if(k&1){
					if(k%4==1)ans^=a[i];
				}else {
					if(k%4==2)ans^=a[i];
				}
			}
			printf("%d\n",ans^wtf);
		}else {
			int tmp=0;
			rep(i,0,n){
				if(sz(G[i])%4==2)tmp^=a[i];
			}
			int ans=tmp^a[0]^wtf;
			rep(i,0,n)cmax(ans,tmp^a[i]^wtf);
			printf("%d\n",ans);
		}
	}
	else printf("Impossible\n");
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}