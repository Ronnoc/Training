#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define PB push_back
#define OP begin()
#define ED end()
#define SZ size()
const double eps=1e-8;
int sign(double x) {return x<-eps?-1:x>eps;}
struct point {
	double x, y;
	point(double _x=0, double _y=0) : x(_x), y(_y) {}
	point operator - (point p) {return point(x-p.x,y-p.y);}
	point operator + (point p) {return point(x+p.x,y+p.y);}
	point operator * (double d) {return point(x*d,y*d);}
	point operator / (double d) {return point(x/d,y/d);}
	double operator ^(point p) {return x*p.y-y*p.x;}
} Orz(0,0);
bool isLL(point p1, point p2, point q1, point q2 ,point &is) {
	double m=(q2-q1)^(p1-q1),n=(q2-q1)^(p2-q1);
	if(sign(n-m)==0)return 0;
	is= (p1*n-p2*m)/(n-m);
	return 1;
}
int nt,tx[22],ty[22];
point t[22];
bool inner(double x,double l,double r) {
	if(r<l)swap(l,r);
	return sign(x-l)>=0&&sign(r-x)>=0;
}
bool onLine(point p,point q1,point q2) {
	return sign((q1-p)^(q2-p))==0;
}
bool inner(point p,point q1,point q2) {
	if(!inner(p.x,q1.x,q2.x))return 0;
	if(!inner(p.y,q1.y,q2.y))return 0;
	return 1;
}
point W(pow(2.,1./3),pow(3.,1./3));
int inOut(point p) {
	int i,cnt=0;
	point is;
	for(i=0; i<nt; i++)if(onLine(p,t[i],t[i+1])&&inner(p,t[i],t[i+1]))return 0;
	for(i=0; i<nt; i++)if(inner(p,t[i],t[i]))return 0;
	for(i=0; i<nt; i++) {
		int flag=isLL(p,p+W,t[i],t[i+1],is);
		if(flag&&inner(is,t[i],t[i+1])&&inner(is,p,p+W*1000))cnt++;
	}
	if(cnt%2==0)return -1;//Outside
	return 1;             //Inside
}
int main() {
	int i,j,k,T;
	int v,b,g;
	point is;
	while(~scanf("%d%d%d",&v,&b,&g)) {
		if(!v&&!b&&!g)break;
		for(scanf("%d",&nt),i=0; i<nt; i++) {
			scanf("%d%d",&tx[i],&ty[i]);
			t[i]=point(tx[i],ty[i]);
		}
		tx[nt]=tx[0],ty[nt]=ty[0],t[nt]=t[0];
		v*=-1;
		bool got=0;
		double ans;
		if(g==0||v==0) {
			point U(v,b);
			vector<point>Y;
			for(i=0; i<nt; i++) {
				int flag=isLL(Orz,U,t[i],t[i+1],is);
				if(flag&&inner(is,t[i],t[i+1]))Y.PB(is);
			}
			for(i=0; i<Y.SZ; i++)
				for(j=i+1; j<Y.SZ; j++)
					if(Y[j].y<Y[i].y)
						swap(Y[i],Y[j]);
			for(i=0; i+1<Y.SZ; i++) {
				int flag=inOut((Y[i]+Y[i+1])*0.5);
				if(flag==1) {
					ans=Y[i].y,got=1;
					break;
				}
			}
			if(got) {
				if(g==0)printf("%.2f\n",ans/b);
				else {
					double dlt=b*b-2*g*ans;
					if(sign(dlt)<=0)printf("Miss!\n");
					else printf("%.2f\n",(b-sqrt(dlt))/g);
				}
			} else printf("Miss!\n");
		} else {
			vector<double>X;
			double D=b*1./v,E=g*0.5/(v*v);
			for(i=0; i<nt; i++) {
				X.PB(tx[i]);
				if(tx[i]!=tx[i+1]) {
					double A=ty[i+1]-ty[i],B=tx[i+1]-tx[i];
					double C=ty[i]*tx[i+1]-tx[i]*ty[i+1];
					double P=E*B,Q=A-D*B,R=C;
					double dlt=Q*Q-4*P*R+eps;
					if(sign(dlt)<0)continue;
					dlt=sqrt(dlt)/(2*P);
					double mid=-Q/(2*P);
					if(inner(mid-dlt,tx[i],tx[i+1]))X.PB(mid-dlt);
					if(inner(mid+dlt,tx[i],tx[i+1]))X.PB(mid+dlt);
				}
			}
			sort(X.OP,X.ED);
			X.erase(unique(X.OP,X.ED),X.ED);
			if(v<0)reverse(X.OP,X.ED);
			for(i=0; i+1<X.SZ; i++) {
				double xx=(X[i]+X[i+1])*0.5;
				int flag=sign(is.y)>0?inOut(point(xx,(D-E*xx)*xx)):0;
				if(flag==1) {
					ans=X[i]/v,got=1;
					break;
				}
			}
			if(got)printf("%.2f\n",ans+eps);
			else printf("Miss!\n");
		}
	}
	return 0;
}
/*
8 2 2	 	3 	-6 8 		-1 7 		-8 1	//Miss!
10 3 3 	3 	9 8 		-7 1 		2 5		//0.63
3 10 5 	3 	-1 3 		10 8 		9 6 	//0.33
-1 4 0 	3 	-77 9 	-8 46 	81 57	//8.76
1 3 0 	3 	-40 32 	92 8 		81 62	//8.77
-6 9 4 	3 	9 9 		100 1 	99 36	//2.10
3 3 4 	3 	-87 1 	-54 25 	87 1	//0.50
4 10 3 	3 	-45 62 	-17 1 	6 27	//1.69
7 10 1	3		-1 10		1 6			-9 1	//0.41
-9 3 3	3		1 9			3 10		4 1		//0.44
*/
