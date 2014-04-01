#include<stdio.h>
int dp[1010][40];	//dp[x][y]表示前x见物品用空间y的权值 
int val[1010],w[1010];
int max(int a,int b){
	if(a>b)return a;
	return b;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int i,n,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d%d",&val[i],&w[i]);
		for(i=0;i<=30;i++)dp[0][i]=0;
		for(i=1;i<=n;i++){
			for(j=0;j<w[i];j++)dp[i][j]=dp[i-1][j];
			for(j=w[i];j<=30;j++)dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+val[i]);
			}
		int m;
		int res=0;
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			res+=dp[n][x];
			}
		printf("%d\n",res);
		}
	return 0;
	}
