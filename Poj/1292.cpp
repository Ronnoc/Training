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
const double eps=1e-9;
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
/*点到直线的距离*/
double disLP ( point p1, point p2, point q ) {
	return fabs ( ( p1 - p2 ).normal() ^ ( q - p1 ) );
}
/*点到线段的距离*/
double disSP ( point p1, point p2, point q ) {
	if ( sign ( ( p2 - p1 ) * ( q - p1 ) ) <= 0 ) return q.dis ( p1 );
	if ( sign ( ( p1 - p2 ) * ( q - p2 ) ) <= 0 ) return q.dis ( p2 );
	return disLP ( p1, p2, q );
}
int fa[3005];
int getfa ( int u ) {return fa[u]==u?u:fa[u]=getfa ( fa[u] );}
point U[3005],V[3005];
bool fit(point is,point a,point b){
	if(is.x>a.x&&is.x>b.x)return 0;
	if(is.x<a.x&&is.x<b.x)return 0;
	if(is.y>a.y&&is.y>b.y)return 0;
	if(is.y<a.y&&is.y<b.y)return 0;
	return 1;
}
double dis ( int i,int j ) {
	point is;
	int flag=isLL(U[i],V[i],U[j],V[j],is);
	if(flag){
		if(fit(is,U[i],V[i])&&fit(is,U[j],V[j]))
			return 0;
	}
	double jdu=disSP ( U[i],V[i],U[j] );
	double jdv=disSP ( U[i],V[i],V[j] );
	double idu=disSP ( U[j],V[j],U[i] );
	double idv=disSP ( U[j],V[j],V[i] );
	return min ( min(jdu,jdv),min(idu,idv) );
}
double d[3005];
int v[3005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while ( ~scanf ( "%d",&n ) &&n ) {
		for ( i=1; i<=n; i++ )
			fa[i]=i;
		for ( i=1; i<=n; i++ ) {
			U[i].in();
			double len;
			scanf ( "%lf",&len );
			V[i]=U[i];
			if ( len>=0 ) V[i].x+=len;
			else V[i].y-=len;
		}
		d[1]=0;
		for ( i=2; i<=n; i++ ) d[i]=dis ( 1,i );
		memset ( v,0,sizeof v );
		v[1]=1;
		double ans=0;
		for ( j=2; j<=n; j++ ) {
			double mn=1e100;
			int id=-1;
			for ( i=1; i<=n; i++ ) if ( !v[i] )
					if ( d[i]<mn ) mn=d[id=i];
			cmax ( ans,mn );
			v[id]=1,d[id]=0;
			for ( i=1; i<=n; i++ ) if ( !v[i] ) cmin ( d[i],dis ( i,id ) );
			if ( id==2 ) {
				printf ( "%.2f\n",ans );
				break;
			}
		}
	}
	return 0;
}
