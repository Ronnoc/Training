#include<stdio.h>
char map[110][110];
int dp[110][110];
int flag[110][110];
int m,n;
int colour(int x,int y,int k){
	if(x<0||y<0||x==m||y==n)return 0;
	if(flag[x][y])return 0;
	int i,j;
//	printf("ÈëÕ»colour(%d,%d,%d):\n",x+1,y+1,k);
/*		for(i=0;i<m;i++){
			for(j=0;j<n;j++)printf("%2d ",dp[i][j]);
			printf("\n");
			}	*/
	if(map[x][y]=='@'){
	//	printf("dp[%d][%d]=%d\n",x+1,y+1,k);
		dp[x][y]=k;
		flag[x][y]=1;
		}
	else return 0;
	colour(x-1,y-1,k);
	colour(x-1,y,k);
	colour(x-1,y+1,k);
	colour(x,y-1,k);
	colour(x,y,k);
	colour(x,y+1,k);
	colour(x+1,y-1,k);
	colour(x+1,y,k);
	colour(x+1,y+1,k);
//	printf("³ö!\n\n");	
	}
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		if(m==0||n==0)break;
		getchar();
		int i,j;
		for(i=0;i<m;i++)gets(map[i]);
		for(i=0;i<m;i++)for(j=0;j<n;j++)dp[i][j]=0;
		for(i=0;i<m;i++)for(j=0;j<n;j++)flag[i][j]=0;
		int k=0;
		for(i=0;i<m;i++)for(j=0;j<n;j++){
			if(!flag[i][j]&&map[i][j]=='@'){
				++k;
				colour(i,j,k);
				}
			}
/*		for(i=0;i<m;i++){
			for(j=0;j<n;j++)printf("%4d",dp[i][j]);
			printf("\n");
			}*/
		printf("%d\n",k);
		}
	return 0;
	}
