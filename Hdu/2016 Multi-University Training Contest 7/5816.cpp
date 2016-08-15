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
int x[20|1];
int s[1<<20|1];
LL cb[23][23];
LL f[21][21][21];
LL g[21];
LL all[21],can[21];
void solve(){
	int p,n,m;
	RI(p);RI(n);RI(m);
	rep(i,0,m)RI(x[i]);
	s[0]=0;
	rep(mask,1,1<<m){
		int la=__builtin_ctz(mask);
		s[mask]=s[mask^(1<<la)]+x[la];
	}
	memset(all,0,sizeof all);
	memset(can,0,sizeof can);
	rep(mask,0,1<<m){
		int cnt=__builtin_popcount(mask);
		all[cnt]++;
		can[cnt]+=s[mask]>=p;
	}
	rep(i,0,m+1){
		LL gcd=__gcd(can[i],all[i]);
		can[i]/=gcd;
		all[i]/=gcd;
	}
	memset(f,0,sizeof f);
	if(m)f[0][1][0]=1;
	if(n)f[1][0][1]=1;
	rep(k,1,n+1)rep(j,0,m+1)rep(i,1,k+1)if(f[i][j][k]){
		int w=f[i][j][k];
		if(k+1<=n&&j+1<=m)f[i][j+1][k+1]+=w<<1;
		if(k+2<=n)f[i+1][j][k+2]+=w;
		if(j+2<=m)f[i-1][j+2][k]+=w;
		if(k+1==n&&j==m)f[0][j][k+1]+=w;
		if(k==n&&j+1==m)f[0][j+1][k]+=w;
	}
	memset(g,0,sizeof g);
	rep(k,0,n+1)rep(j,0,m+1){
		g[j]+=f[0][j][k]*cb[n+m-j-k][n-k];
	}
	LL gcd=0;
	rep(j,1,m+1)if(g[j])gcd=__gcd(gcd,g[j]);
	rep(j,1,m+1)g[j]/=gcd;
	LL sum=0;
	rep(j,1,m+1)sum+=g[j];
	LL ap=0,aq=1;
	rep(j,1,m+1)if(g[j]){
		LL P=1,Q=1;
		LL gg=__gcd(all[j],g[j]);
		P*=g[j]/gg;
		Q*=all[j]/gg;
		gg=__gcd(can[j],sum);
		P*=can[j]/gg;
		Q*=sum/gg;
		LL tp=ap*Q+aq*P,tq=aq*Q;
		gg=__gcd(tp,tq);
	}
	cout<<ap<<"/"<<aq<<"\n";
}

int main(){
	rep(i,0,21){
		cb[i][i]=cb[i][0]=1;
		rep(j,1,i)
			cb[i][j]=cb[i-1][j]+cb[i-1][j-1];
	}
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}