#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

int dp[111][111];
int E[111][111];
int ff[111][111];
vector<int>L;
void solve(int u,int v) {
	if(~ff[u][v]) {
		solve(u,ff[u][v]);
		solve(ff[u][v],v);
	}
	else if(u!=v)L.PB(u);
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,T;
	while(~scanf("%d%d",&n,&m)) {
		memset(dp,0x0f,sizeof dp);
		memset(E,0x0f,sizeof E);
		memset(ff,-1,sizeof ff);
		for(i=1;i<=n;i++)dp[i][i]=0;
		for(i=0; i<m; i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			cmin(dp[u][v],w);
			cmin(dp[v][u],w);
			cmin(E[u][v],w);
			cmin(E[v][u],w);
		}
		int BEST=dp[0][0];
		for(k=1; k<=n; k++) {
			for(i=1; i<=n; i++)
				for(j=1; j<=n; j++) {
					int tap=E[i][k]+E[k][j]+dp[j][i];
					if(tap<BEST&&i!=j){
						BEST=tap;
						L.clear();
						L.PB(i);
						L.PB(k);
						solve(j,i);
					}
				}
			for(i=1; i<=n; i++)
				for(j=1; j<=n; j++) {
					int tp=dp[i][k]+dp[k][j];
					if(tp<dp[i][j])dp[i][j]=tp,ff[i][j]=k;
				}
		}
		if(BEST!=dp[0][0]) {
			printf("%d",L[0]);
			for(i=1; i<L.SZ; i++)printf(" %d",L[i]);
			printf("\n");
		}
		else puts("No solution.");
	}
	return 0;
}

