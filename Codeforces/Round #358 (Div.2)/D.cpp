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

char s[1005],t[1005];
int dp[1005][1005][13][3];
void update(int &tp,int w){
	if(~tp)cmax(tp,w);
	else tp=w;
}
int main(){
	int i,j,k,_T;
	int n,m,K;
	while(~scanf("%d%d%d%s%s",&n,&m,&K,s,t)){
		memset(dp,-1,sizeof dp);
		dp[0][0][0][0]=0;
		rep(i,0,n+1)rep(j,0,m+1)rep(k,0,K+1)
			rep(u,0,2)if(~dp[i][j][k][u]){
				int w=dp[i][j][k][u];
				if(i<n&&j<m&&s[i]==t[j]){
					update(dp[i+1][j+1][k+1][1],w+1);
					if(u)update(dp[i+1][j+1][k][1],w+1);
				}
				update(dp[i+1][j][k][0],w);
				update(dp[i][j+1][k][0],w);
				//cout<<i<<" "<<j<<" "<<k<<" "<<u<<" "<<dp[i][j][k][u]<<"\n";
			}
		int ans=-1;
		rep(u,0,2)
			update(ans,dp[n][m][K][u]);
		cout<<ans<<"\n";
	}
	return 0;
}