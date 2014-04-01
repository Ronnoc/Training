#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dp[205][25][1010];		//dp@i~j~k 前i个选j个差值是500+∑d-∑p的最大值
int main()
{
	int d[202],p[202];
	int JURY=0;
	int n,m;
	while ( scanf( "%d%d",&n,&m )!=EOF&&( m||n ) )
	{
		int i,j,k;
		for ( i=1; i<=n; i++ )
			scanf( "%d%d",&d[i],&p[i] );
		for ( i=1; i<=n; i++ )
			d[i]++,p[i]++;
		for(i=0;i<=n;i++)for(j=0;j<=m;j++)for(k=0;k<=1000;k++)dp[i][j][k]=-1;
		dp[0][0][500]=0;
		for ( i=0; i<n; i++ )
			for ( j=0; j<=m; j++ )
				for ( k=0; k<=1000; k++ )
				{
					if ( dp[i][j][k]==-1 )
						continue;
					dp[i+1][j][k]=max( dp[i+1][j][k],dp[i][j][k] );
					int to=k+d[i+1]-p[i+1];
					if ( to>=0&&to<=1000&&j<m )
						dp[i+1][j+1][to]=max( dp[i+1][j+1][to],dp[i][j][k]+d[i+1]+p[i+1] );
				}
//		for ( i=0; i<=n; i++ )
//			for ( j=0; j<=m; j++ )
//				for ( k=0; k<=1000; k++ ){
//					if(dp[i][j][k]!=-1)
//						printf("(%d,%d,%d):=%d\n",i,j,k,dp[i][j][k]-2*j);
//				}
		int t;		
		for ( i=0; i<=500; i++ )
		{
			t=max( dp[n][m][500+i],dp[n][m][500-i] );
			if ( t!=-1 )
				break;
		}
		int bb= ( t==dp[n][m][500+i] )?500+i:500-i;
		vector<int>L;
		int ii=n,jj=m;
		while ( jj&&ii )
		{
			if ( dp[ii-1][jj-1][bb-d[ii]+p[ii]]!=-1&&dp[ii-1][jj-1][bb-d[ii]+p[ii]]+d[ii]+p[ii]==dp[ii][jj][bb] )
			{
//				printf("(%d,%d,%d)<--",ii,jj,bb);
				jj--;
				bb=bb-d[ii]+p[ii];
				L.push_back( ii );
			}
			ii--;
		}
		int sump=0,sumd=0;
		sort( L.begin(),L.end() );
		printf( "Jury #%d\n",++JURY );
		for ( i=0; i<L.size(); i++ )
			sump+=p[L[i]]-1,sumd+=d[L[i]]-1;
		printf( "Best jury has value %d for prosecution and value %d for defence:\n",sumd,sump );
		for ( i=0; i<L.size(); i++ )
			printf( " %d",L[i] );
		printf( "\n\n" );
	}
	return 0;
}
