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
vector<point> ConvexHull ( vector<point> p ) {
	if ( p.SZ<=2 ) return p;
	int n = p.size(), m = 0;
	vector<point> q;
	q.resize ( n * 2 );
	sort ( p.begin(), p.end() );
	for ( int i = 0; i < n; i ++ ) {
		while ( m > 1 && sign ( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) ) <= 0 )
			m -- ;
		q[m ++ ] = p[i];
	}
	int k = m;
	for ( int i = n - 2; i >= 0; i -- ) {
		while ( m > k && sign ( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) ) <= 0 )
			m -- ;
		q[m ++ ] = p[i];
	}
	if ( n > 1 ) m -- ;
	q.resize ( m );
	return q;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	double rp,rq,ry;
	while ( ~scanf ( "%lf%lf%lf",&rp,&rq,&ry ) ) {
		if ( rp>rq ) swap ( rp,rq );
		if ( !sign ( rp ) &&!sign ( rq ) &&!sign ( ry ) ) break;
		double sp,sq,sy;
		scanf ( "%lf%lf%lf",&sp,&sq,&sy );
		if ( sp>sq ) swap ( sp,sq );
		vector<pair<double,double> >L;
		int n;
		scanf ( "%d",&n );
		for ( i=0; i<n; i++ ) {
			double tp,tq,ty;
			scanf ( "%lf%lf%lf",&tp,&tq,&ty );
			if ( tp>tq ) swap ( tp,tq );
			if(sign(ty-sy)<=0||sign(ty-ry)>=0)continue;
			point ip,iq;
			isLL(point(rq,ry),point(tp,ty),point(sp,sy),point(sp+1,sy),ip);
			isLL(point(rp,ry),point(tq,ty),point(sp,sy),point(sp+1,sy),iq);
			cmax(ip.x,sp),cmin(iq.x,sq);
			if(sign(iq.x-ip.x)>=0)L.PB(MP(ip.x,iq.x));
		}
		sort(L.OP,L.ED);
		double ans=0,la=sp;
		if(!L.empty()){
			double lp=L[0].AA,lq=L[0].BB;
			for(i=1;i<L.SZ;i++){
				if(sign(L[i].AA-lq)<=0)
					cmax(lq,L[i].BB);
				else {
					cmax(ans,lp-la);
					la=lq;
					lp=L[i].AA;
					lq=L[i].BB;
				}
			}
			cmax(ans,lp-la);
			cmax(ans,sq-lq);
		}else ans=sq-sp;
		if(sign(ans))printf("%.2f\n",ans+eps);
		else printf("No View\n");
	}
	return 0;
}
