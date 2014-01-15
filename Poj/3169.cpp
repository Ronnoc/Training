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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
int dp[1111];
int iq[1111];
vector<PII>G[1111];
void solve(){
	int i,j;
	int n,p,q;
	while(scanf("%d%d%d",&n,&p,&q)!=EOF){
		int i;
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<n;i++)
			G[i+1].PB(MP(i,0));
		for(i=1;i<=p;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			G[u].PB(MP(v,w));
		}
		for(i=1;i<=q;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			G[v].PB(MP(u,-w));
		}
		for(i=1;i<=n;i++)dp[i]=MOD;
		for(i=1;i<=n;i++)iq[i]=0;
		queue<PII>q;
		q.push(MP(1,0));
		bool fh=0;
		while(!q.empty()){
			PII tp=q.front();
			q.pop();
			int u=tp.AA;
			int t=tp.BB;
			if(dp[u]<t)continue;
			dp[u]=t;
			iq[u]++;
			if(iq[u]>n){fh=1;break;}
			for(i=0;i<G[u].SZ;i++){
				int v=G[u][i].AA;
				int w=G[u][i].BB;
				q.push(MP(v,t+w));
			}
		}
		if(fh)printf("-1\n");
		else if(dp[n]==MOD)printf("-2\n");
		else printf("%d\n",dp[n]);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
