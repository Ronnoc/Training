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
const double PI=acos( -1. );
const LL MOD = 1000000007;
LL dp[1010][1010],tp;
int K[1010][1010];
LL w[1010],a[1010];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=m;i++)scanf("%d",&w[i]);
		w[++m]=n,w[0]=0;
		for(i=1;i<=m;i++)a[i]=w[i]-w[i-1];
		memset(dp,-1,sizeof dp);
		for(i=1;i<=m;i++)dp[i][i]=0,K[i][i]=i;
		for(int r=1;r<=m;r++)for(i=1;i<=m-r;i++)
			for(k=K[i][i+r-1];k<=K[i+1][i+r];k++)
				if(dp[i][i+r]==-1||dp[i][k]+dp[k+1][i+r]+w[i+r]-w[i-1]<dp[i][i+r])
					dp[i][i+r]=dp[i][k]+dp[k+1][i+r]+w[i+r]-w[i-1],K[i][i+r]=k;
		cout<<dp[1][m]<<endl;
	}
	return 0;
}
