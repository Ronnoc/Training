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
vector<point> ConvexHull ( vector<point> p ) {
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
vector<point>L;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while(~scanf("%d",&n)){
		L.clear();
		for(i=0;i<n;i++){
			point foo;
			foo.in();
			L.PB(foo);
		}
		L=ConvexHull(L);
		if(!L.empty())L.PB(L[0]);
		double S=0;
		for(i=1;i<L.SZ;i++)
			S+=L[i]^L[i-1];
		S=fabs(S/2);
		int ans=(S/50)+eps;
		printf("%d\n",ans);
	}
	return 0;
}
