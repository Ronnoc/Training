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
	double len() {return sqrt( x*x+y*y );}
	double arc() {return atan2( y, x );}
	point normal() {return ( *this ) / this->len();}
	point rotate() {return point( -y, x );}
	point rotate( double arc )
	{return point( x*cos( arc ) - y*sin( arc ),x*sin( arc ) + y*cos( arc ) );}
	double dis( point p ) {return ( *this - p ).len();}
	double dis2( point p ) {p = p - ( *this ); return p*p;}//平方
	void in() {cin>>x>>y;}
	void out() {printf( "%f %f\t",x,y );}
} U[22],D[22];
bool isLL( point p1, point p2, point q1, point q2, point &is ) {
	double m = ( q2 - q1 ) ^ ( p1 - q1 ), n = ( q2 - q1 ) ^ ( p2 - q1 );
	if ( sign( n - m ) == 0 ) return 0; //判直线平行，n=m=0时直线重合
	is = ( p1 * n - p2 * m ) / ( n - m );
	return 1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while ( cin>>n&&n ) {
		for ( i=0; i<n; i++ )U[i].in();
		for ( i=0; i<n; i++ )D[i]=U[i]-point( 0,1 );
		vector<point>L;
		for ( i=0; i<n; i++ )L.PB( U[i] );
		for ( i=0; i<n; i++ )L.PB( D[i] );
		SORT( L );
		int flag=0;
		double ans=U[0].x;
		for ( i=0; !flag&&i<L.SZ; i++ )for ( j=i+1; !flag&&j<L.SZ; j++ ) {
				point is;
				bool s=isLL( U[0],D[0],L[i],L[j],is );
				if ( !s )continue;
				if ( sign( U[0].y-is.y )<0||sign( is.y-D[0].y )<0 )continue;
				for ( k=1; k<n; k++ ) {
					s=isLL( U[k],D[k],L[i],L[j],is );
					if ( s&&( sign( U[k].y-is.y )<0||sign( is.y-D[k].y )<0 ) ) {
						isLL( U[k-1],U[k],L[i],L[j],is );
						cmax( ans,is.x );
						isLL( D[k-1],D[k],L[i],L[j],is );
						cmax( ans,is.x );
						break;
					}
				}
				if ( k==n )flag=1;
			}
		if ( flag )printf( "Through all the pipe.\n" );
		else printf( "%.2f\n",ans );
	}
	return 0;
}
