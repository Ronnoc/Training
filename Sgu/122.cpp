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
int G[1002][1002];
int vis[1002];
int n;
void dfs( int u,int f,vector<int>&L ) {
	vis[u]=1;
	L.PB( u );
	for ( int v=1; v<=n; v++ )if(G[u][v]) {
		if ( vis[v]||v==f )continue;
		dfs( v,u,L );
		return;
	}
}
int main() {
	int i,j,u;
	memset(G,0,sizeof G);
	scanf( "%d%*c",&n );
	memset( vis,0,sizeof vis );
	char c;
	for ( i=1; i<=n; i++ ) {
		while ( ~scanf( "%d%c",&u,&c ) ) {
			G[u][i]=1;
			G[i][u]=1;
			if ( c=='\n' )break;
		}
	}
	vector<int>L,R;
	dfs( 1,-1,L );
	dfs( 1,-1,R );
	vector<int>W;
	for ( i=R.SZ-1; i; i-- )W.PB( R[i] );
	for ( i=0; i<L.SZ; i++ )W.PB( L[i] );
//	for ( i=0; i<W.SZ; i++ )cout<<W[i]<<" "; cout<<endl;
	while ( W.SZ<n ) {
		for ( i=1; i<=n; i++ )if ( !vis[i] )break;
		u=i;
		vector<int>Q;
		for ( i=0; i<W.SZ; i++ ) {
			Q.PB( W[i] );
			if ( !vis[u]&&G[W[i]][u]&&G[W[( i+1 )%W.SZ]][u]) {
				Q.PB( u );
				vis[u]=1;
			}
		}
		if ( !vis[u] )printf( "%d",1/0 );
		W=Q;
	}
	for ( i=1; i<W.SZ; i++ ) {
		int u=W[i-1],v=W[i];
		if ( G[v][W[0]]&&G[u][W[W.SZ-1]] ) {
			reverse( W.OP,W.OP+i );
			break;
		}
	}
	for ( i=0; i<W.SZ; i++ )if ( W[i]==1 )break;
	for ( j=i; i<W.SZ; i++ )printf( "%d ",W[i] );
	for ( i=0; i<j; i++ )printf( "%d ",W[i] );
	printf( "1\n" );
	return 0;
}
