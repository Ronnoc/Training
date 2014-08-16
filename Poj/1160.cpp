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
int dp[2][33][303];
int cc[303][303];
void update( int &A,int B ) {
	if ( ~A )cmin( A,B );
	else A=B;
}
int x[303];
int cal( int l,int r ) {
	int &ret=cc[l][r];
	if ( ~ret )return ret;
	ret=0;
	for ( int i=l+1; i<r; i++ )ret+=min( abs( x[i]-x[l] ),abs( x[i]-x[r] ) );
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int V,P;
	while ( ~scanf( "%d%d",&V,&P ) ) {
		for ( x[0]=-100000,i=1; i<=V; i++ )
			scanf( "%d",&x[i] );
		sort( x+1,x+1+V );
		x[V+1]=MOD;
		memset( dp,-1,sizeof dp );
		dp[0][0][0]=0;
		memset( cc,-1,sizeof cc );
		int x=0,y=1;
		for ( i=0; i<=V; i++ ) {
			memset(dp[y],-1,sizeof dp[y]);
			for ( j=0; j<=P&&j<=i; j++ )for ( k=0; k<=i; k++ )if ( ~dp[x][j][k] ) {
						update( dp[y][j][k],dp[x][j][k] );
						if ( j+1<=P )update( dp[y][j+1][i+1],dp[x][j][k]+cal( k,i+1 ) );
					}
			swap(x,y);
		}
		int ans=dp[x][P][0];
		for ( i=1; i<=V; i++ )update( ans,dp[x][P][i]+cal( i,V+1 ) );
		printf( "%d\n",ans );
	}
	return 0;
}
