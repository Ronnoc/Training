/*
ID: kybconn1
PROG: milk3
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int vis[22][22][22];
int a,b,c;
int ans[22];
bool can( int p,int a,int q,int b,int &L,int &R ) {
	int t=min( p,b-q );
	if ( !t )return 0;
	L=p-t,R=q+t;
	return 1;
}
void dfs( int p,int q,int r ) {
	if ( p==0 )ans[r]=1;
	if ( vis[p][q][r] )return;
	vis[p][q][r]=1;
	int L,R;
	if ( can( p,a,q,b,L,R ) )dfs( L,R,r );
	if ( can( p,a,r,c,L,R ) )dfs( L,q,R );
	if ( can( q,b,p,a,L,R ) )dfs( R,L,r );
	if ( can( q,b,r,c,L,R ) )dfs( p,L,R );
	if ( can( r,c,p,a,L,R ) )dfs( R,q,L );
	if ( can( r,c,q,b,L,R ) )dfs( p,R,L );
}
int main() {
	freopen( "milk3.in", "r", stdin );
	freopen( "milk3.out", "w", stdout );
	while ( cin>>a>>b>>c ) {
		memset( vis,0,sizeof vis );
		memset( ans,0,sizeof ans );
		dfs( 0,0,c );
		int fi=1;
		for ( int i=0; i<=c; i++ )if ( ans[i] ) {
				if ( fi )fi=0;
				else printf( " " );
				printf( "%d",i );
			}
		printf( "\n" );
	}
	return 0;
}
