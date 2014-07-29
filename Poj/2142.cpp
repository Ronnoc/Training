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
int mabs(LL a){return a<0?-a:a;}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	LL a,b,c,x,y;
	while ( cin>>a>>b>>c ) {
		if ( !a&&!b&&!c )break;
		int g=__gcd( a,b );
		assert( c%g==0 );
		c/=g,a/=g,b/=g;
		extGcd( a,b,x,y );
		x*=c;
		y*=c;
		int f1=mabs( x )+mabs( y );
		int f2=mabs( a*x )+mabs( b*y );
		while ( 1 ) {
			int _x=x+b;
			int _y=y-a;
			int g1=mabs( _x )+mabs( _y );
			int g2=mabs( a*_x )+mabs( b*_y );
			if ( MP( g1,g2 )<=MP( f1,f2 ) )
				f1=g1,f2=g2,x=_x,y=_y;
			else break;
		}
		while ( 1 ) {
			int _x=x-b;
			int _y=y+a;
			int g1=mabs( _x )+mabs( _y );
			int g2=mabs( a*_x )+mabs( b*_y );
			if ( MP( g1,g2 )<=MP( f1,f2 ) )
				f1=g1,f2=g2,x=_x,y=_y;
			else break;
		}
		printf( "%d %d\n",mabs( x ),mabs( y ) );
	}
	return 0;
}
