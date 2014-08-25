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
const LL MOD = 1000000007;
LL eulerPhi ( LL n ) {
	LL res = n;
	for ( LL i = 2; i * i <= n; i++ )		//可用质数加速
		if ( n % i == 0 ) {
			res = res / i * ( i - 1 );
			for ( ; n % i == 0; n /= i );
		}
	if ( n != 1 ) res = res / n * ( n - 1 );
	return res;
}
LL modPow ( LL a,LL b,LL c ) {
	LL ret=1;
	while ( b ) {
		if ( b&1 ) ret=ret*a%c;
		a=a*a%c;
		b>>=1;
	}
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,u,v,w,r,n,m;
	int T=0;
	LL p,q;
	while ( ~scanf ( "%I64d/%I64d",&p,&q ) ) {
		p%=q;
		LL g=__gcd ( p,q ),a=1,b=0;
		p/=g,q/=g;
		while ( q%2==0 ) q/=2,a++;
		if ( q>1 ) {
			LL t=eulerPhi ( q );
			b=t;
			for ( LL i=1; i*i<=t&&i<b; i++ ) if ( t%i==0 ) {
					if ( modPow ( 2,i,q ) ==1 ) cmin ( b,i );
					if ( ( t/i ) <b&&modPow ( 2,t/i,q ) ==1 ) cmin ( b,t/i );
				}
		}
		printf ( "Case #%d: %I64d,%I64d\n",++T,a,b );
	}
	return 0;
}
