#include<stdio.h>
#define INF (int)1e9
int g[30][30];
int min(int a,int b){
	if(a>b)return b;return a;
	}
int main(){
	int k;
	int z=0;
	while(scanf("%d",&k)!=EOF){
		int i,j;
		for(i=1;i<=20;i++)for(j=1;j<=20;j++)g[i][j]=INF;
		for(i=1;i<=20;i++)g[i][i]=0;
		int x,y;
		for(i=1;i<=k;i++){
			scanf("%d",&x);
			g[1][x]=1;g[x][1]=1;
			}
		for(i=2;i<=19;i++){
			scanf("%d",&k);
			for(j=1;j<=k;j++){
				scanf("%d",&x);
				g[i][x]=1;
				g[x][i]=1;
				}
			}
		for(k=1;k<=20;k++)for(i=1;i<=20;i++)for(j=1;j<=20;j++){
			int &t=g[i][j];
			t=min(t,g[i][k]+g[k][j]);
			}
		scanf("%d",&k);
		printf("Test Set #%d\n",++z);
		for(i=1;i<=k;i++){
			scanf("%d%d",&x,&y);
			printf("%2d to %2d: %d\n",x,y,g[x][y]);
			}
		printf("\n");
		}
	return 0;	
	}
