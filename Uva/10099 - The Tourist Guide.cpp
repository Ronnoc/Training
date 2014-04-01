#include<stdio.h>
#define INF (int)1e9
int g[110][110];
int max(int a,int b){
	if(a>b)return a;return b;
	}
int min(int a,int b){
	if(a>b)return b;return a;
	}
int main(){
	int n,m;
	int z=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(!n&&!m)break;
		int i,j,k;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)g[i][j]=INF;
		int x,y,v;
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&v);
			g[x][y]=v;
			g[y][x]=v;
			}
		for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			if(g[i][k]!=INF&&g[k][j]!=INF){
				int temp=min(g[i][k],g[k][j]);
				if(g[i][j]==INF)g[i][j]=temp;
				else g[i][j]=max(g[i][j],temp);
				}
			}
	/*	for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)printf("%4d",g[i][j]);
			printf("\n");
			}*/
		scanf("%d%d%d",&x,&y,&v);
		printf("Scenario #%d\n",++z);
		int res=0;
		while(res*g[x][y]<v+res)res++;
		printf("Minimum Number of Trips = %d\n\n",res);
		}
	return 0;
	}
