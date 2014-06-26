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
int a[500005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int n;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		multiset<int>ID,S;
		ID.insert( 1 );
		ID.insert( 2 );
		LL ans=0;
		for ( i=3; i<=n; i++ ) {
			while ( ID.SZ>1 ) {
				int r=*( --ID.ED );
				int l=*( --( --ID.ED ) );
				if ( a[r]<=a[l]&&a[r]<=a[i] ) {
					ID.erase( r );
					ans+=min( a[l],a[i] );
				}else break;
			}
			ID.insert( i );
		}
		for ( multiset<int>::iterator it=ID.OP; it!=ID.ED; ++it )S.insert( a[*it] );
		while ( S.SZ>2 ) {
			ans+=*S.OP;
			S.erase( S.OP );
		}
		cout<<ans<<endl;
	}
	return 0;
}
