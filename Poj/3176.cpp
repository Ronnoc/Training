#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[444][444],mp[444][444];
int main(){
	int n,j,i;
	while(scanf("%d",&n)!=EOF){
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)for(j=1;j<=i;j++)
			scanf("%d",&mp[i][j]);
		int ans=0;
		for(i=1;i<=n;i++)for(j=1;j<=i;j++){
			dp[i][j]=mp[i][j];
			if(i>1)dp[i][j]=mp[i][j]+dp[i-1][j-1];
			if(j<i)dp[i][j]=max(dp[i][j],mp[i][j]+dp[i-1][j]);
			ans=max(ans,dp[i][j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
