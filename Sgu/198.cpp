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
struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
	point operator - (const point p) const {return point(x-p.x,y-p.y);}
	point operator + (const point p) const {return point(x+p.x,y+p.y);}
	point operator * (const double d)const {return point(x*d,y*d);}
	point operator / (const double d)const {return point(x/d,y/d);}
	bool operator < (const point &p) const {
		return sign(x - p.x) == 0 ? sign(y - p.y) <= 0 : sign(x - p.x) <= 0;
	}
	double operator ^(const point &p)const {return x*p.y-y*p.x;}//det
	double operator *(const point &p)const {return x*p.x+y*p.y;}//dot
	double len() {return sqrt(x*x+y*y);}
	double arc() {return atan2(y, x);}
	point normal() {return (*this) / this->len();}
	point rotate() {return point(-y, x);}
	point rotate(double arc)
	{return point(x*cos(arc) - y*sin(arc),x*sin(arc) + y*cos(arc));}
	double dis(point p) {return (*this - p).len();}
	double dis2(point p) {p = p - (*this); return p*p;}
	void in() {scanf("%lf%lf", &x, &y);}
	void out(char *s="") {printf("(%f,%f)%s",x,y,s);}
};
point O[333];
double R[333];
point o;
double r;
vector<int>G[333];
int fa[333];
int vis[333];
int dph[333];
double w[333];
int FAIL;
double getarc(int u,int v){
	double ret=O[v].arc()-O[u].arc();
	while(sign(ret-PI)>0)ret-=PI;
	while(sign(ret+PI)<=0)ret+=PI;
	return ret;
}
void dfs(int u,int f,int h){
	vis[u]=1,fa[u]=f,dph[u]=h;
	if(~f)w[u]=w[f]+getarc(f,u);
	else w[u]=0;
	for(int i=0;i<G[u].SZ;i++){
		int v=G[u][i];
		if(v==f)continue;
		if(vis[v]){
			int p=u,q=v;
			while(dph[p]!=dph[q]){
				if(dph[p]<dph[q])q=fa[q];
				else p=fa[p];
			}
			while(p!=q)p=fa[p],q=fa[q];
			double s=w[u]-w[p],t=w[v]-w[p];
			double z=s-t+getarc(u,v);
			if(sign(z))FAIL=1;
		}else dfs(v,u,h+1);
	}
}
int main() {
	int i,j,k,n,m,u,v,T;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			O[i].in();scanf("%lf",&R[i]);
		}
		o.in();scanf("%lf",&r);
		for(i=0;i<n;i++)O[i]=O[i]-o,R[i]+=r;
		for(i=0;i<n;i++)G[i].clear();
		for(i=0;i<n;i++)for(j=i+1;j<n;j++)
			if(sign(O[i].dis(O[j])-R[i]-R[j])<0)
				G[i].PB(j),G[j].PB(i);
		for(i=0;i<n;i++)vis[i]=0;
		FAIL=0;
		for(i=0;!FAIL&&i<n;i++)if(!vis[i])
			dfs(i,-1,1);
		if(FAIL)puts("NO");
		else puts("YES");
	}
	return 0;
}
