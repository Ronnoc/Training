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
const double PI=acos( -1. );
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
	if(p.SZ<=2)return p;
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
point P[22];
int v[22];
double l[22];
int sumv[1<<15];
double suml[1<<15];
PII st[1<<15];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	int CA=0;
	while(~scanf("%d",&n)&&n){
		if(CA)puts("");
		for(i=0;i<n;i++){
			P[i].in();
			scanf("%d%lf",&v[i],&l[i]);
		}
		int mask=-1,bestv=MOD,bestcnt=-1;
		double ext=0;
		for(sumv[0]=0,suml[0]=0,i=1;i<1<<n;i++){
			j=__builtin_ctz(i);
			sumv[i]=sumv[i^(1<<j)]+v[j];
			suml[i]=suml[i^(1<<j)]+l[j];
		}
		for(i=0;i<1<<n;i++)
			st[i]=MP(sumv[i],i);
		sort(st,st+(1<<n));
		for(k=0;k<1<<n;k++){
			i=st[k].BB;
			vector<point>L;
			int sv=sumv[i],cnt=__builtin_popcount(i);
			double sl=suml[i];
			for(j=0;j<n;j++)if(i>>j&1);else L.PB(P[j]);
			if(sv>bestv)break;
			if(sv==bestv&&cnt>bestcnt)continue;
			vector<point>R=ConvexHull(L);
			if(!R.empty())R.PB(R[0]);
			double all=0;
			for(j=1;j<R.SZ;j++)all+=R[j].dis(R[j-1]);
			if(sign(sl-all)>=0){
				bestv=sv;
				mask=i;
				ext=sl-all;
				bestcnt=cnt;
			}
		}
		printf("Forest %d\n",++CA);
		printf("Cut these trees:");
		for(j=0;j<n;j++)if(mask>>j&1)printf(" %d",j+1);
		printf("\n");
		printf("Extra wood: %.2f\n",ext);
	}
	return 0;
}
