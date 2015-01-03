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

char G[333][333];
int fa[333];
int id[333];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int O[333];
vector<int>P[333];
vector<int>Q[333];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++)fa[i]=i;
		for(i=0;i<n;i++)scanf("%d",&id[i]);
		for(i=0;i<n;i++)scanf("%s",G[i]);
		for(i=0;i<n;i++)
		for(j=i;j<n;j++)if(G[i][j]=='1'){
			int u=getfa(i),v=getfa(j);
			fa[u]=v;
		}
		for(i=0;i<n;i++)P[i].clear(),Q[i].clear();
		for(i=0;i<n;i++)
			P[getfa(i)].PB(i),Q[getfa(i)].PB(id[i]);
		for(i=0;i<n;i++){
			sort(P[i].OP,P[i].ED);
			sort(Q[i].OP,Q[i].ED);
			for(j=0;j<P[i].SZ;j++)
				O[P[i][j]]=Q[i][j];
		}
		for(i=0;i<n;i++)printf("%d ",O[i]);
		printf("\n");
	}
	return 0;
}
