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

LL dp[22][1<<4][4][2];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	memset(dp,0,sizeof dp);
	for(i=0;i<4;i++)dp[1][1<<i][i][0]=1;
	for(i=1;i<17;i++)for(j=0;j<1<<4;j++)for(k=0;k<4;k++)for(u=0;u<2;u++)if(dp[i][j][k][u])
		for(v=0;v<4;v++)dp[i+1][j|(1<<v)][v][u|(max(v,k)-min(v,k))==3]+=dp[i][j][k][u];
	while(~scanf("%d",&n)&&~n){
		LL ans=0;
		for(j=0;j<1<<4;j++)if(__builtin_popcount(j)>=3)
			for(k=0;k<4;k++)ans+=dp[n][j][k][1];
		printf("%d: %I64d\n",n,ans);
	}
	return 0;
}
