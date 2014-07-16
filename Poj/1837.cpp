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
int dp[22][30100];
int p[22],q[22];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int C,G;
	while ( ~scanf( "%d%d",&C,&G ) ) {
		for ( i=1; i<=C; i++ )scanf( "%d",&p[i] );
		for ( i=1; i<=G; i++ )scanf( "%d",&q[i] );
		memset( dp,0,sizeof dp );
		dp[0][15000]=1;
		for ( i=0; i<G; i++ )for ( j=0; j<=30000; j++ )if ( dp[i][j] )
					for ( k=1; k<=C; k++ )dp[i+1][j+p[k]*q[i+1]]+=dp[i][j];
		printf( "%d\n",dp[G][15000] );
	}
	return 0;
}
