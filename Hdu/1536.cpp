#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int sg[10010];
int s[110],k;
int pre( int x ) {
	if ( sg[x]!=-1 )
		return sg[x];
	int nim[110];
	memset(nim,-1,sizeof(nim));
	int i;
	for ( i=1; i<=k; i++ )
		if ( x>=s[i] )
			nim[ pre( x-s[i] ) ]=1;
	for(i=0;i<=k+1;i++)if(nim[i]==-1)return sg[x]=i;
	}
int main() {
	while ( scanf( "%d",&k )!=EOF&&k ) {
		int i;
		for ( i=1; i<=k; i++ )
			scanf( "%d",&s[i] );
		memset( sg,-1,sizeof( sg ) );
		int t;
		scanf( "%d",&t );
		while ( t-- ) {
			int m;
			scanf( "%d",&m );
			int tp=0,x;
			for ( i=1; i<=m; i++ ) {
				scanf( "%d",&x );
				tp=tp xor pre( x );
				}
			if ( tp )
				printf( "W" );
			else
				printf( "L" );
			}
		printf( "\n" );
		}
	return 0;
	}
