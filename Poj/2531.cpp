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
int a[22][22];
int dp[1<<20];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=0; i<n; i++ )for ( j=0; j<n; j++ )
				scanf( "%d",&a[i][j] );
		for ( i=0; i<n; i++ ) {
			dp[1<<i]=0;
			for ( j=0; j<n; j++ )dp[1<<i]+=a[i][j];
		}
		int all=( 1<<n )-1;
		int ans=dp[1];
		for ( i=0; i<1<<n; i++ ) {
			int len=__builtin_popcount( i );
			if ( len<=1 )continue;
			if ( ( all&( ~i ) )<i )dp[i]=dp[all-i];
			else {
				k=__builtin_ctz( i );
				int tmp=i&( ~( 1<<k ) );
				dp[i]=dp[tmp];
				while ( tmp ) {
					j=__builtin_ctz( tmp );
					dp[i]-=a[j][k];
					tmp&=~( 1<<j );
				}
				tmp=all&( ~i );
				while ( tmp ) {
					j=__builtin_ctz( tmp );
					dp[i]+=a[j][k];
					tmp&=~( 1<<j );
				}
			}
			cmax( ans,dp[i] );
		}
		printf( "%d\n",ans );
	}
	return 0;
}
