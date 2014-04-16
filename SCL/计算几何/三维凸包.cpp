//poj 3528
//O(n^2)三维凸包求表面积
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
const int MXN = 505;
const LL MOD = 1000000007;
int Sign( double x ) {return x<-eps?-1:x>eps;}
struct spoint {
	double x,y,z;
	spoint() {}
	spoint( double _x,double _y,double _z ):x( _x ),y( _y ),z(_z) {}
	spoint operator +( const spoint &s )const {return spoint( x+s.x,y+s.y,z+s.z );}
	spoint operator -( const spoint &s )const {return spoint( x-s.x,y-s.y,z-s.z );}
	spoint operator *( const double &d )const {return spoint( x*d,y*d,z*d );}
	spoint operator /( const double &d )const {return spoint( x/d,y/d,z/d );}
	double len()const {return sqrt( SQ( x )+SQ( y )+SQ(z) );}
	double operator *( const spoint &s )const {return x*s.x+y*s.y+z*s.z;} //点积
	spoint operator ^( const spoint &s )const {														//叉积
		spoint ret;
		ret.x=y*s.z-z*s.y;
		ret.y=z*s.x-x*s.z;
		ret.z=x*s.y-y*s.x;
		return ret;
	}
	void output() {printf( "%.6f %.6f %.6f\n",x,y,z );}
} ORI( 0,0,0 );
struct plane{
	spoint u,v,w;
	plane() {}
	plane(spoint _u,spoint _v,spoint _w):u(_u),v(_v),w(_w) {}
};
int SpaceConvexHull(spoint *s,int n,plane *p){
	int vs[MXN][MXN];
	vector<vector<int> >crt;
	vector<vector<int> >::iterator it;
	vector<int>L;
	L.clear();L.PB(0);L.PB(1);L.PB(2);crt.PB(L);
	L.clear();L.PB(2);L.PB(1);L.PB(0);crt.PB(L);
	for(int i=3;i<n;i++){
		vector<vector<int> >next;
		for(it=crt.OP;it!=crt.ED;++it){
			vector<int>t=*it;
			int v=((s[t[1]]-s[t[0]])^(s[t[2]]-s[t[0]]))*(s[i]-s[t[0]])<0?-1:1;
			if(v<0)next.PB(t);
			for(int j=0;j<3;j++){
				int x=t[j],y=t[(j+1)%3];
				if(vs[y][x]==0)vs[x][y]=v;
				else {
					if(vs[y][x]!=v){
						if(v>0){L.clear();L.PB(x);L.PB(y);L.PB(i);next.PB(L);}
						else {L.clear();L.PB(y);L.PB(x);L.PB(i);next.PB(L);}
					}
					vs[y][x]=0;
				}
			}
		}
		crt=next;
	}
	int m=0;
	for(int i=0;i<crt.SZ;i++)
		p[m++]=plane(s[crt[i][0]],s[crt[i][1]],s[crt[i][2]]);
	return m;
}
spoint S[MXN];
plane P[MXN];
int n;
int main() {
	int i,j;
	while(~scanf("%d",&n)){
		double x,y,z;
		for(i=0;i<n;i++){
			scanf("%lf%lf%lf",&x,&y,&z);
			S[i]=spoint(x,y,z);
		}
		int m=SpaceConvexHull(S,n,P);
		double V=0;
		for(i=0;i<m;i++)
			V+=((P[i].u-P[i].w)^(P[i].v-P[i].w)).len();
		printf("%.3f\n",V/2);
	}
	return 0;
}
