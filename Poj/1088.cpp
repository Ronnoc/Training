#include<stdio.h>
#include<algorithm>
int h[105][105];
int dp[105][105];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
int can(int x,int y){
	if(x<0||y<0)return 0;
	if(x>n||y>m)return 0;
	return 1;
	}
int DAG(int x,int y){
	if(dp[x][y]!=-1)return dp[x][y];
	dp[x][y]=1;
	int i;
	for(i=0;i<4;i++)if(can(x+dx[i],y+dy[i])&&h[x+dx[i]][y+dy[i]]<h[x][y]){
		dp[x][y]=std::max(dp[x][y],1+DAG(x+dx[i],y+dy[i]));
		}
	return dp[x][y];
	}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++){
			scanf("%d",&h[i][j]);
			dp[i][j]=-1;
			}
		int res=0;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++){
			res=std::max(res,DAG(i,j)); 
			}
		printf("%d\n",res);
		}
	return 0;
	}
