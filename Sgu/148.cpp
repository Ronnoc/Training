#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
vector<int>G[15005];
int pre[15005];
int N;
int W[15005],L[15005],P[15005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	while(~scanf("%d",&N)){
		for(i=1;i<=N;i++)scanf("%d%d%d",&W[i],&L[i],&P[i]);
		int cost=0,ans=P[N],wh=N;
		pre[0]=0;
		for(i=1;i<=N;i++)pre[i]=pre[i-1]+W[i];
		for(i=1;i<=N;i++){
			//pre[i]-L[i]>pre[max_id]
			int id=lower_bound(pre,pre+N+1,pre[i]-L[i])-pre;
			if(~id)G[id].PB(i);
		}
		for(i=N;i>=1;i--){
			cost+=P[i];
			for(j=0;j<G[i].SZ;j++)cost-=P[G[i][j]];
			if(cost<ans)ans=cost,wh=i;
		}
		int now=0;
		for(i=wh;i<=N;i++){
			now+=W[i];
			if(now<=L[i])
				printf("%d\n",i);
		}
	}
	return 0;
}
