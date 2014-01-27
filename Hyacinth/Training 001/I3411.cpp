#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
int dp[13][1<<13];
int n,m;
int a[13],b[13],c[13],p[13],r[13];
int dfs(int id,int mask){
//	printf("%d %x\n",id,mask);
	if(id==n-1)return 0;
	int &tp=dp[id][mask];
	if(tp!=-1)return tp;
	tp=INF;
	int i;
	for(i=0;i<m;i++){
		if(a[i]!=id)continue;
		int cost=r[i];
		if(mask>>c[i]&1)cost=min(cost,p[i]);
		int now=dfs(b[i],mask|(1<<b[i]));
		tp=min(tp,now+cost);
	}
	return tp;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		int i,j;
		for(i=0;i<m;i++)scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&p[i],&r[i]);
		for(i=0;i<m;i++)a[i]--,b[i]--,c[i]--;
		memset(dp,-1,sizeof dp);
		int ans=dfs(0,1);
		if(ans==INF)printf("impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
