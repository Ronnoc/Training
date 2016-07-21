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

LL dp[15][15];
LL cb[15][15];
void solve(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		printf("%I64d\n",dp[n][m]);
	}
}

LL thr[111];
int main(){
	thr[0]=1;
	rep(i,0,100)
		thr[i+1]=thr[i]*3%MOD;
	rep(i,0,11){
		cb[i][0]=cb[i][i]=1;
		rep(j,1,i)
			cb[i][j]=(cb[i-1][j]+cb[i-1][j-1])%MOD;
	}
	rep(i,0,11)rep(j,0,11){
		dp[i][j]=thr[i*j];
		rep(a,1,i+1)rep(b,0,j+1)if(a!=i||b!=j)
			dp[i][j]-=cb[i-1][a-1]*cb[j][b]*thr[(i-a)*(j-b)]%MOD*dp[a][b]%MOD;
		dp[i][j]=(dp[i][j]%MOD+MOD)%MOD;
	}
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}
/*
1 2
3 2
7 9
10 10
*/