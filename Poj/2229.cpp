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
const LL MOD = 1000000000;
int dp[20][1000005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T,n;
	for(i=0;i<=1000000;i++)dp[0][i]=1;
	for(k=1;k<=19;k++){
		for(i=0;i<1<<k;i++)dp[k][i]=dp[k-1][i];
		for(i=1<<k;i<=1000000;i++){
			dp[k][i]=dp[k-1][i]+dp[k][i-(1<<k)];
			if(dp[k][i]>=MOD)dp[k][i]-=MOD;
		}
	}
	while(~scanf("%d",&n))printf("%d\n",dp[19][n]);
	return 0;
}
