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
LL cb[66][66];
LL tw[66*66];
LL ne[66];
LL tp[66][66];
LL dp[66][66][66];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof dp);
	dp[1][1][1]=1;
	LL ans=0;
	rep(i,1,n+1){
		int rj=min(i,m)+1;
		rep(j,1,rj)rep(k,1,i-j+2){
			if(dp[i][j][k]){
				//cout<<"tot = "<<i<<" , dep = "<<j<<" , last = "<<k<<" => "<<dp[i][j][k]<<" * "<<tw[ne[n-i]]<<"\n";
				dp[i][j][k]%=MOD;
				ans+=dp[i][j][k]*tw[ne[n-i]]%MOD;
				if(j<m)rep(w,1,n-i+1){
					//cout<<"-> "<<i+w<<" "<<j+1<<" "<<w<<" * "<<cb[n-i][w]<<" * "<<tp[k][w]<<"\n";
					dp[i+w][j+1][w]+=dp[i][j][k]*cb[n-i][w]%MOD*tp[k][w]%MOD;
				}
			}
		}
	}
	cout<<ans%MOD<<"\n";
}

int main(){
	rep(i,0,61){
		cb[i][0]=cb[i][i]=1;
		rep(j,1,i)
			cb[i][j]=(cb[i-1][j-1]+cb[i-1][j])%MOD;
	}
	tw[0]=1;
	rep(i,1,3601)
		tw[i]=tw[i-1]*2%MOD;
	ne[0]=0;
	rep(i,1,61)
		ne[i]=(i*(i-1))/2;
	rep(i,1,61)rep(j,1,61){
		tp[i][j]=tw[ne[j]];
		rep(k,0,j)tp[i][j]=tp[i][j]*(tw[i]-1)%MOD;
	}
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}