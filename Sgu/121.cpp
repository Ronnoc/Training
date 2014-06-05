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
vector<int>G[111];
set<int>S[111];
int vis[111];
int w[111];
int n;
int dfs( int u ) {
	vis[u]=1;
	for ( int i=0; i<G[u].SZ; i++ ) {
		int v=G[u][i];
		if ( vis[v] )continue;
		vis[v]=1;
		for ( set<int>::iterator it=S[v].OP; it!=S[v].ED; ++it ) {
			int tp=*it;
			if ( G[tp].SZ==1||w[tp]+1<G[tp].SZ||dfs( tp ) ) {
				w[u]--;
				w[v]--;
				S[u].insert( v );
				S[v].insert( u );
				w[v]++;
				w[tp]++;
				S[v].erase( S[v].find( tp ) );
				S[tp].erase( S[tp].find( v ) );
				return 1;
			}
		}
		if ( w[v]>1||( G[v].SZ==1&&w[v]>0 ) ) {
			w[u]--;
			w[v]--;
			S[u].insert( v );
			S[v].insert( u );
			return 1;
		}
		vis[v]=0;
	}
	vis[u]=0;
	return 0;
}
int main() {
	int i,j;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=1; i<=n; i++ )G[i].clear();
		for ( i=1; i<=n; i++ )S[i].clear();
		for ( i=1; i<=n; i++ ) {
			int v;
			while ( ~scanf( "%d",&v )&&v )G[i].PB( v );
			w[i]=G[i].SZ;
		}
		for ( int t=1; t<=n; t++ ) {
			for ( i=1; i<=n; i++ )if ( S[i].empty()&&w[i]>1 ) {
					memset( vis,0,sizeof vis );
					dfs( i );
				}
		}
		int flag=1;
		for ( i=1; i<=n; i++ )if ( S[i].empty()&&w[i]>1 )flag=0;
		for ( i=1; i<=n; i++ )if ( G[i].SZ>1&&w[i]==0 )flag=0;
		if ( flag ) {
			for ( i=1; i<=n; i++ ) {
				for ( j=0; j<G[i].SZ; j++ ) {
					if ( S[i].count( G[i][j] ) )printf( "1 " );
					else printf( "2 " );
				}
				printf( "0\n" );
			}
		} else printf( "No solution\n" );
	}
	return 0;
}
