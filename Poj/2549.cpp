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
int w[1111];
pair<int,PII> L[999005];
int il;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	while ( ~scanf( "%d",&n )&&n ) {
		for ( i=0; i<n; i++ )scanf( "%d",&w[i] );
		sort( w,w+n );
		il=0;
		for ( i=0; i<n; i++ )for ( j=i+1; j<n; j++ )
				L[il++]=MP( w[i]+w[j],MP( i,j ) );
		sort( L,L+il );
		int ans=-1;
		for ( i=n-1; i>=0; i-- )for ( j=0; ans<i&&j<n; j++ )if ( i!=j ) {
					int query=w[i]-w[j];
					int lid=lower_bound( L,L+il,MP( query,MP( -1,-1 ) ) )-L;
					while ( L[lid].AA==query ) {
						int u=L[lid].BB.AA;
						int v=L[lid].BB.BB;
						if ( u!=i&&u!=j&&v!=i&&v!=j ) {
							cmax( ans,i );
							break;
						}
						lid++;
					}
				}
		if ( ~ans )printf( "%d\n",w[ans] );
		else printf( "no solution\n" );
	}
	return 0;
}
