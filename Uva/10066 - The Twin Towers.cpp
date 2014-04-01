#include<stdio.h>
int dp[110][110];
int max(int a,int b){
	if(a>b)return a;
	return b;
	}
int main(){
	int pa,pb;
	int a[110],b[110];
	int z=0;
	while(scanf("%d%d",&pa,&pb)!=EOF){
		if(pa==0&&pb==0)return 0;
		int i,j;
		for(i=1;i<=pa;i++)scanf("%d",&a[i]);
		for(i=1;i<=pb;i++)scanf("%d",&b[i]);
		for(i=0;i<=pa;i++)dp[i][0]=0;
		for(i=0;i<=pb;i++)dp[0][i]=0;
		for(i=1;i<=pa;i++)for(j=1;j<=pb;j++){
			if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		printf("Twin Towers #%d\n",++z);
		printf("Number of Tiles : %d\n\n",dp[pa][pb]);
		}
	}
