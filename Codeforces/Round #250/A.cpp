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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
vector<int>G[1010];
int w[1010];
int f[1010];
int del[1010];
int main(){
	int i,j;
	int n,m,u,v;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<=n;i++)scanf("%d",&w[i]);
		for(i=1;i<=n;i++)f[i]=0;
		for(i=1;i<=n;i++)del[i]=0;
		for(i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			f[u]+=w[v];
			f[v]+=w[u];
			G[u].PB(v);
			G[v].PB(u);
		}
		set<PII >S;
		for(i=1;i<=n;i++)S.insert(MP(-w[i],i));
		int ans=0;
		while(!S.empty()){
			PII tp=*S.begin();
			S.erase(S.begin());
			u=tp.BB;
//			cout<<u<<" "<<tp.AA<<endl;
			del[u]=1;
			ans+=f[u];
			for(i=0;i<G[u].SZ;i++){
				int v=G[u][i];
				if(del[v])continue;
				f[v]-=w[u];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
