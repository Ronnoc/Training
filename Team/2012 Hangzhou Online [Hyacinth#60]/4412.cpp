#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
double x[1006];
double p[1006];
double mana[1005][1005];
double line[1005][1005];
double cost[1005][1005];
double dp[1005][55];
bool vis[1005][55];
void update(int i,int j,double e) {
	if(!vis[i][j])dp[i][j]=e;
	else cmin(dp[i][j],e);
	vis[i][j]=1;
}
int main() {
	int i,j,k;
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		if(!n&&!m)break;
		memset(vis,0,sizeof vis);
		map<int,double>MA;
		map<int,double>::iterator it;
		for(i=0; i<n; i++) {
			int z;
			scanf("%d",&z);
			while(z--) {
				int x;
				double p;
				scanf("%d%lf",&x,&p);
				MA[x]+=p;
			}
		}
		n=MA.SZ;
		for(i=1,it=MA.OP; it!=MA.ED; ++it,++i)
			x[i]=(*it).AA,p[i]=(*it).BB;
		for(i=1; i<=n; i++) {
			mana[i][0]=0;
			for(j=1; j<=n; j++){
				mana[i][j]=mana[i][j-1];
				if(j<=i)mana[i][j]+=p[j]*(x[i]-x[j]);
				else mana[i][j]+=p[j]*(x[j]-x[i]);
			}
		}
		for(i=2; i<=n; i++) {
			line[i][0]=0;
			for(j=1; j<=n; j++) {
				line[i][j]=line[i][j-1];
				if(j<i)line[i][j]+=p[j];
				else line[i][j]-=p[j];
			}
		}
		for(i=1; i<=n; i++) {
			int w=i;
			cost[i][i]=0;
			for(j=i+1; j<=n; j++) {
				while(w<j&&line[w+1][j]-line[w+1][i-1]<0)
					w++;
				cost[i][j]=mana[w][j]-mana[w][i-1];
			}
		}
		dp[0][0]=0;
		vis[0][0]=1;
		for(i=0; i<n; i++)
			for(j=0; j<=m; j++)if(vis[i][j]){
				for(k=i+1;k<=n;k++)
					update(k,j+1,dp[i][j]+cost[i+1][k]);
			}
		for(k=m;k>0;k--)
			update(n,k-1,dp[n][k]);
		printf("%.2f\n",dp[n][0]);
	}
	return 0;
}
