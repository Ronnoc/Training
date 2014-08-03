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
#define SQ ((x)*(x))
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int,int> PII;
int X[5],Y[5];
int main() {
	int n,m,i,j,k,x,y;
	int CA=0;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		++CA;
		if ( !n&&!m )break;
		int S=n*m;
		int T=0;
		int a;
		scanf( "%d",&a );
		while ( a-- ) {
			scanf( "%d%d",&x,&y );
			int z=x*m+y;
			T|=1<<z;
		}
		int ans=0;
		for ( i=0; i<1<<S; i++ ) {
			int to=0;
			for ( x=0; x<n; x++ )for ( y=0; y<m; y++ ) {
					int z=x*m+y;
					int cnt=0;
					X[0]=x;
					X[1]=( x+1 )%n;
					X[2]=( x+n-1 )%n;
					Y[0]=y;
					Y[1]=( y+1 )%m;
					Y[2]=( y+m-1 )%m;
					for ( j=0; j<3; j++ )for ( k=0; k<3; k++ ) {
							int p=X[j],q=Y[k];
							int r=p*m+q;
							if ( i>>r&1 )cnt++;
							if ( cnt>4 )break;
						}
					if ( i>>z&1 ) {
						if ( cnt==3||cnt==4 )to|=1<<z;
					} else {
						if ( cnt==3 )to|=1<<z;
					}
					if ( ( to>>z&1 )!=( T>>z&1 ) )break;
				}
			if ( to==T )ans++;
		}
		if ( ans )printf( "Case %d: %d possible ancestors.\n",CA,ans );
		else printf( "Case %d: Garden of Eden.\n",CA );
	}
	return 0;
}
