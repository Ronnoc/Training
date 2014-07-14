/*
ID: kybconn1
PROG: numtri
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int dp[1005][1005];
#define cmax(x,y) x=max(x,y)
int main() {
	freopen( "numtri.in", "r", stdin );
	freopen( "numtri.out", "w", stdout );
	int i,j,n;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=1; i<=n; i++ )for ( j=1; j<=i; j++ )scanf( "%d",&a[i][j] );
		memset( dp,0,sizeof dp );
		int ans=0;
		for ( i=1; i<=n; i++ ) {
			dp[i][1]=dp[i-1][1]+a[i][1];
			for ( j=2; j<i; j++ )
				dp[i][j]=a[i][j]+max( dp[i-1][j-1],dp[i-1][j] );
			dp[i][i]=dp[i-1][i-1]+a[i][i];
			for ( j=1; j<=n; j++ )cmax( ans,dp[i][j] );
		}
		cout<<ans<<endl;
	}
	return 0;
}
