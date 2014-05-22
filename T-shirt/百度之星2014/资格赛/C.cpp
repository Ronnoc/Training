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
LL p[111111];
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n,m;
		scanf( "%d%d",&n,&m );
		LL mx=0;
		for ( i=0; i<n; i++ )scanf( "%I64d",&p[i] );
		for ( i=0; i<n; i++ )cmax( mx,p[i] );
		sort( p,p+n );
		printf( "Case #%d:\n",CASE );
		int s=0;
		while ( mx>>s )s++;
		while ( m-- ) {
			LL q,z=0LL;
			scanf( "%I64d",&q );
			int le=0,re=n;
			for ( i=s; i>=0; i-- ) {
				LL add=1LL<<i;
				int a=lower_bound( p+le,p+re,z+add )-p;
				if ( q>>i&1LL ) {
					if ( a>le )re=a;
					else z+=add;
				} else {
					if ( a<re )le=a,z+=add;
				}
			}
			printf( "%I64d\n",z );
		}
	}
	return 0;
}
