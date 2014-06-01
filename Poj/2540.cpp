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
	if ( sign( n-m )==0 )return 0;
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
		if ( sign( ( q[last].v-q[last].u )^( q[last-1].v-q[last-1].u ) )==0 ) {
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
line l[500];
point z[500];
int nl,nz;
int main() {
	int i,j;
	nl=0;
	l[nl++]=line(point(0,0),point(10,0));
	l[nl++]=line(point(10,0),point(10,10));
	l[nl++]=line(point(10,10),point(0,10));
	l[nl++]=line(point(0,10),point(0,0));
	double x,y;
	string s;
	point O=point(0,0);
	int flag=0;
	while(cin>>x>>y>>s){
		point T(x,y);
		point M=(T+O)/2;
		point D=(T-O).rotate().normal();
		point P=M+D*20;
		point Q=M-D*20;
		if(s[0]=='S')flag=1;
		else if(s[0]=='H')
			l[nl++]=line(P,Q);
		else if(s[0]=='C')
			l[nl++]=line(Q,P);
		if(flag)printf("0.00\n");
		else {
			nz=HalfPlaneCross(l,nl,z);
			double S=0;
			for(i=0;i<nz;i++)
				S+=z[i]^z[(i+1)%nz];
			printf("%.2f\n",fabs(S)/2);
		}
		O=T;
	}
	return 0;
}
