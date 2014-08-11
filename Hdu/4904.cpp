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
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
int x[111],y[111];
int sign( double x ) {return x<-eps?-1:x>eps;}
struct point {
	double x, y;
	point() {}
	point( double _x, double _y ) : x( _x ), y( _y ) {}
	point operator - ( const point p ) const {return point( x - p.x, y - p.y );}//{-,*,/}
	point operator + ( const point p ) const {return point( x+p.x,y+p.y );}
	point operator * ( const double d )const {return point( x*d,y*d );}
	point operator / ( const double d )const {return point( x/d,y/d );}
	bool operator < ( const point &p ) const {
		return sign( x - p.x ) == 0 ? sign( y - p.y ) <= 0 : sign( x - p.x ) <= 0;
	}
	double operator ^( const point &p )const {return x*p.y-y*p.x;} //叉积
	double operator *( const point &p )const {return x*p.x+y*p.y;} //点积
	double len() {return sqrt( x*x+y*y );}
	double arc() {return atan2( y, x );}
	point normal() {return ( *this ) / this->len();}
	point rotate() {return point( -y, x );}
	point rotate( double arc )
	{return point( x*cos( arc ) - y*sin( arc ),x*sin( arc ) + y*cos( arc ) );}
	double dis( point p ) {return ( *this - p ).len();}
	double dis2( point p ) {p = p - ( *this ); return p*p;}//平方
	void in() {scanf( "%lf%lf", &x, &y );}
	void out( char *s="" ) {printf( "(%f,%f)%s",x,y,s );}
} ORI( 0,0 );
bool isLL( point p1, point p2, point q1, point q2 ,point &is ) {
	double m=( q2-q1 )^( p1-q1 ),n=( q2-q1 )^( p2-q1 );
	if ( sign( n-m )==0 )return 0;
	is= ( p1*n-p2*m )/( n-m );
	return 1;
}
vector<point> convexCut( const vector<point>&ps, point q1, point q2 ) {
	vector<point> qs;
	int n = ps.size();
	for ( int i = 0; i < n; ++i ) {
		point p1 = ps[i], p2 = ps[( i + 1 ) % n];
		int d1 = sign( ( q2-q1 )^( p1-q1 ) ), d2 = sign( ( q2-q1 )^( p2-q1 ) );
		if ( d1 >= 0 )
			qs.PB( p1 );
		if ( d1 * d2 < 0 ) {
			point is;
			int flag=isLL( p1, p2, q1, q2,is );
			if ( flag )qs.PB( is );
		}
	}
	return qs;
}
double calcArea( const vector<point>&ps ) {
	int n = ps.size();
	double ret = 0;
	for ( int i = 0; i < n; ++i ) {
		ret += ps[i]^ps[( i + 1 ) % n];
	}
	return ret / 2;
}
point A[111];
bool online( point is,point p,point q ) {
	if ( sign( is.x-min( p.x,q.x ) )>=0&&
			 sign( is.y-min( p.y,q.y ) )>=0&&
			 sign( is.x-max( p.x,q.x ) )<=0&&
			 sign( is.y-max( p.y,q.y ) )<=0 )return 1;
	return 0;
}
double cut( vector<point>&R,double x ) {
	double ly=1e100,ry=-1e100;
	int m=R.SZ;
	point is;
	R[m++]=R[0];
	for ( int i=0; i+1<m; i++ ) {
		int flag =isLL( R[i],R[i+1],point( x,0 ),point( x,1 ),is );
		if ( flag&&online( is,R[i],R[i+1] ) ) {
			cmax( ry,is.y );
			cmin( ly,is.y );
		}
	}
	return ry-ly;
}
double play( vector<point>&R,double x ) {
	vector<double>t;
	int m=R.SZ;
	int i,j;
	for ( i=0; i<m; i++ )t.PB( R[i].x );
	SORT( t );
	double ret=0;
	for ( i=1; i<t.SZ; i++ ) {
		double a=t[i-1],d=t[i];
		double b=a+( d-a )/3,c=d-( d-a )/3;
		double fa=cut( R,a ),fb=cut( R,b ),fc=cut( R,c ),fd=cut( R,d );
		double add=0;
		add+=SQ( a-x )*fa;
		add+=SQ( b-x )*fb*3;
		add+=SQ( c-x )*fc*3;
		add+=SQ( d-x )*fd;
		add*=( d-a )/8;
		ret+=add;
	}
	return ret;
}
vector<point> addline( const vector<point>&ps,point p,point q ) {
	point r=( p+q )/2;
	point d=( q-p ).rotate();
	return convexCut( ps,r,r+d );
}
vector<point>R;
int main() {
//	freopen( "1008.in","r",stdin );
//	freopen( "m1008.out","w",stdout );
	int i,j,k;
	int T;
	scanf( "%d",&T );
	while ( T-- ) {
		int n,m,X,Y;
		scanf( "%d%d%d",&n,&X,&Y );
		for ( i=0; i<n; i++ )
			scanf( "%d%d",&x[i],&y[i] );
		for ( i=0; i<n; i++ )A[i]=point( x[i],y[i] );
		double S=X*Y,Ans=0;
		for ( i=0; i<n; i++ ) //nearest
			for ( j=0; j<n; j++ )if ( i!=j ) {
					R.clear();
					R.PB( point( 0,0 ) );
					R.PB( point( X,0 ) );
					R.PB( point( X,Y ) );
					R.PB( point( 0,Y ) );
					R=addline( R,A[i],A[j] );
					for ( k=0; k<n; k++ )if ( k!=i&&k!=j ) {
							if ( sign( calcArea( R ) )<=0 )break;
							R=addline( R,A[i],A[k] );
							if ( sign( calcArea( R ) )<=0 )break;
							R=addline( R,A[j],A[k] );
						}
					Ans+=play( R,A[j].x );
					for ( k=0; k<R.SZ; k++ )swap( R[k].x,R[k].y );
					Ans+=play( R,A[j].y );
				}
		printf( "%.10f\n",Ans/S );
	}
	return 0;
}
