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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
LL llpow( LL a,LL b ) {
	LL ret=1;
	while ( b ) {
		if ( b&1 )ret=ret*a%MOD;
		a=a*a%MOD;
		b/=2;
	}
	return ret;
}
int fact[3000005];	//预处理n! mod p 的表 O(n)
// n!=a*p^e return a%p
LL modFact( int n, LL p, int &e ) {
	e = 0;
	if ( !n ) return 1;
	int res = modFact( n / p, p, e );
	e += n / p;
	if ( n / p % 2 )
		return res * ( p - fact[n % p] ) % p;
	return res * fact[n % p] % p;
}
//C _(n) ^(k) %p
LL modComb( int n, int k, LL p ) {
	if ( n < 0 || k < 0 || n < k ) return 0;
	int e1, e2, e3;
	LL a1 = modFact( n, p, e1 );
	LL a2 = modFact( k, p, e2 );
	LL a3 = modFact( n - k, p, e3 );
	if ( e1 > e2 + e3 ) return 0;
	return a1 * llpow( a2 * a3 % p, p-2 ) % p;
}
int main() {
	int i,j;
	int T;
	fact[0]=1;
	for(i=1;i<=3000000;i++)fact[i]=(1LL*fact[i-1]*i)%MOD;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n;
		scanf("%d",&n);
		LL ans=modComb(2*n,n,MOD);
		ans*=llpow(n+1,MOD-2);
		ans%=MOD;
		printf("Case #%d:\n%d\n",CASE,(int)(ans));
	}
	return 0;
}
