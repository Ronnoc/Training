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
	int dis( point p ) {return ( *this - p ).len();}
	double dis2( point p ) {p = p - ( *this ); return p*p;}//平方
	void in() {scanf( "lf", &x, &y );}
	void out() {printf( "%f %f\n",x,y );}
};
bool isLL( point p1, point p2, point q1, point q2, point &is ) {
	double m = ( q2 - q1 ) ^ ( p1 - q1 ), n = ( q2 - q1 ) ^ ( p2 - q1 );
	if ( sign( n - m ) == 0 ) return 0; //判直线平行，n=m=0时直线重合
	is = ( p1 * n - p2 * m ) / ( n - m );
	return 1;
}
double play(point a,point b,point c,point d){
	double ret=0;
	ret+=a^b;
	ret+=b^c;
	ret+=c^d;
	ret+=d^a;
	return fabs(ret)/2.0;
}
int main() {
	int i,j;
	int n;
	while ( ~scanf( "%d",&n )&&n ) {
		vector<point>L,R,U,D;
		L.PB( point( 0,0 ) ),D.PB( point( 0,0 ) );
		L.PB( point( 0,1 ) ),U.PB( point( 0,1 ) );
		R.PB( point( 1,0 ) ),D.PB( point( 1,0 ) );
		R.PB( point( 1,1 ) ),U.PB( point( 1,1 ) );
		for ( i=0; i<n; i++ ) {
			double x;
			scanf( "%lf",&x );
			D.PB( point( x,0 ) );
		}
		for ( i=0; i<n; i++ ) {
			double x;
			scanf( "%lf",&x );
			U.PB( point( x,1 ) );
		}
		for ( i=0; i<n; i++ ) {
			double x;
			scanf( "%lf",&x );
			L.PB( point( 0,x ) );
		}
		for ( i=0; i<n; i++ ) {
			double x;
			scanf( "%lf",&x );
			R.PB( point( 1,x ) );
		}
		SORT( L );
		SORT( R );
		SORT( U );
		SORT( D );
		point p[55][55];
		for ( i=0; i<D.SZ; i++ )for ( j=0; j<L.SZ; j++ )
				isLL( D[i],U[i],L[j],R[j],p[i][j] );
		double S=0;
		for(i=1;i<D.SZ;i++)for(j=1;j<L.SZ;j++)
			cmax(S,play(p[i-1][j-1],p[i-1][j],p[i][j],p[i][j-1]));
		printf("%.6f\n",S);
	}
	return 0;
}
