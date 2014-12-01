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
const long double eps=1e-8;
const long double PI=acos( -1. );
const LL MOD = 1000000007;

long double dp[2][1555];
long double inv[1555];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	for(i=1;i<=1501;i++)inv[i]=((long double)1)/i;
	int n=100000,m=1;
	while(~scanf("%d%d",&n,&m)){
		memset(dp,0,sizeof dp);
		long double ans=0;
		dp[0][1]=1;
		for(i=0;i<n;i++){
			int x=i%2,y=(i+1)%2;
			int MX=600;
			for(j=1;j<=MX;j++)ans+=dp[x][j]*j*(inv[j+1]+inv[2]);
			for(j=1;j<=MX;j++)dp[y][j]=dp[x][j]*(1.-inv[j+1]*inv[m]);
			for(j=1;j<=MX;j++)dp[y][j+1]+=dp[x][j]*inv[j+1]*inv[m];
		}
		printf("%.16f\n",(double)ans);
	}
	return 0;
}
