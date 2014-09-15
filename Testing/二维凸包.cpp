//poj2187
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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define SZ size()

typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
	int dcmp( double x ) {return x < -eps ? -1 : x > eps;}
	struct point {
		double x, y;
		point() {}
		point( double _x, double _y ) : x( _x ), y( _y ) {}
		point operator - ( point p ) {return point( x - p.x, y - p.y );}
		point operator + ( point p ) {return point( x + p.x, y + p.y );}
		point operator / ( double d ) {return point( x / d, y / d );}
		point operator * ( double d ) {return point( x * d, y * d );}
		bool operator < ( const point &p ) const {
			return dcmp( x - p.x ) == 0 ? dcmp( y - p.y ) <= 0 : dcmp( x - p.x ) <= 0;
		}
		double operator ^( const point &p )const {return x*p.y-y*p.x;} //叉积
		double operator *( const point &p )const {return x*p.x+y*p.y;} //点积
		int len() {return sqrt( x*x+y*y );}
		double arc() {return atan2( y, x );}
		point normal() {return ( *this ) / this->len();}
		point rotate() {return point( -y, x );}
		point rotate( double arc )
		{return point( x*cos( arc ) - y*sin( arc ),x*sin( arc ) + y*cos( arc ) );}
		int dis( point p ) {return ( *this - p ).len();}
		double dis2( point p ) {p = p - ( *this ); return p*p;}//平方
		void in() {scanf( "%lf%lf", &x, &y );}
		void out() {printf( "%f %f\n",x,y );}
	};
	/*求凸包,逆时针*/
	vector<point> ConvexHull( vector<point> p ) {
		int n = p.size(), m = 0;
		vector<point> q;
		q.resize( n * 2 );
		sort( p.begin(), p.end() );
		for ( int i = 0; i < n; i ++ ) {
			while ( m > 1 && dcmp( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) )
							<= 0 )
				m -- ;
			q[m ++ ] = p[i];
		}
		int k = m;
		for ( int i = n - 2; i >= 0; i -- ) {
			while ( m > k && dcmp( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) )
							<= 0 )
				m -- ;
			q[m ++ ] = p[i];
		}
		if ( n > 1 ) m -- ;
		q.resize( m );
		return q;
	}
	int ConvecDiameter( vector<point> p ) {
		int n = p.size(), j = 1;
		int maxd = 0;
		p.push_back( p[0] );
		for ( int i = 0; i < n; i ++ ) {
			while ( ( ( p[i + 1] - p[i] ) ^ ( p[j + 1] - p[i] ) )
							> ( ( p[i + 1] - p[i] ) ^ ( p[j] - p[i] ) ) )
				j = ( j + 1 ) % n;
			maxd = max( maxd, max( p[i].dis( p[j] ), p[i + 1].dis( p[j + 1] ) ) );
		}
		return maxd;
	}
void solve() {
	int n;
	while ( ~scanf( "%d",&n ) ) {
		int i,_x,_y;
		vector<point>p,q;
		for ( i=1; i<=n; ++i ) {
			scanf( "%d%d",&_x,&_y );
			q.PB( point( _x,_y ) );
		}
		p=ConvexHull( q );
		int res=ConvecDiameter( p );
		printf( "%d\n",res );
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
