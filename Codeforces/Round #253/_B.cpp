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
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	scanf( "%d",&n );
	double p[111];
	double dp[111][2][5];
	for ( i=0; i<=n; i++ )
		for ( j=0; j<2; j++ )
			for ( int k=0; k<3; k++ )
				dp[i][j][k]=0;
	for ( k=0; k<3; k++ )dp[0][0][k]=1;
	for ( i=1; i<=n; i++ )scanf( "%lf",&p[i] );
	sort( p+1,p+1+n );
	reverse( p+1,p+1+n );
	for ( i=0; i<n; i++ ) {
		double q=p[i+1];
		for ( j=0; j<2; j++ )for ( k=0; k<3; k++ )dp[i+1][j][k]=dp[i][j][k];
		vector<pair<double,double> >L;
		for ( k=0; k<3; k++ )
			L.PB( MP( dp[i][0][k]*( 1-q ),dp[i][0][k]*q+dp[i][1][k]*( 1-q ) ) );
		for ( j=0; j<L.SZ; j++ )
			if ( L[j].BB>dp[i+1][1][0] )
				dp[i+1][0][0]=L[j].AA,dp[i+1][1][0]=L[j].BB;
		for ( j=0; j<L.SZ; j++ )
			if ( L[j].BB+L[j].AA>dp[i+1][1][1]+dp[i+1][0][1] )
				dp[i+1][0][1]=L[j].AA,dp[i+1][1][1]=L[j].BB;
		for ( j=0; j<L.SZ; j++ )
			if ( L[j].AA>dp[i+1][0][2] )
				dp[i+1][0][2]=L[j].AA,dp[i+1][1][2]=L[j].BB;
	}
	printf( "%.15lf\n",max( dp[n][1][0],dp[n][1][1] ) );
	return 0;
}
