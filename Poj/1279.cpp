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
struct line {
	point s,e;
	double k;
	line ( point _s=Orz,point _e=Orz ) :s ( _s ),e ( _e )
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
point R[11111];
line L[11111];
int nr,nl;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	int CA=0;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		vector<point>P;
		for(i=0;i<n;i++){
			point foo;
			foo.in();
			P.PB(foo);
		}
		if(!P.empty())P.PB(P[0]);
		nl=0;
		for(i=1;i<P.SZ;i++)
			L[nl++]=line(P[i],P[i-1]);
		nr=HPI(L,nl,R);
		R[nr]=R[0];
		double S=0;
		for(i=0;i<nr;i++)
			S+=R[i]^R[i+1];
		S/=2;
		S=fabs(S);
		printf("%.2f\n",S);
	}
	return 0;
}
