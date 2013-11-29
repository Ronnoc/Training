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

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
	int to;
	int tp;
}z;
vector<edge>G[111111];
vector<int>ans;
int dfs(int u,int fa,int tp){
	int i;
	int ret=0;
	for(i=0;i<G[u].SZ;i++){
		int v=G[u][i].to;
		if(v==fa)continue;
		ret+=dfs(v,u,G[u][i].tp);
	}
	if(ret<tp-1)ans.PB(u);
	return max(ret,tp-1);
}
void solve(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,x,y,t;
		for(i=1;i<=n;i++)G[i].clear();
		ans.clear();
		for(i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&t);
			z.to=y;z.tp=t;G[x].PB(z);
			z.to=x;z.tp=t;G[y].PB(z);
		}
		printf("%d\n",dfs(1,-1,1));
		for(i=0;i<ans.SZ;i++)printf("%d ",ans[i]);
		printf("\n");
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
