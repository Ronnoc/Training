#include<stdio.h>
#define INF (int)1e9 
int g[110][110];
int max(int a,int b){
	if(a<b)return b;return a;
	}
void output(int c){
	int i,j;
	for(i=1;i<=c;i++){
		for(j=1;j<=c;j++){
			if(g[i][j]==INF)printf(" INF");
			else printf(" %3d",g[i][j]); 
			}
		printf("\n");
		}
	printf("\n");
	}
int main(){
	int c,s,q;
	int z=0;
	while(scanf("%d%d%d",&c,&s,&q)!=EOF){
		if(!c&&!s&&!q)break;
		if(z)printf("\n");
		int i,j,k;
		for(i=1;i<=c;i++)for(j=1;j<=c;j++)g[i][j]=INF;
		for(i=1;i<=c;i++)g[i][i]=0;
		int x,y,w;
		for(i=1;i<=s;i++){
			scanf("%d%d%d",&x,&y,&w);
			g[x][y]=w;
			g[y][x]=w;
			}
	//	output(c);
		for(k=1;k<=c;k++)for(i=1;i<=c;i++)for(j=1;j<=c;j++){
			if(g[i][k]!=INF&&g[k][j]!=INF){
				int &t=g[i][j];
				int tp=max(g[i][k],g[k][j]);
				if(tp<t)t=tp;
				}
			}
	//	output(c);
		printf("Case #%d\n",++z);
		for(i=1;i<=q;i++){
			scanf("%d%d",&x,&y);
			if(g[x][y]==INF)printf("no path\n");
			else printf("%d\n",g[x][y]);
			}
		}
	return 0;
	}
