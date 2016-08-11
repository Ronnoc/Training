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
unsigned int dp[1<<18];
int e[21];
void dfs(int mask,int rem,int has){
	cmin(dp[mask],dp[mask^has]+1);
	while(rem){
		int la=__builtin_ctz(rem);
		rem^=1<<la;
		dfs(mask,rem&(~e[la]),has|(1<<la));
	}
}
void solve(){
	DRI(n);
	rep(i,0,n){
		char s[22];
		e[i]=0;
		scanf("%s",s);
		rep(j,0,n)if(s[j]=='1')e[i]|=1<<j;
	}
	int all=(1<<n)-1;
	rep(i,0,1<<n)dp[i]=__builtin_popcount(i);
	rep(i,1,1<<n){
		int la=__builtin_ctz(i);
		dfs(i,(~e[la])&i,1<<la);
	}
	unsigned int ret=0,w=1;
	rep(i,1,1<<n){
		w*=233;
		ret+=w*dp[i];
	}
	cout<<ret<<"\n";
}
int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}