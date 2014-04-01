#include<stdio.h>
#include<string.h>
#include<vector>
#define INF (int)1e9
std::vector<int>g[1010];
char s[1010];
int dp[1010];
int isp[1010][1010];
int is_pal(int x,int y){
	int &tp=isp[x][y];
	if(tp!=-1)return tp;
	if(x>=y)return tp=1;
	if(s[x]==s[y])return tp=is_pal(x+1,y-1);
	else return tp=0;
	}
int min(int a,int b){
	if(a>b)return b;return a;
	}
int dag(int x) {
	if(x==strlen(s))return 0;
	if(dp[x])return dp[x];
	int i;
	int &res=dp[x];
	res=INF;
	for(i=0;i<g[x].size();i++){
		res=min(res,1+dag(g[x][i]+1));
		}
	return res;
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s); 
		int i,j,k;
		int len=strlen(s);
		for(i=0;i<len;i++)g[i].clear();
		for(i=0;i<len;i++)for(j=0;j<len;j++)isp[i][j]=-1;
		for(i=0;i<len;i++)for(j=i;j<len;j++)if(is_pal(i,j))g[i].push_back(j);
		for(i=0;i<len;i++)dp[i]=0;
		dag(0);
	/*	for(i=0;i<len;i++){
			printf("g[%d]:",i);
			for(j=0;j<g[i].size();j++)printf("%d ",g[i][j]);
			printf("\n");
			}
		for(i=0;i<len-1;i++)printf("%d ",dp[i]);*/
		printf("%d\n",dp[0]);
		}
	return 0;
	}
