#include<bits/stdc++.h>
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
vector<int>G[100005];
int fa[100005];
int v[100005];
int a[100005];
vector<int>Ans;
int fail=0;
void dfs(int u,int f){
	if(a[u]==u){
		v[u]=1;
	}else if(~f&&a[u]==a[f]){
		
	}else {
		fail=1;return;
	}
	for(auto v:G[u])
		dfs(v,u);
	if(!fail&&v[u])
		Ans.PB(u);
}
int main(){
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)
			G[i].clear(),fa[i]=-1,v[i]=0;
		Ans.clear();
		fail=0;
		for(i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			fa[v]=u;
			G[u].PB(v);
		}
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)if(fa[i]==-1)
			dfs(i,-1);
		if(!fail){
			printf("%d\n",Ans.SZ);
			for(auto x:Ans)
				printf("%d\n",x);
		}else printf("-1\n");
	}
	return 0;
}