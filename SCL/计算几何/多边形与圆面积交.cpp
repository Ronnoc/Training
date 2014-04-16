//poj 3675
//简单n多边形与圆面积交
//圆心在(0,0),半径为r
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
int Sign( double x ) {return x<-eps?-1:x>eps;}
struct point {
	double x,y;
	point() {}
	point( double _x,double _y ):x( _x ),y( _y ) {}
	point operator +( const point &p )const {return point( x+p.x,y+p.y );}
	point operator -( const point &p )const {return point( x-p.x,y-p.y );}
	double len()const {return sqrt( SQ( x )+SQ( y ) );}
	double operator *( const point &p )const {return x*p.x+y*p.y;} //点积
	double operator ^( const point &p )const {return x*p.y-y*p.x;} //叉积
	void output() {printf( "%.6f %.6f\n",x,y );}
}ORI(0,0);
double r;
int n;
point info[MXN+10];
// 用有向面积，划分成一个三角形和圆的交
double area2(point pa,point pb){
	if(pa.len()<pb.len())swap(pa,pb);
	if(pb.len()<eps)return 0;
	double a,b,c,B,C,sinB,cosB,sinC,cosC,S,h,theta;
	a=pb.len(),b=pa.len(),c=(pb-pa).len();
	cosB=pb*(pb-pa)/a/c;
	B=acos(cosB);
	cosC=pa*pb/a/b;
	C=acos(cosC);
	if(a>r){
		S=(C/2)*r*r;
		h=a*b*sin(C)/c;
		if(h<r&&B<PI/2)S-=(acos(h/r)*r*r-h*sqrt(r*r-h*h));
	}else if(b>r){
		theta=PI-B-asin(sin(B)/r*a);
		S=.5*a*r*sin(theta)+(C-theta)/2*r*r;
	}else S=.5*sin(C)*a*b;
	return S;
}
double area(){
	double S=0;
	for(int i=0;i<n;i++)
		S+=area2(info[i],info[i+1])*Sign(info[i]^info[i+1]);
	return fabs(S);
}
int main(){
	int i,j;
	while(~scanf("%lf",&r)){
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%lf%lf",&info[i].x,&info[i].y);
		info[n]=info[0];
		printf("%.2f\n",area());
	}
	return 0;
}
