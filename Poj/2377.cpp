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

vector<pair<int,PII> >L;
int fa[10005];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)fa[i]=i;
		int ans=0;L.clear();
		for(k=0;k<m;k++){
			scanf("%d%d%d",&i,&j,&T);
			L.PB(MP(-T,MP(i,j)));
		}
		sort(L.OP,L.ED);
		int tot=1;
		for(k=0;k<L.SZ;k++){
			int u=getfa(L[k].BB.AA);
			int v=getfa(L[k].BB.BB);
			if(u!=v)tot++,ans-=L[k].AA,fa[u]=v;
		}
		if(tot<n)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
