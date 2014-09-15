//hdu 3007
//n个点的最小圆覆盖
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
int Sign( double x ) {return x<-eps?-1:x>eps;}
struct point {
	double x,y;
	point() {}
	point( double _x,double _y ):x( _x ),y( _y ) {}
	point operator +( const point &p )const {return point( x+p.x,y+p.y );}
	point operator -( const point &p )const {return point( x-p.x,y-p.y );}
	point operator *( const double &d )const {return point( x*d,y*d );}
	point operator /( const double &d )const {return point( x/d,y/d );}
	double len()const {return sqrt( SQ( x )+SQ( y ) );}
	double operator *( const point &p )const {return x*p.x+y*p.y;} //点积
	double operator ^( const point &p )const {return x*p.y-y*p.x;} //叉积
	void output() {printf( "%.6f %.6f\n",x,y );}
	bool operator < ( const point &p )const {
		return MP( x,y )<MP( p.x,p.y );
	}
} ORI( 0,0 );
struct circle {
	point ct;
	double r;
	circle( point a,point b ) {
		ct=( a+b )/2;
		r=( b-a ).len()/2;
	}
	circle( point o,double rr ):ct( o ),r( rr ) {}
	circle( point a,point b,point c ) {
		double A,B,C,D,E,F;
		A=2*a.x-2*b.x;
		B=2*a.y-2*b.y;
		C=SQ( a.len() )-SQ( b.len() );
		D=2*a.x-2*c.x;
		E=2*a.y-2*c.y;
		F=SQ( a.len() )-SQ( c.len() );
		ct.x=( C*E-B*F )/( A*E-B*D );
		ct.y=( A*F-C*D )/( A*E-B*D );
		r=( a-ct ).len();
	}
	bool operator > ( const point a )const {
		return Sign( ( a-ct ).len()-r )<=0;
	}
};
circle minCircle( vector<point>&L ) {
	circle ans( point( 0,0 ),0 );
	int i,j,k;
	for ( i=2; i<L.SZ; i++ )if ( !( ans>L[i] ) ) {
			ans=circle( L[0],L[i] );
			for ( j=1; j<i; j++ )if ( !( ans>L[j] ) ) {
					ans=circle( L[i],L[j] );
					for ( k=0; k<j; k++ )if ( !( ans>L[k] ) )
							ans=circle( L[i],L[j],L[k] );
				}
		}
	return ans;
}
int main() {
	int i,j,k,n;
	while ( ~scanf( "%d",&n )&&n ) {
		vector<point>L;
		double x,y;
		for ( i=1; i<=n; i++ ) {
			scanf( "%lf%lf",&x,&y );
			L.PB( point( x,y ) );
		}
		circle ans=minCircle( L );
		printf( "%.2f %.2f %.2f\n",ans.ct.x,ans.ct.y,ans.r );
	}
	return 0;
}
