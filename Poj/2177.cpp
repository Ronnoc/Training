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
struct spt {
	double x,y,z;
	spt() {}
	spt(double _x,double _y,double _z):x(_x),y(_y),z(_z) {}
	spt operator +(const spt &s)const {return spt(x+s.x,y+s.y,z+s.z);}     //{-,*,/}
	spt operator -(const spt &s)const {return spt(x-s.x,y-s.y,z-s.z);}
	spt operator *(const double &d)const {return spt(x*d,y*d,z*d);}
	spt operator /(const double &d)const {return spt(x/d,y/d,z/d);}
	double len() {return sqrt(SQ(x)+SQ(y)+SQ(z));}
	spt normal() {return (*this)/len();}
	double operator *(const spt &s)const {return x*s.x+y*s.y+z*s.z;}
	spt operator ^(const spt &s)const {
		spt ret;
		ret.x=y*s.z-z*s.y;
		ret.y=z*s.x-x*s.z;
		ret.z=x*s.y-y*s.x;
		return ret;
	}
	void input() {scanf("%lf%lf%lf",&x,&y,&z);}
	void output() {cout<<x<<","<<y<<","<<z<<"\t";}
} O(0,0,0);
struct sfl {
	spt p,o;
	sfl() {}
	sfl(spt _p,spt _o):p(_p),o(_o) {}
	sfl(spt u,spt v,spt w) {p=u,o=((v-u)^(w-u)).normal();}
};
double disLP(spt p1,spt p2,spt q) {
	return fabs(((p2-p1)^(q-p1)).len()/((p2-p1).len()));
}
double disLL(spt p1,spt p2,spt q1,spt q2) {
	spt p=q1-p1,u=p2-p1,v=q2-q1;
	double d=(u*u)*(v*v)-SQ(u*v);
	if(sign(d)==0)return disLP(q1,q2,p1);
	double s=((p*u)*(v*v)-(p*v)*(u*v))/d;
	return disLP(q1,q2,p1+u*s);
}
bool isFL(sfl f,spt q1,spt q2,spt &is) {
	double a=f.o*(q2-f.p),b=f.o*(q1-f.p);
	double d=a-b;
	if(sign(d)==0)return 0;
	is=(q1*a-q2*b)/d;
	return 1;
}
bool isFF(sfl a,sfl b,spt &is1,spt &is2) {
	spt e=a.o^b.o;
	spt v=a.o^e;
	double d=b.o*v;
	if(sign(d)==0)return 0;
	is1=a.p+v*(b.o*(b.p-a.p))/d;
	is2=is1+e;
	return 1;
}
spt o[111];
double r[111];
sfl f[111];
vector<int>ans;
int n;
void gao(spt v) {
	vector<int>now;
	for(int i=0; i<n; i++)if(sign(disLP(O,v,o[i])-r[i])<=0)now.PB(i+1);
	if(now.SZ>ans.SZ)ans=now;
	//	v.output();
	//	printf( "%d\n",now.SZ );
}
int main() {
//	freopen("ghosts.in","r",stdin);
//	freopen("ghosts.out","w",stdout);
	int i,j,k;
	while(scanf("%d",&n)!=EOF) {
		for(i=0; i<n; i++) {
			o[i].input();
			scanf("%lf",&r[i]);
			f[i].o=o[i].normal();
			f[i].p=o[i].normal()/(o[i].len()/(sqrt(SQ(o[i].len())-SQ(r[i]))));
		}
		ans.clear();
		for(i=0; i<n; i++)gao(o[i]);
		for(i=0; i<n; i++)for(j=i+1; j<n; j++) {
				spt is1,is2;
				if(isFF(f[j],f[i],is1,is2)) {
					spt e=(is2-is1).normal(),m;
					sfl t(is1,is2,O);
					spt s=e^(t.o);
					isFL(sfl(is1,s),O,s,m);
					gao(m);
					double d=m.len();
					if(SQ(d)<=1) {
						double v=sqrt(1-SQ(d));
						gao(m+e*v);
						gao(m-e*v);
					}
				}
			}
		if(ans.SZ>0) {
			printf("%d\n%d",ans.SZ,ans[0]);
			for(i=1; i<ans.SZ; i++)printf(" %d",ans[i]);
			printf("\n");
		}
		else printf("0\n");
	}
	return 0;
}
