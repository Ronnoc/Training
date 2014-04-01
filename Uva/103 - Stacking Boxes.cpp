#include<stdio.h>
#include<vector>
#include<stdlib.h>
int cmp(const void *a,const void *b){
	int *p=(int *)a;
	int *q=(int *)b;
	return *p-*q; 
	}
int q[40][12];
int max(int a,int b){
	if(a>b)return a;return b;
	}
int dp[40];
int m,n;
int fit(int a,int b){
	int i;
	int flag=1;
	for(i=0;i<n;i++)if(q[a][i]<=q[b][i])flag=0;
	return flag;
	}
int dag(int x){
	if(dp[x]>-1)return dp[x];
	dp[x]=0;
	int i;
	for(i=1;i<=m;i++){
		if(i==x)continue;
		if(fit(x,i))dp[x]=max(dp[x],dag(i)+1);
		}
	return dp[x];
	}
void back(int p){
	int x=dp[p],i;
	for(i=1;i<=m;i++){
		if(i==p)continue;
		if(fit(p,i)&&dp[i]==x-1){
			back(i);
			printf("%d ",i);
			return;
			}
		}
	}
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		int i,j;
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				int x;
				scanf("%d",&x);
				q[i][j-1]=x;
				}
			qsort(&q[i][0],n,sizeof(int),cmp);
			}
		for(i=1;i<=m;i++)dp[i]=-1;
		int res=0;
		for(i=1;i<=m;i++)res=max(res,dag(i));
		printf("%d\n",res+1);
		int p;
		for(i=1;i<=m;i++)if(dp[i]==res)p=i;
		back(p);
		printf("%d\n",p);
		}
	return 0;
	}
