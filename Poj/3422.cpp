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
const int N = 2*55*55;
const int M = 8*N;
struct edgenode {
	int u, v, next, c, w;
	edgenode( int u,int v,int next,int c,int w ):u( u ),v( v ),next( next ),c( c ),w( w ) {}
	edgenode() {}
} edge[2*M];
int tot, last[N];
int dist[N], pre[N];
bool visit[N];
int n, m, S, T, all;
void addedge( int u, int v, int c, int w ) {
	edge[tot].u = u; edge[tot].v = v; edge[tot].c = c; edge[tot].w = w; edge[tot].next = last[u]; last[u] = tot++;
	edge[tot].u = v; edge[tot].v = u; edge[tot].c = 0; edge[tot].w = -w; edge[tot].next = last[v]; last[v] = tot++;
}
bool spfa( int s, int t, int n ) {
	for(int i=0;i<=n+13;i++)dist[i]=MOD;
	memset( visit, 0, sizeof( visit[0] ) * ( n + 13 ) );
	memset( pre, -1, sizeof( pre[0] ) * ( n + 13 ) );
	queue<int> q;
	while ( !q.empty() ) q.pop();
	q.push( s );
	visit[s] = 1;
	dist[s] = 0;
	pre[s] = -1;
	while ( !q.empty() ) {
		int u = q.front();
		visit[u] =false;
		q.pop();
		for ( int j = last[u]; j != -1; j = edge[j].next )
			if ( edge[j].c > 0 && dist[u] + edge[j].w < dist[edge[j].v] ) {
				dist[edge[j].v] = dist[u] + edge[j].w;
				pre[edge[j].v] = j;
				if ( !visit[edge[j].v] ) {
					q.push( edge[j].v );
					visit[edge[j].v] = true;
				}
			}
	}
	if ( dist[t] == MOD ) return false; /*HINT注意INF和dist[t]的初始值的关系*/
	else return true;
}
int ChangeFlow( int t ) {
	int det = INF, u = t;
	while ( ~pre[u] ) {
		u = pre[u];
		det = min( det, edge[u].c );
		u = edge[u].u;
	}
	u = t;
	while ( ~pre[u] ) {
		u = pre[u];
		edge[u].c -= det;
		edge[u ^ 1].c += det;
		u = edge[u].u;
	}
	return det;
}
int mincost, maxflow;
void MinCostFlow( int s, int t, int n ) {
	mincost = maxflow = 0;
	while ( spfa( s, t, n ) ) {
		int det = ChangeFlow( t );
		mincost += det * dist[t];
		maxflow += det;
	}
}
int w[55][55];
int p[55][55];
int q[55][55];
int main() {
	int i,j;
	int n,k;
	while ( ~scanf( "%d%d",&n,&k ) ) {
		for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )
				scanf( "%d",&w[i][j] );
		tot=0;
		memset( last,-1,sizeof last );
		int nid=0;
		S=nid++;
		T=nid++;
		for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )p[i][j]=nid++;
		for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )q[i][j]=nid++;
		for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )addedge( p[i][j],q[i][j],1,-w[i][j] );
		for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )addedge( p[i][j],q[i][j],k-1,0 );
		for ( i=1; i<=n; i++ )for ( j=1; j<n; j++ )addedge( q[i][j],p[i][j+1],k,0 );
		for ( i=1; i<n; i++ )for ( j=1; j<=n; j++ )addedge( q[i][j],p[i+1][j],k,0 );
		addedge( S,p[1][1],k,0 );
		addedge( q[n][n],T,k,0 );
		MinCostFlow(S,T,nid+1);
		printf("%d\n",-mincost);
	}
	return 0;
}
