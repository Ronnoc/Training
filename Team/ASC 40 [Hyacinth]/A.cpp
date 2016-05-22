#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))
#define PROM "average"
double eps = 1e-8;
double PI = acos(-1.);
int sign(double x) {return x<-eps?-1:x>eps;}
struct point {
	double x,y;
	int id;
	point(double X=0,double Y=0,int i=-1):x(X),y(Y),id(i) {}
	point operator +(point p) {return point(x+p.x,y+p.y);}
	point operator -(point p) {return point(x-p.x,y-p.y);}
	point operator *(double d) {return point(x*d,y*d);}
	point operator /(double d) {return point(x/d,y/d);}
	double operator *(point p) {return x*p.x+y*p.y;} //dot
	double operator ^(point p) {return x*p.y-y*p.x;} //det
	double arc() {return atan2(y,x);}
	bool operator <(const point &p)const {
		if(sign(x-p.x))return sign(x-p.x)<0;
		return sign(y-p.y)<0;
	}
	bool operator ==(const point &p)const {
		if(sign(x-p.x))return 0;
		if(sign(y-p.y))return 0;
		return 1;
	}
	double lenSqr() {return x*x+y*y;}
	void read() {scanf("%lf%lf",&x,&y);}
	void write(char *s="") {printf("(%.2f,%.2f)%s",x,y,s);}
};
bool isLL(point p1,point p2,point q1,point q2,point &is) {
	double m=(q2-q1)^(p1-q1),n=(q2-q1)^(p2-q1);
	if(sign(n-m)==0)return 0;
	is=(p1*n-p2*m)/(n-m);
	return 1;
}
vector<point>ConvexHull(vector<point>p) {
	int n=p.SZ,m=0;
	vector<point>q;
	q.resize(n<<1);
	sort(p.OP,p.ED);
	for(int i=0; i<n; i++) {
		while(m>1&&sign((q[m-1]-q[m-2])^(p[i]-q[m-2]))<=0)
			m--;
		q[m++]=p[i];
	}
	int k=m;
	for(int i=n-2; i>=0; i--) {
		while(m>k&&sign((q[m-1]-q[m-2])^(p[i]-q[m-2]))<=0)
			m--;
		q[m++]=p[i];
	}
	if(n>1)m--;
	q.resize(m);
	return q;
}
point z[200005];
bool used[200005];
int le[200005];
int re[200005];
vector<point>P,Q;
vector<point>p,q;
point Orz;
int state(point &p1,point &p2,point &q) {
	return sign((p2-p1)^(q-p1));
	//p1->p2 left return 1
	//p1->p2 online return 0
	//p1->p2 right return -1
}
int qLeft(int id) {
	return (id+q.SZ-1)%q.SZ;
}
int qRight(int id) {
	return (id+1)%q.SZ;
}
bool longer(point &A,point &B,point &C) {
	double ab=(A-B).lenSqr();
	double ac=(A-C).lenSqr();
	return sign(ac-ab)>0;
}
int main() {
	freopen(PROM".in", "r", stdin);
	freopen(PROM".out", "w", stdout);
	int i,j;
	int n;
	point A(0,0),B(0,1),C(-1,1);
	while(~scanf("%d",&n)) {
		P.clear(),Q.clear();
		for(i=0; i<n; i++) {
			z[i].read();
			z[i].id=i;
			P.PB(z[i]);
			used[i]=0;
		}
		p=ConvexHull(P);
		if(p.SZ==2) {
			printf("2/1\n");
			continue;
		}
		for(i=0; i<p.SZ; i++)
			used[p[i].id]=1;
		for(i=0; i<n; i++)if(!used[i])
				Q.PB(z[i]);
		q=ConvexHull(Q);
		vector<pair<double,int> >LA;
		for(i=0; i<q.SZ; i++) {
			point A=q[i];
			point B=q[(i+1)%q.SZ];
			LA.PB(MP((B-A).arc(),i));
		}
		sort(LA.OP,LA.ED);
		LL ans=0;
		ans=1LL*p.SZ*(n-p.SZ);
		ans+=1LL*p.SZ*(p.SZ-1);
		le[0]=re[0]=0;
		if(!q.empty()) {
			for(i=0; i<p.SZ; i++) {
				point A=p[i];
				if(i)le[i]=le[i-1],re[i]=re[i-1];
				while(1) {
					int id=qLeft(le[i]);
					if(id==le[i])break;
					int st=state(A,q[le[i]],q[id]);
					if(st>0||(st==0&&longer(A,q[le[i]],q[id])))le[i]=id;
					else break;
				}
				while(1) {
					int id=qRight(le[i]);
					if(id==le[i])break;
					int st=state(A,q[le[i]],q[id]);
					if(st>0)le[i]=id;
					else break;
				}
				while(1) {
					int id=qRight(re[i]);
					if(id==re[i])break;
					int st=state(A,q[re[i]],q[id]);
					if(st<0||(st==0&&longer(A,q[re[i]],q[id])))re[i]=id;
					else break;
				}
				while(1) {
					int id=qLeft(re[i]);
					if(id==re[i])break;
					int st=state(A,q[re[i]],q[id]);
					if(st<0)re[i]=id;
					else break;
				}
//				p[i].write(":\t");
//				q[le[i]].write("~");
//				q[re[i]].write("\n");
			}
			for(i=0; i<p.SZ; i++) {
				point A=p[i],B=p[(i+2)%p.SZ];
				int id=re[i];
				if(state(A,B,q[id])>=0)continue;
				int f=re[i],t=le[(i+2)%p.SZ];
				if(t<f)t+=q.SZ;
				ans+=t-f+1;
//				p[i].write(": ");
//				printf("%d\n",t-f+1+p.SZ-1);
			}
		}
		LL m=n;
		LL g=__gcd(ans,m);
		ans/=g,m/=g;
		printf("%I64d/%I64d\n",ans,m);
	}
	return 0;
}
/*
5
-2 0 -1 0 1 0 2 0 0 1
=>14/5
*/
/*
3
0 0 0 1 0 2
=>2/1
*/
/*
3
0 0 1 1 0 2
=>2/1
*/
/*
4
0 0 1 0 2 0 3 0
=>2/1
*/
/*
5
0 0 0 4 4 0 3 3 4 4
=>17/5
*/
/*
10
-4 0 4 0 0 4 0 -4
-2 2 -2 -2 2 -2 2 2
0 5 0 -5
=>21/5
*/
/*
7
0 5 0 -5 1 0 0 3 0 -3 -1 0 -10 0
=>27/7
*/
/*
8
-3 0 3 0 0 1 0 -1 2 2 2 1 2 -1 2 -2
=>17/4
*/
/*
4
-4 0 4 0 0 4 0 0
=>11/4
*/
/*
6
-4 0 4 0 0 4 0 0
-2 2 -1 1
=>19/6
*/
/*
7
-4 0 4 0 0 4 0 0
-2 2 3 1 0 2
=>25/7
*/
/*
7
-4 0 4 0 0 4 0 0
-2 2 1 1 0 2
=>24/7
*/
/*
12
-3 0 0 -3 0 6 6 0
-1 4 -2 2 -1 -2 -2 -1
2 4 4 2 2 -2 4 -1
=>13/3
*/
