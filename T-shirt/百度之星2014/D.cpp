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
const int MOD = 1000000007;
int w[1111][1111];
int dp[1111][1111];
int main() {
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int m,n;
		scanf( "%d%d",&m,&n );
		for ( i=1; i<=m; i++ )for ( j=1; j<=n; j++ )
				scanf( "%d",&w[i][j] );
		for ( i=1; i<=m; i++ )for ( j=1; j<=n; j++ )dp[i][j]=-MOD;
		dp[1][1]=w[1][1];
		for ( i=2; i<=m; i++ )dp[i][1]=dp[i-1][1]+w[i][1];
		for ( j=1; j<n; j++ )for ( i=1; i<=m; i++ ) {
				int now=dp[i][j];
				for ( k=i; k>=1; k-- ) {
					now+=w[k][j+1];
					cmax( dp[k][j+1],now );
				}
				now=dp[i][j];
				for ( k=i; k<=m; k++ ) {
					now+=w[k][j+1];
					cmax( dp[k][j+1],now );
				}
			}
		printf( "Case #%d:\n",CASE );
		printf( "%d\n",dp[1][n] );
	}
	return 0;
}
