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
const double PI=acos( -1. );
const LL MOD = 1000000007;

const int S=20;
inline LL mutiMod( LL a,LL b,LL c ) { //返回(a*b) mod c,a,b,c<2^63
	a%=c,b%=c;
	LL ret=0;
	while ( b ) {
		if ( b&1 ) {
			ret+=a;
			if ( ret>=c ) ret-=c;
		}
		a<<=1,b>>=1;
		if ( a>=c ) a-=c;
	}
	return ret;
}
inline LL powMod( LL x,LL n,LL mod ) { //返回x^n mod c ,非递归版
	LL ret=1;
	while ( n ) {
		if ( n&1 )ret=mutiMod( ret,x,mod );
		x=mutiMod( x,x,mod );
		n>>=1;
	}
	return ret;
}
bool check( LL a,LL n,LL x,LL t ) { //以a为基，n-1=x*2^t，检验n是不是合数
	LL ret=powMod( a,x,n ),last=ret;
	for ( int i=1; i<=t; i++ ) {
		ret=mutiMod( ret,ret,n );
		if ( ret==1&& last!=1&& last!=n-1 ) return 1;
		last=ret;
	}
	if ( ret!=1 ) return 1;
	return 0;
}
bool Miller_Rabin( LL n ) {
	LL x=n-1,t=0;
	while ( ( x&1 )==0 ) x>>=1,t++;
	bool flag=1;
	if ( t>=1&& ( x&1 )==1 ) {
		for ( int k=0; k<S; k++ ) {
			LL a=rand()%( n-1 )+1;
			if ( check( a,n,x,t ) ) {flag=1; break;}
			flag=0;
		}
	}
	if ( !flag || n==2 ) return 0;
	return 1;
}
vector<LL>factor;
LL Pollard_rho( LL x,LL c ) {
	LL i=1,x0=rand()%x,y=x0,k=2;
	while ( i++ ) {
		x0=( mutiMod( x0,x0,x )+c )%x;
		LL d=__gcd( y>x0?y-x0:x0-y,x );
		if ( d!=1&& d!=x ) return d;
		if ( y==x0 ) return x;
		if ( i==k ) y=x0,k<<=1;
	}
}
void findfac( LL n ) {        //递归进行质因数分解N
	if ( !Miller_Rabin( n ) ) {
		factor.PB( n );
		return;
	}
	LL p=n;
	while ( p>=n ) p=Pollard_rho( p,rand() % ( n-1 ) +1 );
	findfac( p );
	findfac( n/p );
}

LL extGcd( LL a, LL b, LL &x, LL &y ) {
	LL ret = a;
	if ( b ) {
		ret = extGcd( b, a % b, y, x );
		y -= ( a / b ) * x;
	} else
		x = 1, y = 0;
	return ret;
}
LL modInv( LL a, LL m ) {
	LL x, y;
	extGcd( a,m,x,y );
	return ( m+x%m )%m;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	LL C,E,N;
	while ( cin>>C>>E>>N ) {
		factor.clear();
		findfac( N );
		LL P=factor[0];
		LL Q=factor[1];
		LL T=( P-1 )*( Q-1 );
		LL D=modInv( E,T );
		LL ans=powMod( C,D,N );
		cout<<ans<<endl;
	}
	return 0;
}
