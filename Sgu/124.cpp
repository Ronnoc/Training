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
const double eps=1e-16;
const double INF=1e16;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;

int dcmp( double x ) {return x < -eps ? -1 : x > eps;}
struct point {
	double x, y;
	point() {}
	point( double _x, double _y ) : x( _x ), y( _y ) {}
	point operator - ( point p ) {return point( x - p.x, y - p.y );}
	point operator + ( point p ) {return point( x + p.x, y + p.y );}
	point operator / ( double d ) {return point( x / d, y / d );}
	point operator * ( double d ) {return point( x * d, y * d );}
	bool operator < ( const point &p )const {
		return dcmp( x - p.x ) == 0 ? dcmp( y - p.y ) <= 0 : dcmp( x - p.x ) <= 0;
	}
	double operator * ( point p ) {return x * p.y - y * p.x;} //²æ»ý
	double operator | ( point p ) {return x * p.x + y * p.y;} //µã»ý
	double len() {return hypot( x, y );}
	double arc() {return atan2( y, x );}
	point normal() {return ( *this ) / this->len();}
	point rotate() {return point( -y, x );}
	point rotate( double arc ) {
		return point( x * cos( arc ) - y * sin( arc ), x * sin( arc ) + y * cos( arc ) );
	}
	double dis( point p ) {return ( *this - p ).len();}
	double dis2( point p ) {p = p - ( *this ); return p|p;}
	void in() {scanf( "%lf%lf", &x, &y );}
	void out() {printf( "%f %f\n",x,y );}
} p[10010],q[10010],O;
bool crsSS( point p1, point p2, point q1, point q2 ) {
	if ( dcmp( min( q1.x, q2.x ) - max( p1.x, p2.x ) ) > 0 ) return false;
	if ( dcmp( min( p1.x, p2.x ) - max( q1.x, q2.x ) ) > 0 ) return false;
	if ( dcmp( min( q1.y, q2.y ) - max( p1.y, p2.y ) ) > 0 ) return false;
	if ( dcmp( min( p1.y, p2.y ) - max( q1.y, q2.y ) ) > 0 ) return false;
	int c1 = dcmp( ( p2 - p1 ) * ( q1 - p1 ) ),
			c2 = dcmp( ( p2 - p1 ) * ( q2 - p1 ) ),
			c3 = dcmp( ( q2 - q1 ) * ( p1 - q1 ) ),
			c4 = dcmp( ( q2 - q1 ) * ( p2 - q1 ) );
	return c1 * c2 <= 0 && c3 * c4 <= 0;
}
int n;
int main() {
	int i,j;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=1; i<=n; i++ ) {
			p[i].in(); q[i].in();
			if(p[i].y>q[i].y)swap(p[i],q[i]);
			if(p[i].x>q[i].x)swap(p[i],q[i]);
		}
		O.in();
		int border=0;
		for ( i=1; i<=n; i++ ) {
			if(p[i].x==q[i].x&&O.x==p[i].x){if(O.y>=p[i].y&&O.y<=q[i].y)border=1;}
			if(p[i].y==q[i].y&&O.y==p[i].y){if(O.x>=p[i].x&&O.x<=q[i].x)border=1;}
		}
		if ( border ) {printf( "BORDER\n" ); continue;}
		point I=point(-10000-sqrt(2),-10000-sqrt(3));
		int cnt=0;
		for ( i=1; i<=n; i++ ) 
			if(crsSS(p[i],q[i],O,I))cnt++;
		if ( cnt%2==0 )printf( "OUTSIDE\n" );
		else printf( "INSIDE\n" );
	}
	return 0;
}
