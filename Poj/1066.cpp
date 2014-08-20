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
const double PI=acos ( -1. );
const LL MOD = 1000000007;
int sign ( double x ) {return x<-eps?-1:x>eps;}
struct point {
	double x, y;
	point() {}
	point ( double _x, double _y ) : x ( _x ), y ( _y ) {}
	point operator - ( const point p ) const {return point ( x - p.x, y - p.y );} //{-,*,/}
	point operator + ( const point p ) const {return point ( x+p.x,y+p.y );}
	point operator * ( const double d ) const {return point ( x*d,y*d );}
	point operator / ( const double d ) const {return point ( x/d,y/d );}
	bool operator < ( const point &p ) const {
		return sign ( x - p.x ) == 0 ? sign ( y - p.y ) <= 0 : sign ( x - p.x ) <= 0;
	}
	double operator ^ ( const point &p ) const {return x*p.y-y*p.x;} //叉积
	double operator * ( const point &p ) const {return x*p.x+y*p.y;} //点积
	double len() {return sqrt ( x*x+y*y );}
	double arc() {return atan2 ( y, x );}
	point normal() {return ( *this ) / this->len();}
	point rotate() {return point ( -y, x );}
	point rotate ( double arc )
	{return point ( x*cos ( arc ) - y*sin ( arc ),x*sin ( arc ) + y*cos ( arc ) );}
	double dis ( point p ) {return ( *this - p ).len();}
	double dis2 ( point p ) {p = p - ( *this ); return p*p;} //平方
	void in() {scanf ( "%lf%lf", &x, &y );}
	void out ( char *s="" ) {printf ( "(%f,%f)%s",x,y,s );}
} Orz ( 0,0 );
bool isLL ( point p1, point p2, point q1, point q2 ,point &is ) {
	double m= ( q2-q1 ) ^ ( p1-q1 ),n= ( q2-q1 ) ^ ( p2-q1 );
	if ( sign ( n-m ) ==0 ) return 0;
	is= ( p1*n-p2*m ) / ( n-m );
	return 1;
}
point u[33],v[33],w;
bool fitin ( point w,point u,point v ) {
	if ( sign ( w.x-min ( u.x,v.x ) ) <0 ) return 0;
	if ( sign ( w.x-max ( u.x,v.x ) ) >0 ) return 0;
	if ( sign ( w.y-min ( u.y,v.y ) ) <0 ) return 0;
	if ( sign ( w.y-max ( u.y,v.y ) ) >0 ) return 0;
	return 1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while ( ~scanf ( "%d",&n ) ) {
		vector<point>L;
		for ( i=0; i<n; i++ ) {
			u[i].in();
			v[i].in();
			L.PB ( u[i] );
			L.PB ( v[i] );
		}
		w.in();
		int ans=n+1;
		for ( i=0; i<L.SZ; i++ ) {
			vector<point>IS;
			point is;
			for ( j=0; j<n; j++ ) {
				int k=isLL ( u[j],v[j],w,L[i],is );
				if ( !k ) continue;
				if ( !fitin ( is,u[j],v[j] ) ) continue;
				if ( !fitin ( is,w,L[i] ) ) continue;
				IS.PB ( is );
			}
			cmin ( ans, ( int ) IS.SZ );
		}
		printf ( "Number of doors = %d\n",ans );
	}
	return 0;
}
