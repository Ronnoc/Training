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

const int MXN = 1005;
int dp[MXN][MXN][3][3];
int w[MXN];
inline void add(int &tp,int w){
	tp+=w;
	if(tp>=MOD)tp-=MOD;
}
void solve(){
	int n,s;
	scanf("%d%d",&n,&s);
	rep(i,0,n)scanf("%d",&w[i]);
	rep(i,0,n+1)rep(j,0,s+1)rep(p,0,3)rep(q,0,3)dp[i][j][p][q]=0;
	dp[0][0][0][0]=1;
	rep(i,0,n)rep(j,0,s+1){
		rep(p,0,3)rep(q,0,3)if(dp[i][j][p][q]){
			int tp=dp[i][j][p][q];
			add(dp[i+1][j][p][q],tp);
			if(q<2)add(dp[i+1][j][p][q+1],tp);
			if(j+w[i]<=s){
				add(dp[i+1][j+w[i]][p][q],tp);
				if(p<2)
					add(dp[i+1][j+w[i]][p+1][q],tp);
			}
		}
	}
	int ans=0;
	rep(j,1,s+1)add(ans,dp[n][j][2][2]);
	printf("%d\n",int((4LL*ans)%MOD));
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}