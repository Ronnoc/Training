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
int n;
const int MXN = 100005;
vector<PII>G[MXN];
double lg[MXN];
int U[MXN],V[MXN],W[MXN];
int deg[MXN];
int dp[MXN];
int fa[MXN];
void dfsdp(int u,int f){
	int i;
	dp[u]=1;
	fa[u]=f;
	for(i=0;i<G[u].SZ;i++){
		int v=G[u][i].AA;
		if(v==f)continue;
		dfsdp(v,u);
		dp[u]+=dp[v];
	}
}
double g(int x){
	if(x<3)return 0;
	return exp(lg[x]+lg[n-3]-lg[n]-lg[x-3]);
}
double f(int u,int v,int w){
	if(fa[u]==v)return f(v,u,w);
	//fa[v]==u
	int p=dp[v],q=n-dp[v];
	double mis=g(p)+g(q);
	return 2.*(1.-mis)*w;
}
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	lg[0]=0;
	for(i=1;i<=100000;i++)
		lg[i]=lg[i-1]+log(i);
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<n;i++)
			scanf("%d%d%d",&U[i],&V[i],&W[i]);
		memset(deg,0,sizeof deg);
		for(i=1;i<n;i++)
			deg[U[i]]++,deg[V[i]]++;
		for(i=1;i<=n;i++)if(deg[i]==1)break;
		int root=i;
		for(i=1;i<n;i++)
			G[U[i]].PB(MP(V[i],W[i]));
		for(i=1;i<n;i++)
			G[V[i]].PB(MP(U[i],W[i]));
		dfsdp(root,-1);
		double ans=0;
		for(i=1;i<n;i++)
			ans+=f(U[i],V[i],W[i]);
		int nq;
		scanf("%d",&nq);
		while(nq--){
			scanf("%d%d",&j,&k);
			ans-=f(U[j],V[j],W[j]);
			ans+=f(U[j],V[j],W[j]=k);
			printf("%.16f\n",ans);
		}
	}
	return 0;
}
