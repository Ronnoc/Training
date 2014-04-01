#include<stdio.h>
#define MAX 100000
int dp[10010];
int main(){
	int i;
	dp[0]=1;
	for(i=1;i<=9999;i++){
		dp[i]=i*dp[i-1];
		while(dp[i]%10==0)dp[i]/=10;
		dp[i]%=MAX;
		}
	int n;
	while(scanf("%d",&n)!=EOF)printf("%5d -> %d\n",n,dp[n]%10);
	return 0;
	}
