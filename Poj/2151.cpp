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
double P[1010][33];
double dp[1010][33][33];
double g[33];
int M,T,N;
void gao( double *P ) {
	int i,j;
	double dp[33][33];
	for ( i=0; i<=M; i++ )for ( j=0; j<=M; j++ )dp[i][j]=0;
	dp[0][0]=1;
	for ( int i=0; i<M; i++ )for ( int j=0; j<=i; j++ )if ( dp[i][j]>0 ) {
				dp[i+1][j+1]+=dp[i][j]*P[i+1];
				dp[i+1][j]+=dp[i][j]*( 1-P[i+1] );
			}
	for ( j=0; j<=M; j++ )g[j]=dp[M][j];
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,l;
	while ( ~scanf( "%d%d%d",&M,&T,&N ) ) {
		if ( !N&&!M&&!T )break;
		for ( i=1; i<=T; i++ )for ( j=1; j<=M; j++ )scanf( "%lf",&P[i][j] );
		gao( P[1] );
		for ( i=0; i<=T; i++ )for ( j=0; j<=M; j++ )for ( k=j; k<=M; k++ )dp[i][j][k]=0;
		for ( j=0; j<=M; j++ )dp[1][j][j]=g[j];
		for ( i=1; i<T; i++ ) {
			gao( P[i+1] );
			for ( j=0; j<=M; j++ )for ( k=j; k<=M; k++ )if ( dp[i][j][k]>0 ) {
						for ( l=0; l<=M; l++ )dp[i+1][min( l,j )][max( l,k )]+=dp[i][j][k]*g[l];
					}
		}
		double ans=0;
		for ( j=1; j<=M; j++ )for ( k=max( N,j ); k<=M; k++ )ans+=dp[T][j][k];
		printf( "%.3f\n",ans );
	}
	return 0;
}
