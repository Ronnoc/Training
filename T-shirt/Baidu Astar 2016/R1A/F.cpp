#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#include<queue>
#include<iostream>
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
int deg[100005];
vector<int>G[100005];
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		int n,m;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)deg[i]=0,G[i].clear();
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			deg[v]++;
			G[u].PB(v);
		}
		priority_queue<int>Q;
		for(i=1;i<=n;i++)if(!deg[i])Q.push(i);
		int mx=n+1;
		LL ans=0;
		while(!Q.empty()){
			int u=Q.top();Q.pop();
			cmin(mx,u);
			ans+=mx;
			for(i=0;i<G[u].SZ;i++){
				int v=G[u][i];
				deg[v]--;
				if(!deg[v])Q.push(v);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}