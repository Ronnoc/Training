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
	double operator * ( point p ) {return x * p.y - y * p.x;} //叉积
	double operator | ( point p ) {return x * p.x + y * p.y;} //点积
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
};
/*直线和直线求交点*/
bool isLL( point p1, point p2, point q1, point q2, point &is ) {
	double m = ( q2 - q1 ) * ( p1 - q1 ), n = ( q2 - q1 ) * ( p2 - q1 );
	if ( dcmp( n - m ) == 0 ) return 0; //判直线平行，n=m=0时直线重合
	is = ( p1 * n - p2 * m ) / ( n - m );
	return 1;
}
/*点到直线的距离*/
double disLP( point p1, point p2, point q ) {
	return fabs( ( p1 - p2 ).normal() * ( q - p1 ) );
}
point a=point( 0,0 );
point b=point( 3.715,1.761 );
point c=point( 2.894,-2.115 );
point da,db,dc;
double p,q,r;
double ff( point s ) {
	double ret=0;
	ret+=SQ( disLP( a,a+da,s ) )*p;
	ret+=SQ( disLP( b,b+db,s ) )*q;
	ret+=SQ( disLP( c,c+dc,s ) )*r;
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T,CA;
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d",&CA );
		double A,B,C;
		scanf( "%lf%lf%lf%lf%lf%lf",&A,&p,&B,&q,&C,&r );
		A/=180/PI,B/=180/PI,C/=180/PI;
		p+=0.2,q+=0.2,r+=0.2;
		da=point( sin( A ),cos( A ) );
		db=point( sin( B ),cos( B ) );
		dc=point( sin( C ),cos( C ) );
		point ab,ac,bc;
		isLL( a,a+da,b,b+db,ab );
		isLL( a,a+da,c,c+dc,ac );
		isLL( b,b+db,c,c+dc,bc );
		double U,W,V,u,v;
		double ea=a*da,eb=b*db,ec=c*dc;
		//f(<x,y>)=Ux^2+Wxy+Vy^2+ux+vy+?
		//dx=2Ux+Wy+u;
		//dy=Wx+2Vy+v;
		U=p*SQ( da.y )+q*SQ( db.y )+r*SQ( dc.y );
		V=p*SQ( da.x )+q*SQ( db.x )+r*SQ( dc.x );
		W=-2*( p*da.x*da.y+q*db.x*db.y+r*dc.x*dc.y );
		u=-2*( p*da.y*ea+q*db.y*eb+r*dc.y*ec );
		v= 2*( p*da.x*ea+q*db.x*eb+r*dc.x*ec );
		double per=0.5;
		point s=( ab+ac+bc )/3;
		double fs=ff( s );
		for ( i=1; i<=100; i++ ) {
			double dx=2*U*s.x+W*s.y+u;
			double dy=2*V*s.y+W*s.x+v;
			point t=s-point( dx,dy ).normal()*per;
			double ft=ff( t );
			if ( ft<fs )s=t,fs=ft;
			else per/=2;
		}
		printf( "%d %.3f %.3f\n",CA,s.x,s.y );
	}
	return 0;
}
