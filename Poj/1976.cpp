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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int w[50005];
int sum[50005];
int dp[4][50005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n,m;
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ )scanf( "%d",&w[i] );
		for ( sum[0]=0,i=1; i<=n; i++ )sum[i]=sum[i-1]+w[i];
		scanf( "%d",&m );
		memset( dp,0,sizeof dp );
		for ( i=0; i<3; i++ )for ( j=0; j<n; j++ ) {
				int d=min( j+m,n );
				cmax( dp[i][j+1],dp[i][j] );
				cmax( dp[i+1][d],dp[i][j]+sum[d]-sum[j] );
			}
		int ans=0;
		for ( i=0; i<=3; i++ )for ( j=0; j<=n; j++ )cmax( ans,dp[i][j] );
		printf( "%d\n",ans );
	}
	return 0;
}
