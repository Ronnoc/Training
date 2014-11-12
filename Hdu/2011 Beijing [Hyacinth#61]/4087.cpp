#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
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
int sign(double x){return x<-eps?-1:x>eps;}
char buf[100005];
void show(double x,char *s=""){
	sprintf(buf,"%.2f",x+1e-3);
	if(strcmp(buf,"-0.00")==0)
		sprintf(buf,"0.00");
	printf("%s%s",buf,s);
}
struct spt {
	long double x,y,z;
	spt(long double X=0,long double Y=0,long double Z=0) {x=X,y=Y,z=Z;}
	spt operator +(spt s) {return spt(x+s.x,y+s.y,z+s.z);}
	spt operator -(spt s) {return spt(x-s.x,y-s.y,z-s.z);}
	spt operator *(long double d) {return spt(x*d,y*d,z*d);}
	spt operator /(long double d) {return spt(x/d,y/d,z/d);}
	long double operator *(spt s) {return x*s.x+y*s.y+z*s.z;}
	spt operator ^(spt s) {
		spt ret;
		ret.x=y*s.z-z*s.y;
		ret.y=z*s.x-x*s.z;
		ret.z=x*s.y-y*s.x;
		return ret;
	}
	long double len() {return sqrt(x*x+y*y+z*z);}
	void normal() {
		long double ll=len();
		x/=ll,y/=ll,z/=ll;
	}
	void read() {
		double p,q,r;
		scanf("%lf%lf%lf",&p,&q,&r);
		x=p,y=q,z=r;
	}
	void write() {
		show(x," ");
		show(y," ");
		show(z,"\n");
	}
};
struct mat {
	long double _[4][4];
	mat() {for(int i=0; i<4; i++)for(int j=0; j<4; j++)_[i][j]=0;}
	long double *operator [](int id) {return _[id];}
	mat friend operator *(mat a,mat b) {
		mat ret;
		int i,j,k;
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				for(k=0; k<4; k++)
					ret[i][j]+=a[i][k]*b[k][j];
		return ret;
	}
	mat operator ^(LL m) {
		mat ret,A=*this;
		ret.eee();
		while(m) {
			if(m&1)ret=ret*A;
			A=A*A;
			m>>=1;
		}
		return ret;
	}
	spt gao(spt a) {
		long double b[4];
		b[0]=a.x,b[1]=a.y,b[2]=a.z,b[3]=1;
		long double c[4];
		int i,j;
		for(i=0; i<4; i++)c[i]=0;
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				c[i]+=_[i][j]*b[j];
		return spt(c[0],c[1],c[2]);
	}
	void eee() {for(int i=0; i<4; i++)for(int j=0; j<4; j++)_[i][j]=(i==j)?1:0;}
	void write(){
//		for(int i=0;i<4;i++,puts(""))
//			for(int j=0;j<4;j++)show(_[i][j],"\t");
	}
};
const long double PI = acos(-1.)/180;
mat rotate(spt S,long double A) {
	A=-A*PI;
	long double Cos=cos(A),Sin=sin(A);
	S.normal();
	long double x=S.x,y=S.y,z=S.z;
	spt X;
	if(0){
	}else if((spt(1,0,0)^S).len()>eps){
		X=spt(1,0,0);
	}else if((spt(0,1,0)^S).len()>eps){
		X=spt(0,1,0);
	}else {
		X=spt(0,0,1);
	}
	X=X^S;
	spt Y=X^S;
	spt Z=S;
	X.normal();
	Y.normal();
	Z.normal();
	mat rot;
	rot[0][0]=Cos;
	rot[0][1]=-Sin;
	rot[1][0]=Sin;
	rot[1][1]=Cos;
	rot[2][2]=rot[3][3]=1;
	mat T;
	T[0][0]=X.x,T[0][1]=X.y,T[0][2]=X.z;
	T[1][0]=Y.x,T[1][1]=Y.y,T[1][2]=Y.z;
	T[2][0]=Z.x,T[2][1]=Z.y,T[2][2]=Z.z;
	T[3][3]=1;
	mat TT;
	int i,j;
	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			TT[i][j]=T[j][i];
	return TT*rot*T;
	mat ret;
	double Cos=cos(A),Sin=sin(A);
	S.normal();
	ret[3][3]=1;
	ret[0][0]=x*x+(1-x*x)*Cos;
	ret[0][1]=x*y*(1-Cos)-z*Sin;
	ret[0][2]=x*z*(1-Cos)+y*Sin;
	ret[1][0]=y*x*(1-Cos)+z*Sin;
	ret[1][1]=y*y+(1-y*y)*Cos;
	ret[1][2]=y*z*(1-Cos)-x*Sin;
	ret[2][0]=z*x*(1-Cos)-y*Sin;
	ret[2][1]=z*y*(1-Cos)+x*Sin;
	ret[2][2]=z*z+(1-z*z)*Cos;
	return ret;
}
mat scale(spt S) {
	mat ret;
	ret[0][0]=S.x;
	ret[1][1]=S.y;
	ret[2][2]=S.z;
	ret[3][3]=1;
	return ret;
}
mat translate(spt S) {
	mat ret;
	ret.eee();
	ret[0][3]=S.x;
	ret[1][3]=S.y;
	ret[2][3]=S.z;
	return ret;
}
mat solve() {
	char s[55];
	mat ret;
	ret.eee();
	while(1) {
		scanf("%s",s);
		spt S;
		if(s[1]=='r') {
			S.read();
			ret=translate(S)*ret;
		} else if(s[1]=='c') {
			S.read();
			ret=scale(S)*ret;
		} else if(s[1]=='o') {
			S.read();
			double A;
			scanf("%lf",&A);
			ret=rotate(S,A)*ret;
		} else if(s[1]=='e') {
			LL m;
			scanf("%I64d",&m);
			mat tmp=solve()^m;
			ret=tmp*ret;
		} else if(s[1]=='n')return ret;
	}
}
int main() {
	int i,j;
	int n;
	while(~scanf("%d",&n)&&n) {
		mat Z=solve();
		while(n--) {
			spt S;
			S.read();
			Z.gao(S).write();
		}
		printf("\n");
	}
	return 0;
}
