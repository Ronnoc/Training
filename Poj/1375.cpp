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
const double PI=acos(-1.);
const LL MOD = 1000000007;
int sign(double x) {return x<-eps?-1:x>eps;}
struct point {
	double x, y;
	point(double _x=0, double _y=0) : x(_x), y(_y) {}
	point operator - (point p) {return point(x-p.x,y-p.y);}
	point operator + (point p) {return point(x+p.x,y+p.y);}
	point operator * (double d) {return point(x*d,y*d);}
	point operator / (double d) {return point(x/d,y/d);}
	bool operator < (const point &p) const {
		return sign(x - p.x) == 0 ? sign(y - p.y) <= 0 : sign(x - p.x) <= 0;
	}
	double operator ^(point p) {return x*p.y-y*p.x;}
	double operator *(point p) {return x*p.x+y*p.y;}
	double len() {return sqrt(x*x+y*y);}
	double arc() {return atan2(y, x);}
	point normal() {return (*this) / this->len();}
	point rotate() {return point(-y, x);}
	point rotate(double arc)
	{return point(x*cos(arc) - y*sin(arc),x*sin(arc) + y*cos(arc));}
	double dis(point p) {return (*this - p).len();}
	double dis2(point p) {p = p - (*this); return p*p;}
	void read() {scanf("%lf%lf", &x, &y);}
	void write(char *s="") {printf("(%f,%f)%s",x,y,s);}
} Orz(0,0);
bool isLL(point p1, point p2, point q1, point q2 ,point &is) {
	double m=(q2-q1)^(p1-q1),n=(q2-q1)^(p2-q1);
	if(sign(n-m)==0)return 0;
	is= (p1*n-p2*m)/(n-m);
	return 1;
}
point p[555];
double r[555];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	while(~scanf("%d",&n)&&n){
		point S;
		S.read();
		vector<pair<double,double> >L;
		for(i=0;i<n;i++){
			p[i].read();
			scanf("%lf",&r[i]);
			double d=(p[i]-S).len();
			double arc=atan2(S.y-p[i].y,S.x-p[i].x);
			double bet=atan2(sqrt(d*d-r[i]*r[i]),r[i]);
			double le=arc+bet,re=arc-bet;
			point dl(cos(le),sin(le));
			point dr(cos(re),sin(re));
			point cl=p[i]+dl*r[i],cr=p[i]+dr*r[i];
			isLL(S,cl,Orz,point(1,0),cl);
			isLL(S,cr,Orz,point(1,0),cr);
			double l=cl.x,r=cr.x;
			if(l>r)swap(l,r);
			L.PB(MP(l,r));
		}
		sort(L.OP,L.ED);
		if(!L.empty()){
			int id=0;
			double le=L[0].AA,re=L[0].BB;
			for(i=1;i<L.SZ;i++){
				if(L[i].AA<re+eps)cmax(re,L[i].BB);
				else {
					printf("%.2f %.2f\n",le,re);
					le=L[i].AA,re=L[i].BB;
				}
			}
			printf("%.2f %.2f\n",le,re);
		}
		printf("\n");
	}
	return 0;
}
