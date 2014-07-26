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
LL extGcd( LL a, LL b, LL &x, LL &y ) {
	LL ret = a;
	if ( b ) {
		ret = extGcd( b, a % b, y, x );
		y -= ( a / b ) * x;
	} else x = 1, y = 0;
	return ret;
}
LL modInv( LL a, LL m ) {
	LL x, y;
	extGcd( a,m,x,y );
	return ( m+x%m )%m;
}
pair<LL,LL> linearMod( vector<LL>&A,vector<LL>&B,vector<LL>&M ) {
	LL x=0,m=1;
	for ( int i=0; i<A.SZ; i++ ) {
		LL a=A[i]*m,b=B[i]-A[i]*x,d=__gcd( M[i],a );
		if ( b%d )return MP( 0,-1 );
		LL t=b/d*modInv( a/d,M[i]/d )%( M[i]/d );
		x+=m*t;
		m*=M[i]/d;
		x%=m;
	}
	return MP( ( ( x%m )+m )%m,m );
}
LL gao( LL a,LL x,LL b,LL mod ) {
	LL ret=a%mod;
	while(b){
		if(b&1)ret=ret*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,m,p;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		scanf( "%d%d%d",&n,&m,&p );
		//C(n+m-2,n-1)%p
		int N=n+m-2,M=n-1;
		//C(N,M)%p
		vector<PII>Lp;
		for ( i=2; i*i<=p; i++ )if ( p%i==0 ) {
				int cnt=0;
				while ( p%i==0 )p/=i,cnt++;
				Lp.PB( MP( i,cnt ) );
			}
		if ( p>1 )Lp.PB( MP( p,1 ) );
		vector<LL>A,B,C;
		for ( j=0; j<Lp.SZ; j++ ) {
			int mod=1;
			int cnt=Lp[j].BB;
			int x=Lp[j].AA;
			while ( cnt-- )mod*=x;
			A.PB( 1 );
			C.PB( mod );
			LL a=1,b=0;
			//a*(p^b);
			for ( i=N-M+1; i<=N; i++ ) {
				int t=i;
				while ( t%x==0 )t/=x,b++;
				a=a*t%mod;
			}
			for ( i=1; i<=M; i++ ) {
				int t=i;
				while ( t%x==0 )t/=x,b--;
				a=a*modInv( t,mod )%mod;
			}
//			cout<<a<<"*"<<x<<"^"<<b<<endl;
			B.PB( gao( a,x,b,mod ) );
		}
		pair<LL,LL>tp=linearMod( A,B,C );
		cout<<tp.AA<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
