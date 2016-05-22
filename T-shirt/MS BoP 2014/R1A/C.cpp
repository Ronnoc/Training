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
double x[111111],y[111111];
int n;
double play( double a ) {
	double ret=0;
	for ( int i=1; i<=n; i++ )ret+=sqrt( SQ( x[i]-a )+SQ( y[i] ) );
	return ret;
}
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ )scanf( "%lf%lf",&x[i],&y[i] );
		double l=0,r=0;
		for ( i=1; i<=n; i++ )cmin( l,x[i] );
		for ( i=1; i<=n; i++ )cmax( r,x[i] );
		for ( int t=0; t<=50; t++ ) {
			double lmid=( r-l )/3+l;
			double rmid=r-( r-l )/3;
			double fl=play( lmid );
			double fr=play( rmid );
			if ( fl>fr )l=lmid;
			else r=rmid;
		}
		printf( "Case %d: %.8lf\n",CASE,( l+r )/2 );
	}
	return 0;
}
