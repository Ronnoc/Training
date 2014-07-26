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
	} else
		x = 1, y = 0;
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
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n;
	while ( cin>>n ) {
		vector<LL>A,B,C;
		while ( n-- ) {
			LL a,r;
			cin>>a>>r;
			A.PB( 1 );
			B.PB( r );
			C.PB( a );
		}
		pair<LL,LL>ans=linearMod( A,B,C );
		if ( ans.BB==-1LL )cout<<-1<<endl;
		else cout<<ans.AA<<endl;
	}
	return 0;
}
