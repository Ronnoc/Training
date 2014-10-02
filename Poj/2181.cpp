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


int dp[150005][2];
int v[150005],n;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)scanf("%d",&v[i]);
		dp[0][0]=dp[0][1]=0;
		int ans=0;
		for(i=1;i<=n;i++){
			dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][1];
			cmax(dp[i][0],dp[i-1][1]-v[i]);
			cmax(dp[i][1],dp[i-1][0]+v[i]);
			cmax(ans,dp[i][0]);
			cmax(ans,dp[i][1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
