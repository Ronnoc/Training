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
int sign( double x ) {return x<-eps?-1:x>eps;}
struct point {
	double x,y;
	point() {}
	point( double _x,double _y ):x( _x ),y( _y ) {}
	point operator - ( const point &p )const {return point( x-p.x,y-p.y );}
	point operator + ( const point &p )const {return point( x+p.x,y+p.y );}
	point operator * ( const double &p )const {return point( x*p,y*p );}
	point operator / ( const double &p )const {return point( x/p,y/p );}
	bool operator < ( const point &p )const {return sign( x-p.x )==0?sign( y-p.y )<=0:sign( x-p.x )<=0;}
	double operator ^( const point &p )const {return x*p.y-y*p.x;}
	double operator *( const point &p )const {return x*p.x+y*p.y;}
	double len() {return sqrt( SQ( x )+SQ( y ) );}
};
vector<point> ConvexHull( vector<point>p ) {
	int n=p.SZ,m=0;
	vector<point>q;
	q.resize( n*2 );
	sort( p.OP,p.ED );
	for ( int i=0; i<n; i++ ) {
		while ( m>1&&sign( ( q[m-1]-q[m-2] )^( p[i]-q[m-2] ) )<=0 )m--;
		q[m++]=p[i];
	}
	int k=m;
	for ( int i=n-2; i>=0; i-- ) {
		while ( m>k&&sign( ( q[m-1]-q[m-2] )^( p[i]-q[m-2] ) )<=0 )m--;
		q[m++]=p[i];
	}
	if ( n>1 )m--;
	q.resize( m );
	return q;
}
vector<point>L,C;
bool can( point a,double r,double h ) {
	return sign( a.x/r+a.y/h-1 )<=0;
}
int main() {
	int i,j;
//	freopen( "dome.in", "r", stdin );
//	freopen( "dome.out", "w", stdout );
	int n;
	while ( cin>>n ) {
		L.clear();
		L.PB( point( 0,0 ) );
		for ( i=0; i<n; i++ ) {
			double x,y,z;
			cin>>x>>y>>z;
			x=sqrt( SQ( x )+SQ( y ) );
			L.PB( point( x,z ) );
		}
		C=ConvexHull( L );
//		for(i=0;i<C.SZ;i++){
//			cout<<C[i].x<<","<<C[i].y<<endl;
//		}
		double V=1e100,R=-1,H=-1;
		for ( i=0; i<C.SZ; i++ ) {
			point a=C[( i+C.SZ-1 )%C.SZ];
			point b=C[( i+1 )%C.SZ];
			double x=C[i].x,y=C[i].y;
			double r=1.5*x,h=3*y;
			double v=PI*r*r*h/3;
			if ( can( a,r,h )&&can( b,r,h )&&V>v )
				V=v,R=r,H=h;
			double x1=C[i].x,y1=C[i].y;
			double x2=C[( i+1 )%C.SZ].x,y2=C[( i+1 )%C.SZ].y;
			double yy=( x2*y1-x1*y2 )/( x2-x1 );
			double xx=( x1*y2-x2*y1 )/( y2-y1 );
//			cout<<i<<" "<<xx<<" "<<yy<<endl;
			if ( sign( x1-x2 )&&sign( y1-y2 )&&xx>eps&&yy>eps ) {
				double v=PI*xx*xx*yy/3;
				if ( V>v )V=v,R=xx,H=yy;
			}
		}
		printf( "%.3f %.3f\n",H,R );
	}
	return 0;
}
/*
1
1.00 0.00 1.00
2
1.00 0.00 1.00
0.00 1.50 0.50
3
1.00 0.00 1.00
0.00 1.50 0.50
-0.50 -0.50 1.00
2
1.00 0.00 1.00
0 0 5
2
1 2 0.00001
1 0 1
*/
