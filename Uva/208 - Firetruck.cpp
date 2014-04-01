#include<stdio.h>
int graph[25][25];
int cho[25];
int aim;
int max=0;
int res=0;
int dist[25][25];
bool come[25];
bool check(int t){
	if(dist[cho[t]][aim]>=100)return 0;
	int i;
	for(i=1;i<t;i++)if(cho[i]==cho[t])return 0;
	return 1;
	}
void op(int t){
	int i;
	if(cho[t-1]==aim){
		res++;
		int fi=1;
		for(i=1;i<t;i++){
			if(fi)fi=0;
			else printf(" ");
			printf("%d",cho[i]);
			}
		printf("\n");
		}
	else {
		for(i=1;i<=max;i++){
			if(come[i]&&graph[cho[t-1]][i]){
				cho[t]=i;
				if(check(t))op(t+1);
				}
			}
		}
	}
int main(){
	int k=0;
	while(scanf("%d",&aim)!=EOF){
		int p,q;
		max=0;
		res=0;
		int i,j;
		for(i=1;i<=21;i++)for(j=1;j<=21;j++){
			graph[i][j]=0;
			dist[i][j]=1000;
			}
		for(i=1;i<=21;i++)come[i]=0;
		while(scanf("%d%d",&p,&q)){
			if(p==0&&q==0)break;
			graph[p][q]=1; 
			graph[q][p]=1;
			if(p>max)max=p;
			if(q>max)max=q;
			dist[p][q]=1;
			dist[q][p]=1;
			come[p]=1;
			come[q]=1;
			}
		int l;
		for(l=1;l<=max;l++)for(i=1;i<=max;i++)for(j=1;j<=max;j++){
			if(dist[i][l]+dist[l][j]<dist[i][j])dist[i][j]=dist[i][l]+dist[l][j];
			}
//		for(i=1;i<=max;i++){for(j=1;j<=max;j++){printf("%4d ",dist[i][j]);}printf("\n");}
		++k;
		printf("CASE %d:\n",k);
		cho[1]=1;
		op(2);
		printf("There are %d routes from the firestation to streetcorner %d.\n",res,aim);
		}
	return 0;
	}
