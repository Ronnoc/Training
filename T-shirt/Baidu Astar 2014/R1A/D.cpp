#pragma comment(linker, "/STACK:512000000,512000000")
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
int v[100005],w[100005];
int vis[100005];
int tid[100005];
int C[100005];
int dp[100005][2];
vector<int>G[100005];
vector<int>L;
int root;
void dfs( int u,int fa ) {
	L.PB( u );
	vis[u]=1;
	int i;
	for ( i=0; i<G[u].SZ; i++ ) {
		int v=G[u][i];
		if ( v==fa )continue;
		if ( vis[v] ) {root=v; continue;}
		dfs( v,u );
	}
}
void dfsdp( int u,int fa ) {
	C[tid[u]]=1;
	int i;
	dp[u][1]=w[u];
	dp[u][0]=0;
	for ( i=0; i<G[u].SZ; i++ ) {
		int v=G[u][i];
		if ( v==fa )continue;
		if ( C[ tid[v] ] )continue;
		dfsdp( v,u );
		dp[u][1]+=dp[v][0];
		dp[u][0]+=max( dp[v][0],dp[v][1] );
	}
}
int solve0( int rt ) {
	int i,j;
	for ( i=0; i<L.SZ; i++ )tid[L[i]]=i;
	for ( i=0; i<L.SZ; i++ )C[i]=0;
	int ret=w[rt];
	C[tid[rt]]=1;
	for ( i=0; i<G[rt].SZ; i++ ) {
		j=G[rt][i];
		C[tid[j]]=1;
	}
	for ( i=0; i<L.SZ; i++ ) {
		if ( !C[i] ) {
			dfsdp( L[i],-1 );
			ret+=max( dp[L[i]][0],dp[L[i]][1] );
		}
	}
	return ret;
}
int solve1( int rt ) {
	int i,j;
	for ( i=0; i<L.SZ; i++ )tid[L[i]]=i;
	for ( i=0; i<L.SZ; i++ )C[i]=0;
	int ret=0;
	C[tid[rt]]=1;
	for ( i=0; i<L.SZ; i++ ) {
		if ( !C[i] ) {
			dfsdp( L[i],-1 );
			ret+=max( dp[L[i]][0],dp[L[i]][1] );
		}
	}
	return ret;
}
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		printf( "Case #%d:\n",CASE );
		int n;
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ )scanf( "%d",&v[i] );
		for ( i=1; i<=n; i++ )scanf( "%d",&w[i] );
		for ( i=1; i<=n; i++ )G[i].clear();
		for ( i=1; i<=n; i++ )G[i].PB( v[i] );
		for ( i=1; i<=n; i++ )G[v[i]].PB( i );
		memset( vis,0,sizeof vis );
		memset( dp,0,sizeof dp );
		int ans=0;
		for ( i=1; i<=n; i++ )if ( !vis[i] ) {
				L.clear();
				dfs( i,-1 );
				int s0=solve0( root );
				int s1=solve1( root );
				ans+=max( s0,s1 );
			}
		printf( "%d\n",ans );
	}
	return 0;
}
