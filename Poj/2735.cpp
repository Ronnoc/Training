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
int u[22],v[22],w[22],n,m;
int dp[1<<20];
int cn[1<<20];
vector<pair<int,int> >L;
int fa[22];
int getfa( int u ) {return u==fa[u]?u:fa[u]=getfa( fa[u] );}
int check( int mask ) {
	int i,j;
	int cnt=n-1;
	for ( i=1; i<=n; i++ )fa[i]=i;
	while ( mask ) {
		int al=mask&( -mask );
		int la=__builtin_ctz( mask );
		mask^=al;
		int p=u[la],q=v[la];
		p=getfa( p ),q=getfa( q );
		if ( p!=q )fa[p]=q,cnt--;
	}
	return cnt==0;
}
int main() {
	int i,j;
	int CA=0;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		++CA;
		if ( !n&&!m )break;
		L.clear();
		for ( i=0; i<m; i++ )scanf( "%d%d%d",&u[i],&v[i],&w[i] );
		dp[0]=0,cn[0]=0;
		for ( i=1; i<1<<m; i++ ) {
			int cnt=__builtin_popcount( i );
			int al=i&( -i );
			int la=__builtin_ctz( i );
			dp[i]=dp[i^al]+w[la];
			cn[i]=-1;
			if ( cnt<n )continue;
			L.PB( MP( dp[i],i ) );
		}
		sort( L.begin(),L.end() );
		int ans=-1;
		for ( i=0; i<L.size(); i++ ) {
			int mask=L[i].BB;
			int tmp=mask;
			int flag=1;
			while ( tmp ) {
				int la=tmp&( -tmp );
				tmp^=la;
				if ( cn[mask^la]==-1 )cn[mask^la]=check( mask^la );
				if ( !cn[mask^la] ) {flag=0; break;}
			}
			if ( flag ) {ans=L[i].AA; break;}
		}
		if ( ~ans )printf( "The minimal cost for test case %d is %d.\n",CA,ans );
		else printf( "There is no reliable net possible for test case %d.\n",CA );
	}
	return 0;
}
