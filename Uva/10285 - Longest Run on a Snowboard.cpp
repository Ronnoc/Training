#include<stdio.h>
int dp[110][110],map[110][110];
int max(int a,int b){
	if(a>b)return a;return b;
	}
int dag(int x,int y){
	if(dp[x][y]!=-1)return dp[x][y];
	dp[x][y]=1;
	int &h=dp[x][y];
	if(map[x][y]>map[x+1][y])h=max(h,dag(x+1,y)+1);
	if(map[x][y]>map[x-1][y])h=max(h,dag(x-1,y)+1);
	if(map[x][y]>map[x][y+1])h=max(h,dag(x,y+1)+1);
	if(map[x][y]>map[x][y-1])h=max(h,dag(x,y-1)+1);
	return h;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char name[110];
		scanf("%s",name);
		int m,n;
		scanf("%d%d",&m,&n);
		int i,j;
		for(i=1;i<=m;i++)for(j=1;j<=n;j++)scanf("%d",&map[i][j]);
		for(i=1;i<=m;i++)for(j=1;j<=n;j++)dp[i][j]=-1;
		int res=0;
		for(i=1;i<=m;i++)for(j=1;j<=n;j++)res=max(res,dag(i,j));
		printf("%s: %d\n",name,res);
		}
	return 0;
	}
