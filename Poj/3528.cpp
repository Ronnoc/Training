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
const double PI=acos(-1.);
const int MXN = 505;
const LL MOD = 1000000007;
int sign(double x) {return x<-eps?-1:x>eps;}
struct spt {
	double x,y,z;
	spt(double _x=0,double _y=0,double _z=0):x(_x),y(_y),z(_z) {}
	spt operator +(spt &s) {return spt(x+s.x,y+s.y,z+s.z);}
	spt operator -(spt &s) {return spt(x-s.x,y-s.y,z-s.z);}
	spt operator *(double d) {return spt(x*d,y*d,z*d);}
	spt operator /(double d) {return spt(x/d,y/d,z/d);}
	double len()const {return sqrt(SQ(x)+SQ(y)+SQ(z));}
	double operator *(spt s) {return x*s.x+y*s.y+z*s.z;}   //µã»ý
	spt operator ^(spt s) {	//²æ»ý
		spt ret;
		ret.x=y*s.z-z*s.y;
		ret.y=z*s.x-x*s.z;
		ret.z=x*s.y-y*s.x;
		return ret;
	}
	bool operator < (const spt &s)const {
		if(sign(s.x-x)!=0)return sign(x-s.x)<0;
		if(sign(s.y-y)!=0)return sign(y-s.y)<0;
		return sign(z-s.z)<0;
	}
	bool operator ==(const spt &s)const {
		return sign(s.x-x)==0&&sign(s.y-y)==0&&sign(s.z-z)==0;
	}
	void output() {printf("(%.6f %.6f %.6f)\n",x,y,z);}
} Orz(0,0,0);
spt s[MXN];
int mark[MXN][MXN];
int cnt,n;
struct Face {
	int a,b,c;
	Face(int a=0,int b=0,int c=0):a(a),b(b),c(c) {}
	int &operator [](int k) {
		if(!k)return a;
		return k==1?b:c;
	}
};
vector<Face>face;
void insert(int a,int b,int c) {face.PB(Face(a,b,c));}
double mix(spt a,spt b,spt c) {return a*(b^c);}
double volume(int a,int b,int c,int d) {return mix(s[b]-s[a],s[c]-s[a],s[d]-s[a]);}
void add(int v) {
	vector<Face>tmp;
	int a,b,c;
	cnt++;
	for(int i=0; i<face.SZ; i++) {
		a=face[i][0],b=face[i][1],c=face[i][2];
		if(sign(volume(v,a,b,c))<0)
			mark[a][b]=mark[b][a]=mark[b][c]=mark[c][b]=mark[c][a]=mark[a][c]=cnt;
		else tmp.PB(face[i]);
	}
	face=tmp;
	for(int i=0; i<tmp.SZ; i++) {
		a=face[i][0],b=face[i][1],c=face[i][2];
		if(mark[a][b]==cnt)insert(b,a,v);
		if(mark[b][c]==cnt)insert(c,b,v);
		if(mark[c][a]==cnt)insert(a,c,v);
	}
}
int Find() {
	for(int i=2; i<n; i++) {
		spt ndir=(s[0]-s[i])^(s[1]-s[i]);
		if(ndir==spt())continue;
		swap(s[i],s[2]);
		for(int j=i+1; j<n; j++)
			if(sign(volume(0,1,2,j))!=0) {
				swap(s[j],s[3]);
				insert(0,1,2);
				insert(0,2,1);
				return 1;
			}
	}
	return 0;
}
bool makeFace() {
	sort(s,s+n);
	n=unique(s,s+n)-s;
	random_shuffle(s,s+n);
	face.clear();
	int flag=Find();
	if(!flag);//on same plane
	memset(mark,0,sizeof mark);
	cnt=0;
	for(int i=3; i<n; i++)add(i);
	return 1;
}
int main() {
	int i,j;
	while(~scanf("%d",&n)) {
		double x,y,z;
		for(i=0; i<n; i++)
			scanf("%lf%lf%lf",&s[i].x,&s[i].y,&s[i].z);
		makeFace();
		double V=0;
		for(i=0; i<face.SZ; i++)
			V+=((s[face[i][0]]-s[face[i][2]])^(s[face[i][1]]-s[face[i][2]])).len();
		printf("%.3f\n",V/2);
	}
	return 0;
}
