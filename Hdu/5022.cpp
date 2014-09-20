#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
#define OP begin()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const double eps = 1e-8;
LL extGcd(LL a,LL b,LL &x,LL &y) {
	LL ret=a;
	if(b) {
		ret=extGcd(b,a%b,y,x);
		y-=(a/b)*x;
	} else x=1,y=0;
	return ret;
}
LL modInv(LL a,LL m) {
	LL x,y;
	extGcd(a,m,x,y);
	return (m+x%m)%m;
}
LL modPow(LL a,LL b,LL P) {
	LL ret=1;
	while(b) {
		if(b&1)ret=ret*a%P;
		a=a*a%P;
		b>>=1;
	}
	return ret;
}
vector<PII>L;
int LA=-1,LC=-1;
int extBSGS(int A,int B,int C) {			//A^x==B mod C
	for(int i=0,tmp=1%C; i<100; i++,tmp=1LL*tmp*A%C)
		if(tmp==B)return i;
	int s=(int)ceil(sqrt(C+eps))+1;
	if(LA!=A||LC!=C) {
		L.clear();
		LA=A,LC=C;
		LL G=1%C;
		for(int i=0; i<s; i++) {
			L.PB(MP(G,i));
			G=G*A%C;
		}
		sort(L.OP,L.ED);
	}
	LL G=modPow(A,s,C);
	LL D=1%C;
	for(int i=0; i<=s; i++) {
		int tmp=modInv(D,C)*B%C;
		int id=lower_bound(L.OP,L.ED,MP(tmp,-1))-L.OP;
		if(id<L.SZ&&id>=0&&L[id].AA==tmp)
			return i*s+L[id].BB;
		D=D*G%C;
	}
}
int findRoot(int P) {		//P>2
	int Q=P-1;						//Q=phi(P)
	int i,j;
	vector<int>F;
	for(i=2; i*i<=Q; i++)if(Q%i==0) {
			F.PB(i);
			while(Q%i==0)Q/=i;
		}
	if(Q>1)F.PB(i);
	Q=P-1;
	for(i=2; i<P; i++) {
		int fail=0;
		for(j=0; !fail&&j<F.SZ; j++) {
			int tmp=modPow(i,(P-1)/F[j],P);
			if(tmp==1)fail=1;
		}
		if(!fail)return i;
	}
	return -1;
}
LL getmin(LL start,LL slope,LL cnt,LL mod) {	//min{ (start+k*slope)%mod | 0<=k<=cnt }
	start%=mod;
	if(start+slope*cnt<mod)return start;
	if(start>=slope) {
		int use=(mod-1-start)/slope+1;
		return min(start,getmin(start+use*slope,slope,cnt-use,mod));
	}
	LL res=start;
	LL ns=slope-mod%slope;
	LL ncnt=(start+slope*cnt)/mod;
	return min(res,getmin(start,ns,ncnt,slope));
}
int main() {
	int i,j,k;
	int M,A,B,s,t,P;
	LL _X,_Y,x0,z0;
	while(~scanf("%d%d%d%d%d%d",&M,&A,&B,&s,&t,&P)) {
		if(!M&&!A&&!B&!s&&!t&&!P)break;
		int g=findRoot(P);
		int m=extBSGS(g,M,P);
		int a=extBSGS(g,A,P);
		int b=extBSGS(g,B,P);
//    cout<<g<<"^ "<<m<<" "<<a<<" "<<b<<endl;
		P--;
		int c=((1LL*b*s-m)%P+P)%P;
		int u=extGcd(a,P,_X,_Y);
		int v=extGcd(u,b,_X,_Y);
//    cout<<c<<" "<<u<<" "<<v<<endl;
		if(c%v) {
			printf("impossible\n");
			continue;
		}
		LL Uv=u/v,Bv=b/v;
		extGcd(Bv,Uv,x0,z0);
		LL X=-c/v*x0;
		LL DX=Uv;
		LL Z=c/v*z0;
		LL DZ=Bv;
//    cout<<(Z*Bv-X*Uv)<<" "<<(c/v)<<endl;
//    cout<<"X="<<X<<" DX="<<DX<<" Z="<<Z<<" DZ="<<DZ<<endl;
		LL TX=(X%DX+DX)%DX;
		LL tmp=(TX-X)/DX;
		X+=tmp*DX;
		Z+=tmp*DZ;
//    cout<<(Z*Bv-X*Uv)<<" "<<(c/v)<<endl;
		LL inv=modInv(a/u,P/u);
		LL PU=P/u;
//    cout<<"a="<<a<<" P="<<P<<" u="<<u<<endl;
//    cout<<"PU="<<PU<<endl;
//    cout<<"inv="<<inv<<endl;
//    cout<<"X="<<X<<" Z="<<Z<<endl;
//    cout<<"Uv="<<Uv<<" Bv="<<Bv<<endl;
//    cout<<(Z*Bv-X*Uv)<<" "<<(c/v)<<endl;
		int ans=-1;
		LL dltn=inv*DZ%PU;
		int tn=(Z*inv%PU+PU)%PU;
		LL cnt=(t-s-X)/DX;
		if(cnt>=0)
			ans=getmin(tn,dltn,cnt,PU);
		if(~ans)printf("%d\n",ans);
		else printf("impossible\n");
	}
	return 0;
}
