#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define BG begin()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const double eps = 1e-8;
int sign(double x) {return x<-eps?-1:x>eps;}
struct spt {
	double x,y,z;
	spt(double _x=0,double _y=0,double _z=0) {x=_x,y=_y,z=_z;}
	spt operator + (spt s) {return spt(x+s.x,y+s.y,z+s.z);}
	spt operator - (spt s) {return spt(x-s.x,y-s.y,z-s.z);}
	spt operator *(double d) {return spt(x*d,y*d,z*d);}
	spt operator /(double d) {return spt(x/d,y/d,z/d);}
	double len() {return sqrt(x*x+y*y+z*z);}
	double len2() {return x*x+y*y+z*z;}
	double operator * (spt s) {return x*s.x+y*s.y+z*s.z;} //dot
	spt operator ^(spt s) { //det
		return spt(y*s.z-z*s.y,z*s.x-x*s.z,x*s.y-y*s.x);
	}
	bool operator < (const spt &s)const {
		if(sign(s.x-x)!=0)return sign(x-s.x)<0;
		if(sign(s.y-y)!=0)return sign(y-s.y)<0;
		return sign(z-s.z)<0;
	}
	bool operator ==(const spt &s)const {
		return sign(s.x-x)==0&&sign(s.y-y)==0&&sign(s.z-z)==0;
	}
	void output(char *s="") {printf("(%.3f,%.3f,%.3f)%s",x,y,z,s);}
} Orz(0,0,0);
struct sfl {
	spt u,v,w;
	sfl() {}
	sfl(spt U,spt V,spt W) {u=U,v=V,w=W;}
};
double callArea(spt A,spt B,spt C) {
	spt p=B-A,q=C-A;
	return (p^q).len()*0.5;
}
struct point {
	double x,y;
	point(double X=0,double Y=0) {x=X,y=Y;}
	point operator +(point p) {return point(x+p.x,y+p.y);}
	point operator -(point p) {return point(x-p.x,y-p.y);}
	point operator *(double d) {return point(x*d,y*d);}
	point operator /(double d) {return point(x/d,y/d);}
	double operator ^(point p) {return x*p.y-y*p.x;}
	double operator *(point p) {return x*p.x+y*p.y;}
	bool operator <(const point &p)const {
		return sign(x-p.x)==0?sign(y-p.y)<=0:sign(x-p.x)<=0;
	}
};
vector<point>ConvexHull(vector<point>p) {
	int n=p.SZ,m=0;
	vector<point>q;
	q.resize(n*2);
	sort(p.OP,p.ED);
	for(int i=0; i<n; i++) {
		while(m>1&&sign((q[m-1]-q[m-2])^(p[i]-q[m-2]))<=0)m--;
		q[m++]=p[i];
	}
	int k=m;
	for(int i=n-2; i>=0; i--) {
		while(m>k&&sign((q[m-1]-q[m-2])^(p[i]-q[m-2]))<=0)m--;
		q[m++]=p[i];
	}
	if(n>1)m--;
	q.resize(m);
	return q;
}
int isFL(spt p,spt o,spt q1,spt q2,spt &is) {
	double a=o*(q2-p);
	double b=o*(q1-p);
	double d=a-b;
	if(sign(d)==0)return 0;
	is=(q1*a-q2*b)/d;
	return 1;
}
spt touPF(spt p,sfl s) {
	spt o=(s.u-s.v)^(s.w-s.v),is;
	int flag=isFL(s.u,o,p,p+o,is);
	return is;
}
const int MXN = 55;
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
	while(~scanf("%d",&n)&&n) {
		for(i=0; i<n; i++)scanf("%lf%lf%lf",&s[i].x,&s[i].y,&s[i].z);
		makeFace();
		double ansH=0,ansS=0;
		for(i=0; i<face.SZ; i++) {
			double SS=0,HH=0;
			sfl p(s[face[i][0]],s[face[i][1]],s[face[i][2]]);
			spt o(p.u);
			spt ez=(p.v-p.u)^(p.w-p.u);
			spt ex=p.v-o;
			ex=ex/ex.len();
			spt ey=ex^ez;
			ey=ey/ey.len();
			vector<point>poly;
			for(j=0; j<n; j++) {
				spt is=touPF(s[j],p);
				double hnow=(is-s[j]).len();
				cmax(HH,hnow);
				spt t=is-o;
				poly.PB(point(t*ex,t*ey));
			}
			if(sign(HH-ansH)<0)continue;
			poly=ConvexHull(poly);
			if(!poly.empty())poly.PB(poly[0]);
			for(j=1; j<poly.SZ; j++)
				SS+=poly[j]^poly[j-1];
			SS/=2;
			if(SS<0)SS=-SS;
			if(sign(HH-ansH)>0)ansH=HH,ansS=SS;
			else if(sign(HH-ansH)==0)cmin(ansS,SS);
		}
		printf("%.3f %.3f\n",ansH,ansS);
	}
	return 0;
}
