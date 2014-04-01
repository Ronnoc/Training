//poj 1325
#include<stdio.h>
#include<string.h>
using namespace std;
#define N 1010
int G[N][N],n;
bool vis[N];
int match[N];
bool dfs(int x){
	for(int i=1;i<=n;i++){
		if(!G[x][i])continue;
		if(!vis[i]){
			vis[i]=1;
			int &tp=match[i];
			if(tp==-1||dfs(tp)){
				match[i]=x;
				match[x]=i;
				return 1;
				}
			}
		}
	return 0;
	}
int greedy_match(){
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		if(!G[i][j])continue;
		if(match[i]!=-1)continue;
		if(match[j]==-1){
			match[i]=j;
			match[j]=i;
			ans++;
			break;
			}
		} 
	return ans;
	}
int Hungrary(){
	memset(match,-1,sizeof(match));
	int res=greedy_match();
	for(int i=1;i<=n;i++){
		if(match[i]!=-1)continue;
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		if(dfs(i))res++;
		}
	return res;
	}
int main(){
	int p,q,r,i,j,k,x,y,T=500;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p);
		n*=2;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)G[i][j]=0;
		for(i=1;i<=p;i++){
			scanf("%d%d",&x,&y);
			G[x][y+n/2]=1;
			} 
		int res=Hungrary();
	//	printf("H:%d\n",res);
		printf("%d\n",n/2-res);
		}
	return 0;
	}
