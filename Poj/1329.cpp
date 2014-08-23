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
struct circle {
	point ct;
	double r;
	circle ( point a,point b ) {
		ct= ( a+b ) /2;
		r= ( b-a ).len() /2;
	}
	circle ( point o,double rr ) :ct ( o ),r ( rr ) {}
	circle ( point a,point b,point c ) {
		double A,B,C,D,E,F;
		A=2*a.x-2*b.x;
		B=2*a.y-2*b.y;
		C=SQ ( a.len() )-SQ ( b.len() );
		D=2*a.x-2*c.x;
		E=2*a.y-2*c.y;
		F=SQ ( a.len() )-SQ ( c.len() );
		ct.x= ( C*E-B*F ) / ( A*E-B*D );
		ct.y= ( A*F-C*D ) / ( A*E-B*D );
		r= ( a-ct ).len();
	}
	bool operator > ( const point a ) const {
		return sign ( ( a-ct ).len()-r ) <=0;
	}
};
char f(double x){
	if(sign(x)>=0)return '-';
	return '+';
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	point A,B,C;
	while(~scanf("%lf%lf",&A.x,&A.y)){
		B.in(),C.in();
		circle D(A,B,C);
		printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n",f(D.ct.x),fabs(D.ct.x),f(D.ct.y),fabs(D.ct.y),D.r);
		double a=SQ(D.r)-SQ(D.ct.len());
		printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n",f(D.ct.x),2*fabs(D.ct.x),f(D.ct.y),2*fabs(D.ct.y),f(a),fabs(a));
		puts("");
	}
	return 0;
}
