#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define cmin(x,y) x=min(x,y)
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
int G[15][15];
int dp[1<<12][12];
int vis[1<<12][12];
int n;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	while ( ~scanf( "%d",&n )&&n ) {
		for ( i=0; i<=n; i++ )for ( j=0; j<=n; j++ )
				scanf( "%d",&G[i][j] );
		for ( k=0; k<=n; k++ )for ( i=0; i<=n; i++ )for ( j=0; j<=n; j++ )
					cmin( G[i][j],G[i][k]+G[k][j] );
		memset( dp,-1,sizeof dp );
		memset( vis,0,sizeof vis );
		dp[0][0]=0;
		queue<pair<int,int> >Q;
		Q.push( MP( 0,0 ) );
		while ( !Q.empty() ) {
			i=Q.front().AA;
			j=Q.front().BB;
			Q.pop();
			for ( k=0; k<=n; k++ ) {
				int to=i;
				if ( k>0 )to|=1<<( k-1 );
				if ( dp[to][k]==-1 || dp[to][k]>dp[i][j]+G[j][k] )
					dp[to][k]=dp[i][j]+G[j][k],Q.push( MP( to,k ) );
			}
		}
		printf( "%d\n",dp[( 1<<n )-1][0] );
	}
	return 0;
}
