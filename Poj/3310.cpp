#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define cmin(x,y) x=min(x,y)
#define PB push_back
#define MP make_pair
#define AA first
#define SZ size()
#define BB second
int n,m;
vector<int>G[111];
int fa[111];
int getfa( int u ) {
	return fa[u]==u?u:fa[u]=getfa( fa[u] );
}
int vis[111],ff[111];
void dfs( int u,int f=-1,int h=1 ) {
	vis[u]=h;
	ff[u]=f;
	for ( int i=0; i<G[u].SZ; i++ ) {
		int v=G[u][i];
		if ( v==f )continue;
		if ( !vis[v] )dfs( v,u,h+1 );
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int CA=0;
	while ( ~scanf( "%d",&n )&&n ) {
		CA++;
		scanf( "%d",&m );
		for ( i=1; i<=n; i++ )G[i].clear(),fa[i]=i;
		int fail=0,tot=n;
		while ( m-- ) {
			int u,v;
			scanf( "%d%d",&u,&v );
			G[u].PB( v );
			G[v].PB( u );
			int fu=getfa( u );
			int fv=getfa( v );
			if ( fu==fv )fail=1;
			else fa[fu]=fv,tot--;
		}
		if ( tot!=1 )fail=1;
		if ( !fail ) {
			memset( vis,0,sizeof vis );
			dfs( 1 );
			int mxrank=-1,id;
			for ( i=1; i<=n; i++ )if ( vis[i]>mxrank )mxrank=vis[i],id=i;
			memset( vis,0,sizeof vis );
			dfs( id );
			mxrank=-1;
			for ( i=1; i<=n; i++ )if ( vis[i]>mxrank )mxrank=vis[i],id=i;
			for ( i=1; i<=n; i++ )fa[i]=i;
			vector<int>L;
			while ( id!=-1 ) {
				L.PB( id );
				id=ff[id];
			}
			int root=L[0];
			for ( i=1; i<L.SZ; i++ ) {
				int u=L[i-1];
				int v=L[i];
				int fu=getfa( u );
				int fv=getfa( v );
				fa[fu]=fv;
			}
			root=getfa( root );
			for ( i=1; i<=n; i++ )if ( getfa( i )!=root ) {
					int flag=0;
					for ( j=0; j<G[i].SZ; j++ ) {
						int v=G[i][j];
						int fv=getfa( v );
						if ( fv==root )flag=1;
					}
					if ( !flag )fail=1;
				}
		}
		if ( fail )printf( "Graph %d is not a caterpillar.\n",CA );
		else printf( "Graph %d is a caterpillar.\n",CA );
	}
	return 0;
}
