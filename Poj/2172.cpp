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
bool can( double p,double q,double d,double e ) {
//	cout<<p<<" "<<q<<" "<<d<<" "<<e<<"~"<<endl;
	double x,r=sqrt( SQ( p/2 )+SQ( q/2 ) );
	if ( r<e/2 )x=0;
	else x=-sqrt( SQ( r )-SQ( e/2 ) );
	if ( x<-d/2 )return 0;
	double alpha=atan2( q,p );
	double beta=atan2( e/2,x );
	beta+=2*alpha;
	double xx=r*cos( beta );
	double yy=r*sin( beta );
	if ( xx<-d/2 )return 0;
	if ( xx>d/2 )return 0;
	if ( yy<-e/2 )return 0;
	if ( yy>e/2 )return 0;
	return 1;
}
int main() {
	int i, j;
//	freopen( "bricks.in", "r", stdin );
//	freopen( "bricks.out", "w", stdout );
	double a[5],d,e;
	while ( ~scanf( "%lf",&a[0] ) ) {
		for ( i=1; i<3; i++ )scanf( "%lf",&a[i] );
		scanf( "%lf%lf",&d,&e );
		sort( a,a+3 );
		if ( d<e )swap( d,e ); //d>e
//		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<d<<" "<<e<<endl;
		int flag=0;
		if ( a[0]<=e&&a[1]<=d )flag=1;
		for ( i=0; i<3; i++ )if ( can( a[i],a[( i+1 )%3],d,e ) )flag=1;
		for ( i=0; i<3; i++ )if ( can( a[( i+1 )%3],a[i],d,e ) )flag=1;
		for ( i=0; i<3; i++ )if ( can( a[i],a[( i+1 )%3],e,d ) )flag=1;
		for ( i=0; i<3; i++ )if ( can( a[( i+1 )%3],a[i],e,d ) )flag=1;
		printf( "%s\n",flag?"YES":"NO" );
	}
	return 0;
}
/*
130 130 1 100 100
1.0 2.0 1.5 1.4 1.0
1.0 2.0 1.5 1.5 1.0
1 1 1 10 10
150 150 1 100 100
130 130 1 100 100
*/
