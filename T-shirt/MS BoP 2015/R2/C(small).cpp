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
const int N = 1005;
int n,w[N];
vector<PII>G[N];
LL ans;
void dfs( int u,int fa,int wr,LL _d ) {
	cmax( ans,1LL*min( wr,w[u] )*_d );
	for ( int i=0; i<G[u].SZ; i++ ) {
		int v=G[u][i].AA;
		int c=G[u][i].BB;
		if ( v==fa )continue;
		dfs( v,u,wr,c+_d );
	}
}
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n;
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ )scanf( "%d",&w[i] );
		for ( i=1; i<=n; i++ )G[i].clear();
		for ( i=1; i<n; i++ ) {
			int u,v,c;
			scanf( "%d%d%d",&u,&v,&c );
			G[u].PB( MP( v,c ) );
			G[v].PB( MP( u,c ) );
		}
		ans=0;
		for ( i=1; i<=n; i++ )dfs( i,-1,w[i],0 );
		printf( "Case %d: %lld\n",CASE,ans );
	}
	return 0;
}
