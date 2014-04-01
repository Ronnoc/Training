#include <cstdio>
long long dp[11][11];
//dp[i][j]=dp[i][j-1]+dp[i-j][j];
int main(){
	int i,j;
	for(i=0;i<=10;i++){
		dp[i][1]=1;
		for(j=2;j<=10;j++){
			dp[i][j]=dp[i][j-1];
			if(i>=j)dp[i][j]+=dp[i-j][j];
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%I64d\n",dp[a][b]);
	}
	return 0;
}
