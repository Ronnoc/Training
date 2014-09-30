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
	void in() {scanf("%lf%lf", &x, &y);}
	void out(char *s="") {printf("(%f,%f)%s",x,y,s);}
} Orz(0,0);
point O[1005];
double R[1005];
int main() {
//	freopen("F.in","r",stdin);
//	freopen("F.wa","w",stdout);
	int i,j,k,T;
	scanf("%d",&T);
	for(int CA=1; CA<=T; CA++) {
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			O[i].in();
			scanf("%lf",&R[i]);
		}
		int ans=0;
		for(i=0;i<n;i++){
			vector<pair<double,int> >L;
			int now=0;
			for(j=0;j<n;j++){
				double d=O[i].dis(O[j]);
				if(sign(d+R[i]-R[j])<=0)
					now++;
				else if(sign(d+R[j]-R[i])>0){
					vector<double>T;
					double arc=(O[j]-O[i]).arc();
					double f=sqrt(d*d-SQ(R[i]-R[j]));
					T.PB(arc+PI/2+atan2(R[j]-R[i],f));
					T.PB(arc-PI/2-atan2(R[j]-R[i],f));
					if(sign(R[i]+R[j]-d)<0){
						double g=sqrt(d*d-SQ(R[i]+R[j]));
						T.PB(arc+atan2(g,R[i]+R[j]));
						T.PB(arc-atan2(g,R[i]+R[j]));
					}
					for(k=0;k<T.SZ;k++){
						while(sign(T[k]-PI)>=0)T[k]-=2*PI;
						while(sign(T[k]+PI)<0)T[k]+=2*PI;
					}
					int m=T.SZ;
					for(k=0;k<m;k++)T.PB(T[k]+2*PI);
					int state=sign(fabs(O[j].x-(O[i].x-R[i]))-R[j])<0;
					if(sign(fabs(O[j].x-(O[i].x-R[i]))-R[j])==0&&sign((O[j].x-(O[i].x-R[i]))*(O[j].y-O[i].y))>=0)state=1;
//					O[j].out();printf("?%d ",state);
					now+=state;
					sort(T.OP,T.ED);
					for(k=0;k<T.SZ;k++)
						if((k+state)&1)L.PB(MP(T[k],1));
						else L.PB(MP(T[k],-1));
				}
			}
//			O[i].out();printf(",%d\n",now);
			L.PB(MP(-PI,0));
			L.PB(MP(PI,0));
			sort(L.OP,L.ED);
			for(j=0;j<L.SZ;j++){
				now-=L[j].BB;
//				cout<<"@"<<i<<"\t"<<L[j].AA<<" & "<<L[j].BB<<"\t"<<now<<endl;
				cmax(ans,now);
			}
		}
		printf("Case #%d: %d\n",CA,ans);
	}
	return 0;
}
/*
6
4   -2 5 1   5 5 1   -3 2 1   0 1 1
4   -4 5 1   3 2 1   -5 3 1   4 -3 1
3   4 7 1   17 2 1   19 17 1
3   14 15 1   11 3 1   13 2 1
3   8 9 1   0 3 1   2 2 1
4   14 8 1   14 19 1   16 14 1   8 10 1
*/
/*
3 2 2 2 3 3
*/
