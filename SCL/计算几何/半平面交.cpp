//poj 2451
//在边长为10000的正方形内nlgn半平面交
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
const double PI=acos( -1. );
const int MXN = 50;
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
} ORI( 0,0 );
	struct line {
		point u,v;//u->v的左边
		double arc;
		line() {}
		line( point _u,point _v ):u( _u ),v( _v )
		{arc=atan2( v.y-u.y,v.x-u.x );}
		bool operator <( const line &L )const {return arc<L.arc;}
	};
	bool OnLeft( line l,point p ) {
		return ( ( l.v-l.u )^( p-l.u ) )>0;
	}
	bool LLCross( point p1, point p2, point q1, point q2, point &is ) {
		double m=( q2-q1 )^( p1-q1 ),n=( q2-q1 )^( p2-q1 );
		if ( Sign( n-m )==0 )return 0;
		is=( p1*n-p2*m )/( n-m );
		return 1;
	}
	int HalfPlaneCross( line *l,int n,point *poly ) {
		sort( l,l+n );
		int first,last;
		point p[n];
		line q[n];
		q[first=last=0]=l[0];
		for ( int i=1; i<n; i++ ) {
			while ( first<last&&!OnLeft( l[i],p[last-1] ) )last--;
			while ( first<last&&!OnLeft( l[i],p[first] ) )first++;
			q[++last]=l[i];
			if ( Sign( ( q[last].v-q[last].u )^( q[last-1].v-q[last-1].u ) )==0 ) {
				last--;
				if ( OnLeft( q[last],l[i].u ) )
					q[last]=l[i];
			}
			if ( first<last )
				LLCross( q[last - 1].u, q[last - 1].v, q[last].u, q[last].v, p[last - 1] );
		}
		while ( first<last&&!OnLeft( q[first],p[last-1] ) )last--;
		if ( last-first<=1 )return 0;
		LLCross( q[first].u,q[first].v,q[last].u,q[last].v,p[last] );
		int m=0;
		for ( int i=first; i<=last; i++ )
			poly[m++]=p[i];
		return m;
	}
line T[44444];
point P[44444];
int main() {
	int i,j;
	point Z( 0,0 ),A( 0,10000 ),S( 10000,10000 ),X( 10000,0 );
	int n;
	while ( ~scanf( "%d",&n ) ) {
		int Tcnt=0;
		T[Tcnt++]=line( Z,X );
		T[Tcnt++]=line( X,S );
		T[Tcnt++]=line( S,A );
		T[Tcnt++]=line( A,Z );
		for ( i=1; i<=n; i++ ) {
			double p,q,x,y;
			scanf( "%lf%lf%lf%lf",&p,&q,&x,&y );
			T[Tcnt++]=line( point( p,q ),point( x,y ) );
		}
		int m=HalfPlaneCross( T,Tcnt,P );
		double SS=0;
		P[m]=P[0];
		for ( i=0; i<m; i++ )
			SS+=( P[i]-Z )^( P[i+1]-Z );
		printf( "%.1f\n",SS/2.0 );
	}
	return 0;
}
