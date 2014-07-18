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
LL llpow( LL a,LL b,LL m ) {
	LL ret=1%m;
	while ( b ) {
		if ( b&1 )ret=ret*a%m;
		a=a*a%m;
		b/=2;
	}
	return ret;
}
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
int extBSGS( int A,int B,int C ) { //A^x==B mod C
	LL D=1%C;
	int s=( int )ceil( sqrt( C+eps ) )+1;
	vector<PII>L;
	LL G=1%C;
	for ( int i=0; i<s; i++ ) {
		L.PB( MP( G,i ) );
		G=G*A%C;
	}
	SORT( L );
	for ( int i=0; i<=s; i++ ) {
		int tmp=modInv( D,C )*B%C;
		int id=lower_bound( L.OP,L.ED,MP( tmp,-1 ) )-L.OP;
		if ( id<L.SZ&&id>=0&&L[id].AA==tmp )
			return i*s+L[id].BB;
		D=D*G%C;
	}
	return -1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int A,B,C;
	while ( ~scanf( "%d%d%d",&C,&A,&B ) ) {
		if ( !A&&!B&&!C )break;
		int ans=extBSGS( A,B,C );
		if ( ans<0||llpow( A,ans,C )!=B%C )puts( "no solution" );
		else printf( "%d\n",ans );
	}
	return 0;
}
