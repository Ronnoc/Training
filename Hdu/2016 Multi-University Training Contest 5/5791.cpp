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
int dp[1005][1005];
int a[1005],b[1005];
int sa[1005][1005];
int sb[1005];
void add(int &tp,int w){
	tp+=w;
	if(tp>=MOD)tp-=MOD;
}
void solve(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		rep(i,1,n+1)scanf("%d",&a[i]);
		rep(j,1,m+1)scanf("%d",&b[j]);
		rep(i,0,n+1)dp[i][0]=1;
		rep(j,0,m+1)dp[0][j]=1;
		rep(k,1,1001)rep(j,0,m+1)sa[k][j]=0;
		rep(i,1,n+1){
			rep(k,1,1001)sb[k]=0;
			rep(j,1,m+1){
				dp[i][j]=dp[i-1][j-1];
				if(a[i]==b[j])add(dp[i][j],dp[i-1][j-1]);
				add(dp[i][j],sb[a[i]]);
				add(dp[i][j],sa[b[j]][j]);
				add(sb[b[j]],dp[i-1][j-1]);
			}
			rep(j,1,m+1)
				add(sa[a[i]][j],dp[i-1][j-1]);
		}
		printf("%d\n",(dp[n][m]+MOD-1)%MOD);
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}