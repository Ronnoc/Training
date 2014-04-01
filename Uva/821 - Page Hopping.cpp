#include<stdio.h>
#define INF (int)1e9
int g[110][110];
int should[110];
int max(int a,int b){
	if(a>b)return a;return b;
	}
int min(int a,int b){
	if(a<b)return a;return b;
	}
int main(){
	int x,y;
	int z=0;
	while(scanf("%d%d",&x,&y)!=EOF){
		if(!x&&!y)break;
		int i,j;
		for(i=1;i<=100;i++)for(j=1;j<=100;j++)g[i][j]=INF;
		for(i=1;i<=100;i++)g[i][i]=0;
		for(i=1;i<=100;i++)should[i]=0;
		g[x][y]=1;
		int mm=1;
		should[x]=1;
		should[y]=1;
		mm=max(mm,x);mm=max(mm,y);
		while(scanf("%d%d",&x,&y)!=EOF){
			if(!x&&!y)break;
			g[x][y]=1;
			should[x]=1;
			should[y]=1;
			mm=max(mm,x);mm=max(mm,y);
			}
		int k;
		for(k=1;k<=mm;k++)for(i=1;i<=mm;i++)for(j=1;j<=mm;j++){
			g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		double sum=0;
		int many=0;
		for(i=1;i<=mm;i++)if(should[i])many++;
		many*=many-1;
		for(i=1;i<=mm;i++)if(should[i])for(j=1;j<=mm;j++){
			if(should[j])sum+=g[i][j];
			}
		sum/=many;
		printf("Case %d: average length between pages = %.3lf clicks\n",++z,sum);
		}
	return 0;
	}
