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
int clr[33],tot,n;
int G[33][33];
void dfs( int u ) {
	int i,j;
	int vis[33];
	memset( vis,0,sizeof vis );
	for ( i=0; i<n; i++ )if ( G[u][i]&&clr[i]!=-1 )vis[clr[i]]=1;
	for ( i=1; i<=n; i++ )if ( !vis[i] )break;
	clr[u]=i;
	cmax( tot,i );
	for ( i=0; i<n; i++ )if ( G[u][i]&&clr[i]==-1 )dfs( i );
}
int solve( int u ) {
	tot=0;
	dfs( u );
	return tot;
}
int main() {
	int i,j;
	while ( ~scanf( "%d",&n )&&n ) {
		memset( G,0,sizeof G );
		char s[44];
		for ( i=1; i<=n; i++ ) {
			memset( s,0,sizeof s );
			scanf( "%s",s );
			int u=s[0]-'A';
			for ( j=2; s[j]; j++ )G[u][s[j]-'A']=G[s[j]-'A'][u]=1;
		}
		int ans=0;
		memset( clr,-1,sizeof clr );
		for ( i=0; i<n; i++ )if ( clr[i]==-1 )cmax( ans,solve( i ) );
		if ( tot<2 )printf( "%d channel needed.\n",ans );
		else printf( "%d channels needed.\n",ans );
	}
	return 0;
}
