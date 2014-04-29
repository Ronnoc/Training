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
int a[105][105];
int sum[105][105][105];
int dp[105][105][2];
int dis[105][105][2];
int main() {
	int i,j,l,r,k;
	int n,m,K;
	while ( cin>>n>>m>>K ) {
		for ( i=1; i<=n; i++ )for ( j=1; j<=m; j++ )cin>>a[i][j];
		if ( m==1||n==1 ) {printf( "0\n" ); continue;}
		memset( sum,0,sizeof sum );
		memset( dis,0,sizeof dis );
		for ( i=1; i<=n; i++ ) {
			for ( j=1; j<=m; j++ )sum[i][j][j]=a[i][j];
			for ( l=1; l<=m; l++ )for ( r=l+1; r<=m; r++ )sum[i][l][r]=a[i][r]+sum[i][l][r-1];
		}
		int ans=MOD;
		if ( m>K ) {
			for ( i=1; i<=m; i++ )for ( j=1; j<=m; j++ ) {
					for ( k=1; k<=n; k++ )if ( a[k][i]==a[k][j] )dis[i][j][1]++;
						else dis[i][j][0]++;
				}
			for ( i=1; i<=m; i++ ) {
				for ( j=1; j<=m; j++ ) {
					dp[i][j][0]=min( dp[i][j-1][1]+dis[i][j][1],dp[i][j-1][0]+dis[i][j][0] );
					dp[i][j][1]=min( dp[i][j-1][1]+dis[i][j][0],dp[i][j-1][0]+dis[i][j][1] );
				}
			}
			for ( i=1; i<=m; i++ ) cmin( ans,dp[i][m][0] );
			for ( i=1; i<=m; i++ ) cmin( ans,dp[i][m][1] );
		} else if ( n>K ) {
			for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ ) {
					for ( k=1; k<=m; k++ )if ( a[i][k]==a[j][k] )dis[i][j][1]++;
						else dis[i][j][0]++;
				}
			for ( i=1; i<=n; i++ ) {
				for ( j=1; j<=n; j++ ) {
					dp[i][j][0]=min( dp[i][j-1][1]+dis[i][j][1],dp[i][j-1][0]+dis[i][j][0] );
					dp[i][j][1]=min( dp[i][j-1][1]+dis[i][j][0],dp[i][j-1][0]+dis[i][j][1] );
				}
			}
			for ( i=1; i<=n; i++ ) cmin( ans,dp[i][n][0] );
			for ( i=1; i<=n; i++ ) cmin( ans,dp[i][n][1] );
		}else {
			int pd[22][1<<12];
			int d[22][1<<12];
			memset(d,0,sizeof d);
			for(k=0;k<1<<n;k++){
				int now[33];
				for(i=1;i<=n;i++)now[i]=k>>(i-1)&1;
				for(j=1;j<=m;j++){
					for(i=1;i<=n;i++)if(a[i][j]!=now[i])d[j][k]++;
				}
			}
			for(k=0;k<1<<n;k++)pd[1][k]=d[1][k];
			for(j=2;j<=m;j++)for(k=0;k<1<<n;k++)
				pd[j][k]=d[j][k]+min(pd[j-1][(1<<n)-1-k],pd[j-1][k]);
			for(k=0;k<1<<n;k++)cmin(ans,pd[m][k]);
		}
		if ( ans<=K )printf( "%d\n",ans );
		else printf( "-1\n" );
	}
	return 0;
}
