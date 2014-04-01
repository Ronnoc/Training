#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int map[110][110],dp[110][110];
int main()
{
	int OFFL=0;
#ifndef ONLINE_JUDGE
	OFFL=1;
#endif
	int n;
	while ( scanf( "%d",&n )!=EOF )
	{
		int i,j;
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=i; j++ )
				scanf( "%d",&map[i][j] );
		memset( dp,0,sizeof( dp ) );
		for ( i=1; i<=n; i++ )
			for ( j=1; j<=i; j++ )
				dp[i][j]=max( dp[i-1][j-1],dp[i-1][j] )+map[i][j];
	int ans=0;
	for(i=1;i<=n;i++)ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
	}
	return 0;
}
