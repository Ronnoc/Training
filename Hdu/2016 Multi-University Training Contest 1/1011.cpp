#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const long double PI = acos(-1.);
const long double eps = 1e-6;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
int sign(long double x){return x<-eps?-1:x>eps;}
struct spt {
	long double x,y,z;
	spt( long double _x=0,long double _y=0,long double _z=0 ):x( _x ),y( _y ),z(_z) {}
	spt operator +( spt s ) {return spt( x+s.x,y+s.y,z+s.z );}
	spt operator -( spt s ) {return spt( x-s.x,y-s.y,z-s.z );}
	spt operator *(long double d) {return spt(x*d,y*d,z*d);}
	spt operator /(long double d) {return spt(x/d,y/d,z/d);}
	long double len() {return sqrt( SQ(x)+SQ(y)+SQ(z) );}
	spt normal() {long double d=(*this).len();return (*this)/d;}
	long double operator *( spt s ) {return x*s.x+y*s.y+z*s.z;} //dot
	spt operator ^( spt s ) {	//det
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
	void read() {double xx,yy,zz;scanf("%lf%lf%lf",&xx,&yy,&zz);x=xx,y=yy,z=zz;}
	void write(char *s="") {printf( "(%.6f %.6f %.6f)%s",x,y,z,s );}
} Orz( 0,0,0 );
struct sfl {
	spt p,o;
	sfl() {}
	sfl( spt _p,spt _o ):p( _p ),o( _o ) {}
	sfl( spt u,spt v,spt w ) {p=u,o=( ( v-u )^( w-u ) ).normal();}
};
long double disLP( spt p1,spt p2,spt q ) {
	return fabs( ( ( p2-p1 )^( q-p1 ) ).len()/( ( p2-p1 ).len() ) );
}
long double disLL( spt p1,spt p2,spt q1,spt q2 ) {
	spt p=q1-p1,u=p2-p1,v=q2-q1;
	long double d=( u*u )*( v*v )-SQ( u*v );
	if ( sign( d )==0 )return disLP( q1,q2,p1 );
	long double s=( ( p*u )*( v*v )-( p*v )*( u*v ) )/d;
	return disLP( q1,q2,p1+u*s );
}
bool isFL( sfl f,spt q1,spt q2,spt &is ) {
	long double a=f.o*( q2-f.p ),b=f.o*( q1-f.p );
	long double d=a-b;
	if ( sign( d )==0 )return 0;
	is=( q1*a-q2*b )/d;
	return 1;
}
bool isFF( sfl a,sfl b,spt &is1,spt &is2 ) {
	spt e=a.o^b.o;
	spt v=a.o^e;
	long double d=b.o*v;
	if ( sign( d )==0 )return 0;
	is1=a.p+v*( b.o*( b.p-a.p ) )/d;
	is2=is1+e;
	return 1;
}

void solve(){
	spt A,B,C,D;
	double xx,yy,zz;
	while(~scanf("%lf%lf%lf",&xx,&yy,&zz)){
		A=spt(xx,yy,zz);
		B.read();
		C.read();
		D.read();
		if(sign(((B-A)^(C-A)).len())==0){
			printf("O O O O\n");
			continue;
		}
		sfl ABC(A,B,C);
		sfl ABD(A,B,D);
		sfl ACD(A,C,D);
		sfl BCD(B,C,D);
		spt H;
		isFL(ABC,D,D+ABC.o,H);
		if(sign((H-D).len())==0){
			printf("O O O O\n");
			continue;
		}
		long double abc=((B-A)^(C-A)).len();
		long double abd=((B-A)^(D-A)).len();
		long double acd=((C-A)^(D-A)).len();
		long double bcd=((C-B)^(D-B)).len();
		long double r=(abc*(H-D).len())/(abc+abd+acd+bcd);
		spt is;
		sfl dd(ABC.p+(D-H).normal()*r,ABC.o);
		isFL(ABD,C,C+ABD.o,is);
		sfl cc(ABD.p+(C-is).normal()*r,ABD.o);
		spt pe,qe;
		isFF(cc,dd,pe,qe);
		isFL(ACD,B,B+ACD.o,is);
		sfl bb(ACD.p+(B-is).normal()*r,ACD.o);
		isFL(bb,pe,qe,is);
		printf("%.4f %.4f %.4f %.4f\n",(double)(is.x),(double)(is.y),(double)(is.z),(double)(r));
	}
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}