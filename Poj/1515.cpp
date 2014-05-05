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
/*
*TarjanEBCC
*/
const int N=1005;
const int M=500005;
struct edgenode {
	int u,v, next;
} edge[2*M];
int last[N], tot;
int n, m;
int dfn[N], low[N], belong[N], instack[N], nindex, ncnt;
stack<int> sta;

void addedge( int x, int y ) {
	edge[tot].u = x;
	edge[tot].v = y;
	edge[tot].next = last[x];
	last[x] = tot++;
}

void init() {
	tot = 0;
	memset( last, -1, sizeof( last ) );
	int x, y;
	for ( int i = 0; i < m; i++ ) {
		scanf( "%d%d", &x, &y );
		addedge( x, y );
		addedge( y, x );
	}
}

void Tarjan( int u, int from ) {
	dfn[u] = low[u] = nindex++;
	instack[u] = 1;
	sta.push( u );
	int v;
	for ( int j = last[u]; -1 != j; j = edge[j].next ) {
		if ( j == from ) continue;
		v = edge[j].v;
		if ( 0 == dfn[v] ) {
			Tarjan( v, j ^ 1 );
			if ( low[u] > low[v] )
				low[u] = low[v];
		} else if ( instack[v] ) {
			if ( low[u] > dfn[v] )
				low[u] = dfn[v];
		}
	}
	if ( dfn[u] == low[u] ) {
		ncnt++;
		do {
			v = sta.top();
			instack[v] = 0;
			sta.pop();
			belong[v] = ncnt;
		} while ( v != u );
	}
}
set<PII>ANS;
set<PII>::iterator it;
int vis[1005];
void dfs( int u,int fa,int b ) {
//	cout<<u<<" "<<fa<<" "<<b<<":";
//	for ( int j = last[u]; ~j; j = edge[j].next )cout<<edge[j].v<<" ";
//	cout<<endl;
	vis[u]=1;
	for ( int j = last[u]; ~j; j = edge[j].next ) {
		int v = edge[j].v;
		if ( belong[v]!=b )continue;
		if ( vis[v] )
			{if(!ANS.count(MP(v,u)))ANS.insert( MP( u,v ) );}
		else {
			if(!ANS.count(MP(v,u)))ANS.insert( MP( u,v ) );
			dfs( v,u,b );
		}
	}
}
void solve() {
	memset( dfn, 0, sizeof( dfn ) );
	memset( low, 0, sizeof( low ) );
	memset( instack, 0, sizeof( instack ) );
	memset( belong, 0, sizeof( belong ) );
	ncnt = 0;
	nindex = 0;
	int flag = 0,i;
	for ( i = 1; i <= n; i++ )
		if ( 0 == belong[i] ) {
			Tarjan( i, -1 );
			flag++;
		}
	memset( vis,0,sizeof vis );
	ANS.clear();
	for ( i=1; i<=n; i++ )if ( !vis[i] )dfs( i,-1,belong[i] );
//	for ( it=ANS.OP; it!=ANS.ED; ++it )
//		printf( "%d %d ~\n",( *it ).AA,( *it ).BB );
	for ( i=0; i<tot; i++ ) {
		if ( ANS.count( MP( edge[i].u,edge[i].v ) ) );
		else if ( ANS.count( MP( edge[i].v,edge[i].u ) ) );
		else {
			ANS.insert( MP( edge[i].v,edge[i].u ) );
			ANS.insert( MP( edge[i].u,edge[i].v ) );
		}
	}
	for ( it=ANS.OP; it!=ANS.ED; ++it )
		printf( "%d %d\n",( *it ).AA,( *it ).BB );
}
int main() {
	int i,j;
	int CASE=0;
	while ( ~scanf( "%d%d",&n,&m )&&( n&&m ) ) {
		init();
		printf( "%d\n\n",++CASE );
		solve();
		printf( "#\n" );
	}
	return 0;
}
