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
struct line {
	point s,e; //s->e left
	double k;
	line() {}
	line ( point _s,point _e ) :s ( _s ),e ( _e )
	{k = atan2 ( e.y - s.y,e.x - s.x );}
	bool operator < ( const line &L ) const {
		if ( sign ( k-L.k ) ) return k<L.k;
		return ( ( s-L.s ) ^ ( L.e-L.s ) ) <0;
	}
	point operator & ( const line &b ) const {
		point res = s;
		double t = ( ( s - b.s ) ^ ( b.s - b.e ) ) / ( ( s - e ) ^ ( b.s - b.e ) );
		res.x += ( e.x - s.x ) *t;
		res.y += ( e.y - s.y ) *t;
		return res;
	}
};
int HPI ( line *L, int n, point *R ) {
	sort ( L,L+n );
	int tot = 1;
	for ( int i = 1; i < n; i++ )
		if ( sign ( L[i].k - L[i-1].k ) !=0 )
			L[tot++] = L[i];
	line Q[n];
	int fi = 0, la = 1;
	Q[0] = L[0],Q[1] = L[1];
	for ( int i = 2; i < tot; i++ ) {
		if ( sign ( ( Q[la].e-Q[la].s ) ^ ( Q[la-1].e-Q[la-1].s ) ) ==0 ||
				 sign ( ( Q[fi].e-Q[fi].s ) ^ ( Q[fi+1].e-Q[fi+1].s ) ) ==0 )
			return 0;
		point s=L[i].s,e=L[i].e;
		while ( fi<la && sign ( ( ( Q[la]&Q[la-1] )-s ) ^ ( e-s ) ) >0 )
			la--;
		while ( fi<la && sign ( ( ( Q[fi]&Q[fi+1] )-s ) ^ ( e-s ) ) >0 )
			fi++;
		Q[++la] = L[i];
	}
	while ( fi<la && sign ( ( ( Q[la]&Q[la-1] )-Q[fi].s ) ^ ( Q[fi].e-Q[fi].s ) ) >0 )
		la--;
	if ( la <= fi + 1 ) return 0;
	int ret = 0;
	for ( int i = fi; i < la; i++ ) R[ret++] = Q[i]&Q[i+1];
	if ( fi < la - 1 ) R[ret++] = Q[fi]&Q[la];
	return ret;
}
double u[11111],v[11111],w[11111];
line L[33333];
point R[33333];
int nl,nr,n;
bool check ( int i ) {
	nl=0;
	int j;
	double inf=1e8;
	L[nl++]=line(point(eps,eps),point(1,eps));
	L[nl++]=line(point(eps,1),point(eps,eps));
	L[nl++]=line(point(inf,eps),point(inf,1));
	L[nl++]=line(point(1,inf),point(eps,inf));
	for ( j=0; j<n; j++ ) if ( i!=j ) 
		if(u[i]<=u[j]&&v[i]<=v[j]&&w[i]<=w[j])
			return 0;
	for ( j=0; j<n; j++ ) if ( i!=j ) {
			double A=1.0*(u[j]-u[i])/(u[i]*u[j]);
			double B=1.0*(v[j]-v[i])/(v[i]*v[j]);
			double C=1.0*(w[j]-w[i])/(w[i]*w[j]);
			if ( !sign ( u[i]-u[j] ) &&!sign ( v[i]-v[j] ) )
				continue;
			point p,q,r;
			if ( sign ( A ) ) {
				p=point ( -C/A,0 );
				q=point ( - ( B+C ) /A,1 );
			}
			if ( sign ( B ) ) {
				p=point ( 0,-C/B );
				q=point ( 1,- ( A+C ) /B );
			}
			r= ( q-p ).rotate()+p;
			if ( r.x*A+r.y*B+C<-eps ) L[nl++]=line ( p,q );
			else L[nl++]=line ( q,p );
		}
	nr=HPI ( L,nl,R );
	point A=Orz;
	for(j=0;j<nr;j++)A=A+R[j];
	A=A/nr;
	return sign (A.x)&&sign(A.y);
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf ( "%d",&n ) ) {
		for ( i=0; i<n; i++ ) scanf ( "%lf%lf%lf",&u[i],&v[i],&w[i] );
		for ( i=0; i<n; i++ )
			if ( check ( i ) ) puts ( "Yes" );
			else puts ( "No" );
	}
	return 0;
}
