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

void update(PII &tp,PII w){
	if(~w.AA){
		if(~tp.AA){
			if(tp.AA<w.AA)tp=w;
			else if(tp.AA==w.AA){
				tp.BB+=w.BB;
				if(tp.BB>=MOD)tp.BB-=MOD;
			}
		}else tp=w;
	}
}
int a[5005],n;
PII dp[5005][5005];
int pre[5005][5005];
int nxt[5005][5005];
int id[5005];
PII sv[5005];
void solve(){
	while(~scanf("%d",&n)){
		rep(i,1,n+1)scanf("%d",&a[i]);
		VI Z;
		rep(i,1,n+1)Z.PB(a[i]);
		sort(all(Z));
		Z.erase(unique(all(Z)),Z.ED);
		rep(i,1,n+1)a[i]=lower_bound(Z.OP,Z.ED,a[i])-Z.OP;
		rep(i,0,n+2)rep(j,0,n+2)dp[i][j]=MP(-1,-1);
		rep(j,0,sz(Z))id[j]=n+1;
		repd(i,n,-1,-1){
			rep(j,0,sz(Z))nxt[i][j]=id[j];
			if(1<=i&&i<=n)id[a[i]]=i;
		}
		rep(j,0,sz(Z))id[j]=0;
		rep(i,1,n+2){
			rep(j,0,sz(Z))pre[i][j]=id[j];
			if(1<=i&&i<=n)id[a[i]]=i;
		}
		repd(i,n,0,-1){
			rep(k,0,sz(Z))sv[k]=MP(0,1);
			PII now=MP(0,1);
			rep(j,i,n+1){
				if(a[j]==a[i])
					dp[i][j]=MP(now.AA+(i==j?1:2),now.BB);
				if(a[j]<=a[i]&&j>i){
					int flag=0;
					if(dp[nxt[i][a[j]]][j]>sv[a[j]]){
						if(dp[nxt[i][a[j]]][j].AA>now.AA)
							now=dp[nxt[i][a[j]]][j];
						else if(dp[nxt[i][a[j]]][j].AA==now.AA){
							if(sv[a[j]].AA==now.AA)
								now.BB+=dp[nxt[i][a[j]]][j].BB-sv[a[j]].BB;
							else now.BB+=dp[nxt[i][a[j]]][j].BB;
							if(now.BB>=MOD)now.BB-=MOD;
						}
					}
					sv[a[j]]=dp[nxt[i][a[j]]][j];
				}
			}
		}
		PII ans=MP(-1,-1);
		rep(k,0,sz(Z))update(ans,dp[nxt[0][k]][pre[n+1][k]]);
		printf("%d %d\n",(int)ans.AA,(int)ans.BB);
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