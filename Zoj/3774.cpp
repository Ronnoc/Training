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
const LL MOD = 1000000009;
LL llpow( LL a,LL b ) {
	a%=MOD;
	LL ret=1;
	while ( b ) {
		if ( b&1 )ret=ret*a%MOD;
		a=a*a%MOD;
		b/=2;
	}
	return ret;
}
LL s5=383008016;
LL invs5=llpow( s5,MOD-2 );
LL comb[100005];
LL v[100005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	for ( i=1; i<=100000; i++ )v[i]=llpow( i,MOD-2 );
	LL p,q;
	p=( 1+s5 )*v[2]%MOD;
	q=( 1-s5+MOD )*v[2]%MOD;
	int T;
	cin>>T;
	for ( int CA=1; CA<=T; ++CA ) {
		LL N,K;
		cin>>N>>K;
		comb[0]=1;
		for ( i=1; i<=K; i++ )comb[i]=comb[i-1]*( K+1-i )%MOD*v[i]%MOD;
		LL ans=0;
		for ( j=0; j<=K; j++ ) {
			LL f1,mu,fh;
			LL now;
			fh=llpow( MOD-1,K-j );
			f1=llpow( p,j )*llpow( q,K-j )%MOD;
			mu=f1;
			if ( mu!=1 )now=f1*( 1+MOD-llpow( mu,N ) )%MOD*llpow( 1+MOD-mu,MOD-2 )%MOD;
			else now=f1*N%MOD;
			ans=( ans+fh*comb[j]%MOD*now )%MOD;
		}
		ans=ans*llpow( invs5,K )%MOD;
		cout<<ans<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
