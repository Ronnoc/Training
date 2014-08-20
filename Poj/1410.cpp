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
double xl,xr,yl,yr;
point s,e;
int FLAG=0;
void check(point is){
	if(sign(is.x-xl)<0)return;
	if(sign(is.x-xr)>0)return;
	if(sign(is.y-yl)<0)return;
	if(sign(is.y-yr)>0)return;
	if(sign(is.x-min(s.x,e.x))<0)return;
	if(sign(is.x-max(s.x,e.x))>0)return;
	if(sign(is.y-min(s.y,e.y))<0)return;
	if(sign(is.y-max(s.y,e.y))>0)return;
	FLAG=1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf("%d",&T);
	while(T--){
		point is;
		FLAG=0;
		s.in();
		e.in();
		scanf("%lf%lf%lf%lf",&xl,&yr,&xr,&yl);
		if(xl>xr)swap(xl,xr);
		if(yl>yr)swap(yl,yr);
		k=isLL(s,e,point(xl,yl),point(xl,yr),is);
		if(k)check(is);
		k=isLL(s,e,point(xl,yr),point(xr,yr),is);
		if(k)check(is);
		k=isLL(s,e,point(xr,yr),point(xr,yl),is);
		if(k)check(is);
		k=isLL(s,e,point(xr,yl),point(xl,yl),is);
		if(k)check(is);
		check(s);
		check(e);
		if(FLAG)puts("T");
		else puts("F");
	}
	return 0;
}
