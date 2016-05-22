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
int n,m;
set<int>G[100005];
int main(){
	int i,j,k,_T;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)G[i].clear();
		for(i=0;i<m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].insert(v);
			G[v].insert(u);
		}
		int ans=0;
		queue<int>Q;
		for(i=1;i<=n;i++){
			if(G[i].SZ==0)ans++;
			else if(G[i].SZ==1)Q.push(i);
		}
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			if(G[u].SZ==0)ans++;
			else for (auto v : G[u]){
				G[v].erase(u);
				if(G[v].SZ==1)Q.push(v);
			}
			G[u].clear();
		}
		cout<<ans<<"\n";
	}
	return 0;
}