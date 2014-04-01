#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 105
int map[N][N];
int dp[N][N][N];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,k,l;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&map[i][j]);
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)
			dp[i][i][j]=dp[i][i][j-1]+map[i][j];
		for(l=1;l<n;l++)for(i=1;i+l<=n;i++){
			int p=i,q=i+l;
			for(j=1;j<=n;j++)dp[p][q][j]=dp[p][q-1][j]+dp[q][q][j];
		}
		for(i=1;i<=n;i++)for(j=i;j<=n;j++){
			int mn=0;
			for(k=1;k<=n;k++){
				ans=max(ans,dp[i][j][k]-mn);
				mn=min(mn,dp[i][j][k]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
