#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int , int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const long double eps = 1e-10;
const long double PI = acos(-1.);
int sign(long double x) {return x < -eps ? -1 : x > eps;}
struct point {
	long double x, y;
	point() {}
	point(long double _x, long double _y) : x(_x), y(_y) {}
	point operator - (const point & p) const { return point(x - p.x, y - p.y);}
	point operator + (const point & p) const { return point(x + p.x, y + p.y);}
	point operator * (long double l) const { return point(x * l, y * l);}
	point operator / (long double l) const { return point(x / l, y / l);}
	long double len() {return sqrt(x*x+y*y);}
	long double arc() {return atan2(y,x);}
	bool operator < (const point & p) const {
		return sign(x - p.x) == 0 ? sign(y - p.y) <= 0 : sign(x - p.x) <= 0;
	}
	long double operator ^ (const point & p) const {return x * p.y - y * p.x;}   //cha
	long double operator * (const point & p) const {return x * p.x + y * p.y;}   //dot
};
vector<point> Convexhull(vector<point> p) {
	int n = p.size(), m = 0;
	vector<point> q;
	q.resize(n * 2);
	sort(p.begin(), p.end());
	for(int i = 0; i < n; i++) {
		while(m > 1 && sign((q[m - 1] - q[m - 2]) ^ (p[i] - q[m - 2])) <= 0)
			m--;
		q[m++] = p[i];
	}
	int k = m;
	for(int i = n - 2; i >= 0; i--) {
		while(m > k && sign((q[m - 1] - q[m - 2]) ^ (p[i] - q[m - 2])) <= 0)
			m--;
		q[m ++] = p[i];
	}
	if(n > 1) m--;
	q.resize(m);
	return q;
}
void gao(vector<pair<long double,long double> >&Z,long double p,long double q) {
	if(p<=-PI) {
		Z.PB(MP(p+2*PI,PI));
		Z.PB(MP(-PI,q));
	} else if(q>PI) {
		Z.PB(MP(p,PI));
		Z.PB(MP(-PI,q-2*PI));
	} else Z.PB(MP(p,q));
}
vector<point>A;
vector<long double>arc,len;
long double f(long double x) {
	int i;
	vector<pair<long double,long double> >Z;
	for(i=0; i<A.SZ; i++) {
		if(len[i]<=x) continue;
		long double alpha=acos(x/len[i]);
		gao(Z,arc[i]-alpha,arc[i]+alpha);
	}
	sort(Z.OP,Z.ED);
	long double ans=0;
	if(!Z.empty()) {
		long double p=Z[0].AA,q=Z[0].BB;
		for(i=1; i<Z.SZ; i++) {
			if(Z[i].AA<=q) cmax(q,Z[i].BB);
			else {
				ans+=q-p;
				p=Z[i].AA;
				q=Z[i].BB;
			}
		}
		ans+=q-p;
		ans/=PI;
	}
	return ans;
}
long double simpson(long double a,long double b) {
	long double c=a+ (b-a) /2;
	return (f(a)+4*f(c)+f(b)) * (b-a) /6;
}
long double asr(long double a,long double b,long double eps,long double A) {
	long double c=a+ (b-a) /2;
	long double L=simpson(a,c),R=simpson(c,b);
	if(fabs(L+R-A) <15*eps) return L+R+ (L+R-A) /15.;
	return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
}
long double asr(long double a,long double b,long double eps) {
	return asr(a,b,eps,simpson(a,b));
}
int main() {
	int i, j;
	int T;
	scanf("%d",&T);
	for(int CA=1; CA<=T; CA++) {
		A.clear();
		len.clear();
		arc.clear();
		int n;
		double D;
		scanf("%d%lf",&n,&D);
		for(i=0; i<n; i++) {
			double x,y;
			scanf("%lf%lf",&x,&y);
			x/=D;
			y/=D;
			A.PB(point(x,y));
		}
		A=Convexhull(A);
		point Orz(0,0);
		for(i=0; i<A.SZ; i++)Orz=Orz+A[i];
		Orz=Orz/A.SZ;
		for(i=0; i<A.SZ; i++)A[i]=A[i]-Orz;
		for(i=0; i<A.SZ; i++) arc.PB(A[i].arc());
		for(i=0; i<A.SZ; i++) len.PB(A[i].len());
		long double mx=-1;
		for(i=0; i<A.SZ; i++)cmax(mx,len[i]);
		double ans=asr(0,mx,1e-6);
		printf("Case #%d: %.4f\n",CA,ans);
	}
	return 0;
}
