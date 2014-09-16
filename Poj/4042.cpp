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
int isp[10000007];
int p[2000007];
bool flag[10000007];
typedef long long LL;
const LL MOD = 1000000007;
const double eps = 1e-6;
int sign(double x) {return x<-eps?-1:x>eps;}
struct point {
	double x,y;
	point() {}
	point(double _x,double _y) {x=_x,y=_y;}
	point operator -(const point &p)const {return point(x-p.x,y-p.y);}
	point operator +(const point &p)const {return point(x+p.x,y+p.y);}
	point operator *(const double &d)const {return point(x*d,y*d);}
	point operator /(const double &d)const {return point(x/d,y/d);}
	double operator ^(const point &p)const {return x*p.y-y*p.x;} //cha ji
	double operator *(const point &p)const {return x*p.x+y*p.y;} //dian ji
	double arc() {return atan2(y,x);}
	point rotate() {return point(-y,x);}
};
bool isLL(point p1,point p2,point q1,point q2,point &is) {
	double m=(q2-q1)^(p1-q1);
	double n=(q2-q1)^(p2-q1);
	if(sign(n-m)==0)return 0;
	is=(p1*n-p2*m)/(n-m);
	return 1;
}
const double PI = acos(-1);
int main() {
	int n;
	int i,j;
	char s[1111];
	while(~scanf("%s",s)) {
		if(strcmp(s,"END")==0)break;
		point A,B,C;
		sscanf(s,"%lf",&A.x);
		scanf("%lf",&A.y);
		scanf("%lf%lf",&B.x,&B.y);
		scanf("%lf%lf",&C.x,&C.y);
		point AB=(A+B)/2,AC=(A+C)/2,BC=(B+C)/2;
		point ab=(B-A).rotate(),ac=(C-A).rotate(),bc=(C-B).rotate();
		point O;
		isLL(AB,AB+ab,AC,AC+ac,O);
		double a=(A-O).arc();
		double b=(B-O).arc();
		double c=(C-O).arc();
		double e[5];
		e[0]=a,e[1]=b,e[2]=c;
		sort(e,e+3);
		double f1=e[1]-e[0],f2=e[2]-e[1];
		int n;
		for(n=3; n<=1001; n++) {
			double f=2*PI/n;
			double n1=f1/f,n2=f2/f;
			int m1=n1+0.5,m2=n2+0.5;
			int flag1=0,flag2=0;
			if(sign(n1-m1)==0)flag1=1;
			if(sign(n1-m1-1)==0)flag1=1;
			if(sign(n1-m1+1)==0)flag1=1;
			if(sign(n2-m2)==0)flag2=1;
			if(sign(n2-m2-1)==0)flag2=1;
			if(sign(n2-m2+1)==0)flag2=1;
//			if(n==3)printf("%.9lf %.9lf\n",f1-m1*f,f2-m2*f);
			if(flag1&&flag2)break;
		}
		printf("%d\n",n);
	}
	return 0;
}
