#include <vector>
#include <cstdio>
#include <stack>
using namespace std;
#define N 2010
vector<int> G[N];
int main(){
	int t,tt;
	for(scanf("%d",&tt),t=1;t<=tt;t++){
		int n,m,x,y;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)G[i].clear();
		while(m--){
			scanf("%d%d",&x,&y);
			G[x].push_back(y),G[y].push_back(x);
		}
		int flag=1;
		int clr[N];
		for(int i=1;i<=n;i++)clr[i]=-1;
		stack<int>S;
		for(int i=n;i>=1;i--)S.push(i);
		while(!S.empty()){
			int u=S.top();S.pop();
			int p= clr[u]==-1 ? 0: 1-clr[u];
			for(int j=0;j<G[u].size();j++){
				int v=G[u][j];
				if(clr[v]==-1){clr[v]=p;S.push(v);}
				else if(clr[v]!=p)flag=0;
			}
		}
		printf("Scenario #%d:\n",t);
		if(!flag)printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
		if(t!=tt)printf("\n");
	}
	return 0;
}

