#include<stdio.h>
bool graph[110][110];	//清零 
int n,m;
bool opt[110];	
int result=0;	//清零 
bool mem[110]; //清零 
bool check(int t){
//	printf("入栈check(%d)\n",t); 
	if(opt[t]==0)return 1;
	int i;
//	int sum=0;
//	for(i=1;i<=t;i++)sum+=opt[i];//printf("opt[%d]=%d ",i,opt[i]);}printf("\n");
//	sum+=n-t;
//	if(sum<result)return 0;
	for(i=1;i<=n;i++){
		if(i==t)continue;
		if(graph[i][t]&&opt[i]&&opt[t])return 0;
		}
//	printf("return 1;\n");
	return 1;
	}
void op(int t){
	int i;
	if(t>n){
		int sum=0;
		for(i=1;i<=n;i++)sum+=opt[i];//printf("%2d",opt[i]);}printf("\n");
		if(sum>result){
			result=sum;
			for(i=1;i<=n;i++)mem[i]=opt[i];
			} 
		}
	else {
		for(i=1;i>=0;i--){
			opt[t]=i;
			if(check(t))op(t+1);
			}
		}
	}
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		scanf("%d%d",&n,&m);
		int i,j;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)graph[i][j]=0;
		for(i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			graph[u][v]=1;
			graph[v][u]=1;
			}
		result=0;
		op(1);
		int fi=1;
		printf("%d\n",result);
		for(i=1;i<=n;i++){
			if(mem[i]){
				if(fi)fi=0;
				else printf(" ");
				printf("%d",i);
				}
			}
		printf("\n");
		}
	return 0;
	}
