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
char s[11111];
vector<double>L[111];
vector<point>G;
//vector<pair<point,point> >S;
double dp[11111];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	double x;
	while ( ~scanf ( "%d",&n ) &&~n ) {
		gets ( s );
//		S.clear();
		G.clear();
		G.PB(point(0,5));
		G.PB(point(10,5));
		for ( i=0; i<n; i++ ) {
			L[i].clear();
			gets ( s );
			istringstream sin ( s );
			while(sin>>x)L[i].PB(x);
//			double la=0;
//			for(j=1;j<L[i].SZ;j+=2){
//				S.PB(MP(point(L[i][0],la),point(L[i][0],L[i][j])));
//				la=L[i][j+1];
//			}
//			S.PB(MP(point(L[i][0],la),point(L[i][0],10)));
			for(j=1;j<L[i].SZ;++j)
				G.PB(point(L[i][0],L[i][j]));
		}
		dp[0]=0;
		for(i=1;i<G.SZ;i++)dp[i]=1e150;
		queue<int>Q;
		Q.push(0);
		while(!Q.empty()){
			int uid=Q.front();
			Q.pop();
			point u=G[uid],is;
			for(i=0;i<G.SZ;i++){
				point v=G[i];
				int ok=1;
				for(k=0;ok&&k<n;k++){
					if(sign(L[k][0]-min(u.x,v.x))<=0)continue;
					if(sign(L[k][0]-max(u.x,v.x))>=0)continue;
					int flag=isLL(u,v,point(L[k][0],1),point(L[k][0],0),is);
					if(!flag)continue;
					double la=0;
					for(j=1;j<L[k].SZ;j+=2){
						if(sign(is.y-la)>0&&sign(is.y-L[k][j])<0){ok=0;break;}
						la=L[k][j+1];
					}
					if(sign(is.y-la)>0)ok=0;
				}
				if(ok){
					double d=dp[uid]+v.dis(u);
					if(sign(dp[i]-d)>0){
						dp[i]=d;
						Q.push(i);
					}
				}
			}
		}
		printf("%.2f\n",dp[1]);
	}
	return 0;
}
