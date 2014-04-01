#include<stdio.h>
int ok[110]; 
int graph[110][110];
int m,n;
int first=1;
void FS(){
	int sum[110],i,j;
	for(i=1;i<=n;i++){
		sum[i]=0;
		for(j=1;j<=n;j++){
			if(ok[j])continue;
			sum[i]+=graph[j][i];
			}
	//	printf("%d ",sum[i]);
		}//printf("\n");
	int check=0;
	for(i=1;i<=n;i++){
		check+=ok[i];
		if(!ok[i]&&sum[i]==0){
			ok[i]=1;
			if(first)first=0;
			else printf(" ");
			printf("%d",i);
			}
		}
	if(check!=n)FS();
	}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		if(m==0&&n==0)break;
		first=1;
		int i,j;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)graph[i][j]=0;
		for(i=1;i<=n;i++)ok[i]=0;
		for(i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);		//xÔÚyÇ° 
			graph[x][y]=1;
			}
	/*	for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)printf("%d ",graph[i][j]);
			printf("\n");
			}printf("\n");*/
		FS();
		printf("\n");
		}
	return 0;
	}
