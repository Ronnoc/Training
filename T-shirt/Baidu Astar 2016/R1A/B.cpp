#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL dp[1<<16][17];
int vis[1<<16][17];
int a[22];
int limit[22];
int main(){
	int i,j,k,_T;
	int n;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		scanf("%d",&n);
		memset(limit,-1,sizeof limit);
		memset(vis,0,sizeof vis);
		for(i=0;i<n;i++){
			int p;
			scanf("%d%d",&a[i],&p);
			if(~p)limit[p+1]=i;
		}
		a[n]=0;
		dp[0][n]=0;
		vis[0][n]=1;
		for(i=1;i<1<<n;i++){
			int cnt=0;
			for(j=0;j<n;j++)if(i>>j&1)cnt++;
			for(j=0;j<n;j++)if(i>>j&1){
				if(~limit[cnt]&&limit[cnt]!=j)
					continue;
				for(k=0;k<=n;k++)if(vis[i^(1<<j)][k]){
					if(!vis[i][j]){
						vis[i][j]=1;
						dp[i][j]=dp[i^(1<<j)][k]+a[k]*a[j];
					}else 
						cmax(dp[i][j],dp[i^(1<<j)][k]+a[k]*a[j]);
				}
			}
		}
		LL ans=0;
		int vi=0;
		for(i=0;i<n;i++)if(vis[(1<<n)-1][i]){
			if(!vi)ans=dp[(1<<n)-1][i],vi=1;
			else cmax(ans,dp[(1<<n)-1][i]);
		}
		printf("Case #%d:\n",CA);
		printf("%I64d\n",ans);
	}
	return 0;
}