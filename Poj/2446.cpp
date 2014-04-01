#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1040
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
int map[40][40];
int clr[40][40];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
	int l,r,w,i,j,k,x,y;
	while(scanf("%d%d%d",&l,&r,&w)!=EOF){
		::n=l*r;
		int _clk=0;
		map[1][1]=++_clk;
		clr[1][1]=1;
		for(i=1;i<=l;i++)for(j=1;j<=r;j++){
			if(i==1&&j==1)continue;
			map[i][j]=++_clk;
			if(i>1)clr[i][j]=-clr[i-1][j];
			else if(j>1)clr[i][j]=-clr[i][j-1];
			}
		for(i=1;i<=w;i++){
			scanf("%d%d",&y,&x);
			clr[x][y]=0;
			}
		for(i=1;i<=l;i++)for(j=1;j<=r;j++){
			if(clr[i][j]>=0)continue;
			for(k=0;k<4;k++){
				if(clr[i+dx[k]][j+dy[k]]>0)G[ map[i+dx[k]][j+dy[k]] ][ map[i][j] ]=1;
				}
			}
		int flag= Hungrary()*2==l*r-w;
		if(flag)printf("YES\n");
		else printf("NO\n");
		}
	return 0;
	} 
