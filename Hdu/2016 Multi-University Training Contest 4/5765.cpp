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
int u[444],v[444],w[444];
int g[22][22];
char dp[1<<20|1][22];
int ok[1<<20];
int ee[22];
char getfa(char u,char *fa){return fa[u]==u?u:fa[u]=getfa(fa[u],fa);}
int tot[1<<20];
int may[1<<20],lastmay;
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,m+1)scanf("%d%d",&u[i],&v[i]),w[i]=0;
	rep(i,0,n)rep(j,0,n)g[i][j]=0;
	rep(i,0,n)ee[i]=0;
	rep(i,1,m+1)g[u[i]][v[i]]=g[v[i]][u[i]]=i;
	rep(i,1,m+1)ee[u[i]]|=1<<v[i];
	rep(i,1,m+1)ee[v[i]]|=1<<u[i];
	rep(i,0,n)dp[0][i]=i;ok[0]=0;
	rep(mask,1,1<<n){
		int la=__builtin_ctz(mask);
		int pre=mask^(1<<la);
		rep(i,0,n)dp[mask][i]=dp[pre][i];
		int E=mask&ee[la];
		while(E){
			int i=__builtin_ctz(E);
			E^=1<<i;
			int fu=getfa(i,dp[mask]);
			int fv=getfa(la,dp[mask]);
			dp[mask][fu]=fv;
		}
		ok[mask]=1;
		int temp=pre;
		while(temp){
			int id=__builtin_ctz(temp);
			temp^=1<<id;
			ok[mask]&=getfa(id,dp[mask])==getfa(la,dp[mask]);
		}
	}
	lastmay=0;
	rep(mask,0,1<<n)if(ok[mask]&&ok[(1<<n)-1-mask])may[lastmay++]=mask;
	rep(i,0,n){
		rep(imay,0,lastmay){
			int mask=may[imay];
			int ksam=(1<<n)-1-mask;
			tot[ksam&ee[i]]+=mask>>i&1;
		}
		for(int mask=ee[i];mask>=1;mask--)if((mask&ee[i])==mask){
			int la=__builtin_ctz(mask);
            tot[mask^(1<<la)]+=tot[mask];
            w[g[i][la]]+=tot[mask];
            tot[mask]=0;
		}
	}
	rep(i,1,m+1)printf(" %d",w[i]/2);
	printf("\n");
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d:",CA+1);
		solve();
	}
	return 0;
}