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
//LCA
const int N=11111;
const int M=N<<2;
const int STEP=20;
struct edgenode {
	int u, v, len, next;
} edge[M];
int tot, last[N];
int depth[N], fa[STEP][N];
int n, m;
void addedge( int x, int y ) {
	edge[tot].u = x;
	edge[tot].v = y;
	edge[tot].next = last[x];
	last[x] = tot++;
}
void init() {
	memset( last, -1, sizeof( last ) );
	memset( fa, 0 , sizeof( fa ) );
	memset( depth, -1, sizeof( depth ) );
	memset( fa, 0 , sizeof( fa ) );
	tot = 0;
}
void dfs( int u ) {
	int v;
	for ( int j = last[u]; -1 != j; j = edge[j].next ) {
		v = edge[j].v;
		if ( fa[0][v] == 0 ) {
			fa[0][v] = u;
			depth[v] = depth[u] + 1;
			dfs( v );
		}
	}
}
int getLCA( int x, int y ) {
	int dif = abs( depth[x] - depth[y] );
	if ( depth[x] < depth[y] )
		swap( x, y );
	for ( int i = STEP - 1; i >= 0; i-- )
		if ( ( 1 << i ) & dif ) {
			dif -= ( 1 << i );
			x = fa[i][x];
		}
	for ( int i = STEP - 1; i >= 0; i-- )
		if ( fa[i][x] != fa[i][y] ) {
			x = fa[i][x];
			y = fa[i][y];
		}
	if ( x == y ) return x;
	else return fa[0][x];
}
void solve() {
	int i,u,v,n;
	scanf( "%d",&n );
	for ( i=1; i<n; i++ ) {
		scanf( "d",&u,&v );
		fa[0][v]=u;
		addedge( u,v );
		addedge( v,u );
	}
	int root=1;
	fa[0][root] = root;
	depth[root] = 0;
	dfs( root );
	for ( int i = 1; i < STEP; i++ )
		for ( int j = 1; j <= n; j++ )
			fa[i][j] = fa[i-1][fa[i-1][j]];
	scanf( "d",&u,&v );
	printf( "%d\n",getLCA( u,v ) );
}
int main() {
	int i,j;
	int u,v,T;
	scanf( "%d",&T );
	while ( T-- ) {
		init();
		solve();
	}
	return 0;
}
