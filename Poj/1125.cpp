#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 110
#define INF (int)1e9
int G[N][N];
int res[N];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int ii,i,j,k,m,x,y;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)G[i][j]=(i==j)?0:INF;
		for(ii=1;ii<=n;ii++){
			scanf("%d",&m);
			for(i=1;i<=m;i++){
				scanf("%d%d",&x,&y);
				G[ii][x]=min(G[ii][x],y);
				}
			} 
		for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
			G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
		int flag=1;
		for(i=1;i<=n;i++){
			res[i]=-1;
			for(j=1;j<=n;j++)res[i]=max(res[i],G[i][j]);
			if(res[i]!=INF)flag=0;
			}
	//	if(flag){printf("disjoint\n");continue;}
		int ans=res[1],pans=1;
		for(i=2;i<=n;i++)if(res[i]<ans)ans=res[i],pans=i;
		printf("%d %d\n",pans,ans);
		}
	return 0;
	}
