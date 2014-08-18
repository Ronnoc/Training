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
const double PI=acos ( -1. );
const LL MOD = 1000000009;
LL f ( LL a ) {
	if ( max ( a,-a ) >=MOD ) a%=MOD;
	if ( a<0 ) a+=MOD;
	return a;
}
LL modPow ( LL a,LL b ) {
	a=f(a);
	LL ret=1;
	while ( b ) {
		if ( b&1 ) ret=f ( ret*a );
		a=f ( a*a );
		b>>=1;
	}
	return ret;
}
struct dot {
	LL a,b; //a+b*sqrt(5)
	dot ( LL _a=0,LL _b=0 ) :a ( f ( _a ) ),b ( f ( _b ) ) {}
	void output(){cout<<a<<"+"<<b<<"*_5"<<endl;}
	dot operator + ( dot d ) {return dot ( a+d.a,b+d.b );}
	dot operator - ( dot d ) {return dot ( a-d.a,b-d.b );}
	dot operator * ( dot d ) {return dot ( a*d.a+5*b*d.b,b*d.a+a*d.b );}
	dot operator * ( LL i ) {return dot ( a*f(i),b*f(i) );}
	dot operator / ( dot x ) {
		LL c=x.a,d=x.b;
		dot ret= ( *this ) *dot(c,-d);
		LL inv=modPow ( f ( c*c-d*d*5 ),MOD-2 );
		return ret*inv;
	}
	dot operator ^ ( LL x ) {
		dot ret ( 1,0 ),t=*this;
		while ( x ) {
			if ( x&1 ) ret=ret*t;
			t=t*t;
			x>>=1;
		}
		return ret;
	}
};
LL inv[100005];
LL fac[100005];
LL invFac[100005];
LL comb[100005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	for ( inv[1]=1,i=2; i<=100000; i++ ) inv[i] = f ( inv[MOD%i] * ( MOD-MOD/i ) );
	for ( fac[0]=1,i=1; i<=100000; i++ ) fac[i] = f ( fac[i-1] * i );
	invFac[100000]=modPow(fac[100000],MOD-2);
	for(i=100000;i>=1;i--)invFac[i-1]=f(invFac[i]*i);
	dot ONE(1,0);
	dot phi=dot(1,1)*inv[2];
	dot _phi=dot(1,-1)*inv[2];
	int T;
	cin>>T;
	while(T--){
		LL n,k;
		cin>>n>>k;
		for(comb[0]=1,j=1;j<=k;j++)comb[j]=f( f(fac[k]*invFac[j])*invFac[k-j] );
		dot ret,per=ONE/(dot(0,1)^k);
		LL sign=modPow(-1,k);
		for(j=0;j<=k;j++){
			dot qj=(phi^j)*(_phi^(k-j)),ADD;
			dot tmp=qj*((qj^n)-ONE)/(qj-ONE);
			if(j*2==k&&j%2==0)tmp=qj*n;
			ret=ret+tmp*f(comb[j]*sign);
			sign=f(-sign);
		}
		ret=ret*per;
		cout<<ret.a<<"\n";
	}
	return 0;
}
