#include<stdio.h>
#include<stdlib.h>
int dp[25][25][25];
int w(int x,int y,int z){
//	printf("w %d %d %d\n",x,y,z);
//	system("pause");
	if(x<0)return w(0,y,z);
	if(y<0)return w(x,0,z);
	if(z<0)return w(x,y,0);
	if(x<=0||y<=0||z<=0){
		dp[x][y][z]=1;
		return 1;
		}
	if(x>20||y>20||z>20)return w(20,20,20);
	if(dp[x][y][z]!=-1)return dp[x][y][z];
	int a=x,b=y,c=z;
	if(a<b&&b<c)dp[a][b][c]=w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else dp[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1) ;
	return dp[a][b][c];
	}
int main(){
	int i,j,k;
	for(i=0;i<=20;i++)for(j=0;j<=20;j++)for(k=0;k<=20;k++)dp[i][j][k]=-1;
	for(i=0;i<=20;i++)for(j=0;j<=20;j++){
		dp[i][j][0]=1;
		dp[i][0][j]=1;
		dp[0][i][j]=1;
		}
	int a,b,c;
	w(20,20,20);
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		if(a==-1&&b==-1&&c==-1)break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
		}
	return 0;
	}
