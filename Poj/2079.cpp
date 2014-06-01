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
int sign( double x ) {return x < -eps ? -1 : x > eps;}
struct point {
	double x, y;
	point() {}
	point( double _x, double _y ) : x( _x ), y( _y ) {}
	point operator - ( const point &p ) const {return point( x - p.x, y - p.y );}
	point operator + ( const point &p ) const {return point( x + p.x, y + p.y );}
	point operator * ( const double &d ) const {return point( x*d,y*d );}
	point operator / ( const double &d ) const {return point( x/d,y/d );}
	bool operator < ( const point &p ) const {
		return sign( x - p.x ) == 0 ? sign( y - p.y ) <= 0 : sign( x - p.x ) <= 0;
	}
	double operator ^( const point &p )const {return x*p.y-y*p.x;} //叉积
	double operator *( const point &p )const {return x*p.x+y*p.y;} //点积
	int len() {return sqrt( x*x+y*y );}
	double arc() {return atan2( y, x );}
	point normal() {return ( *this ) / this->len();}
	point rotate() {return point( -y, x );}
	point rotate( double arc )
	{return point( x*cos( arc ) - y*sin( arc ),x*sin( arc ) + y*cos( arc ) );}
	double dis( point p ) {return ( *this - p ).len();}
	double dis2( point p ) {p = p - ( *this ); return p*p;}//平方
	void in() {scanf( "%lf%lf", &x, &y );}
	void out() {printf( "%f %f\n",x,y );}
} O( 0,0 );
vector<point> ConvexHull( vector<point> p ) {
	int n = p.size(), m = 0;
	vector<point> q;
	q.resize( n * 2 );
	sort( p.begin(), p.end() );
	for ( int i = 0; i < n; i ++ ) {
		while ( m > 1 && sign( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) )<= 0 )
			m -- ;
		q[m ++ ] = p[i];
	}
	int k = m;
	for ( int i = n - 2; i >= 0; i -- ) {
		while ( m > k && sign( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) )<= 0 )
			m -- ;
		q[m ++ ] = p[i];
	}
	if ( n > 1 ) m -- ;
	q.resize( m );
	return q;
}
double Stri( point A,point B,point C ) {
	return fabs( ( A^B )+( B^C )+( C^A ) )/2;
}
double ConvecDiameter( vector<point> p ) {
	int n = p.size();
	double maxd = 0;
	if ( p.SZ<3 )return 0;
	int j=p.SZ-1,k=1;
	for ( int i = 0; i < n; i ++ ) {
		int flag=1;
		while ( flag ) {
			flag=0;
			while ( sign( Stri( p[i],p[( j+1+n )%n],p[k] )-Stri( p[i],p[j],p[k] ) )>0 )
				j=( j+1+n )%n,flag=1;
			while ( sign( Stri( p[i],p[( j-1+n )%n],p[k] )-Stri( p[i],p[j],p[k] ) )>0 )
				j=( j-1+n )%n,flag=1;
			while ( sign( Stri( p[i],p[j],p[( k+1+n )%n] )-Stri( p[i],p[j],p[k] ) )>0 )
				k=( k+1+n )%n,flag=1;
			while ( sign( Stri( p[i],p[j],p[( k-1+n )%n] )-Stri( p[i],p[j],p[k] ) )>0 )
				k=( k-1+n )%n,flag=1;
		}
		cmax( maxd, Stri( p[i],p[j],p[k] ) );
	}
	return maxd;
}
vector<point>L,p;
int main() {
	int i,j,n;
	while ( ~scanf( "%d",&n )&&n>=0 ) {
		p.clear();
		for ( i=0; i<n; i++ ) {
			O.in();
			p.PB( O );
		}
		L=ConvexHull( p );
		printf( "%.2f\n",ConvecDiameter( L ) );
	}
	return 0;
}
