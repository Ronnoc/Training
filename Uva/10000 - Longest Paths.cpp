#include<stdio.h>
#include<vector>
std::vector<int>q[110];
int dp[110];
int max(int a,int b){
	if(a>b)return a;
	return b;
	}
int min(int a,int b){
	if(a<b)return a;
	return b;
	}
int dag(int x){
	if(dp[x]!=-1)return dp[x];
	dp[x]=0;
	int i;
	for(i=0;i<q[x].size();i++)dp[x]=max(dp[x],1+dag(q[x][i]));
	return dp[x];
	}
int back(int x){
	std::vector<int>p;
	if(dp[x]==0)return x;
	int i;
	for(i=0;i<q[x].size();i++){
		if(dp[ q[x][i] ]==dp[x]-1){
			p.push_back(q[x][i]);
			}
		}
	int res=100;
	for(i=0;i<p.size();i++){
		res=min(res,back(p[i]));
		}
	return res;
	}
int main(){
	int n;
	int t=0;
	while(scanf("%d",&n)!=EOF&&n){
		int bn;
		scanf("%d",&bn);
		int i;
		for(i=1;i<=n;i++)q[i].clear();
		for(i=1;i<=n;i++)dp[i]=-1;
		int z,x;
		while(scanf("%d%d",&z,&x)!=EOF){
			if(z==0&&x==0)break;
			q[z].push_back(x);
			}
	//	if(t)printf("\n");
		dag(bn);
		int res=back(bn);
		printf("Case %d: The longest path ",++t);
		printf("from %d has length %d, finishing at %d.\n\n",bn,dp[bn],res);
		}
	return 0;
	}
