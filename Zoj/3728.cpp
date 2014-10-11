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
int sign(double x){return x<-eps?-1:x>eps;}
struct point{
	double x,y;
	point(double X=0,double Y=0){x=X,y=Y;}
	point operator +(point p){return point(x+p.x,y+p.y);}
	point operator -(point p){return point(x-p.x,y-p.y);}
	point operator *(double d){return point(x*d,y*d);}
	point operator /(double d){return point(x/d,y/d);}
	double operator *(point p){return x*p.x+y*p.y;}
	double operator ^(point p){return x*p.y-y*p.x;}
	double len(){return sqrt(SQ(x)+SQ(y));}
}Orz(0,0);
bool isLL(point p1,point p2,point q1,point q2,point &is){
	double m=(q2-q1)^(p1-q1),n=(q2-q1)^(p2-q1);
	if(sign(n-m)==0)return 0;
	is=(p1*n-p2*m)/(n-m);
	return 1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	double p,q,r,x,y,vx,vy;
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf",&p,&q,&r,&x,&y,&vx,&vy)){
		point S(x,y),V(vx,vy),is;
		isLL(Orz,point(vy,-vx),S,S+V,is);
		p+=r,q+=r;
		double tmp=(is-S)*V;
		if(sign(tmp)<=0){
			printf("0.000\n");
			continue;
		}
		double dis=is.len();
		if(sign(dis-p)<=0){
			double len1=sqrt(SQ(q)-SQ(dis))*2;
			double len2=sqrt(SQ(p)-SQ(dis))*2;
			printf("%.3f\n",(len1-len2)/V.len());
		}else if(sign(dis-q)<=0){
			double len=sqrt(SQ(q)-SQ(dis))*2;
			printf("%.3f\n",len/V.len());
		}else printf("0.000\n");
	}
	return 0;
}
