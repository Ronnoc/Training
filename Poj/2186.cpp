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
const double PI=acos(-1.);
const LL MOD = 1000000007;
const int M = 100000|3;
const int N = 20000|3;
struct edgenode {
	int u, v, next;
} edge[M|3];
int tot, last[N];
int dfn[N], low[N], belong[N], instack[N], ncnt, nindex;
stack<int>sta;
void addedge(int x, int y) {
	edge[tot].u = x;
	edge[tot].v = y;
	edge[tot].next = last[x];
	last[x] = tot++;
}
int n,m;
void init() {   // ‰»Î ˝æ›
	memset(last, -1, sizeof(last));
	tot = 0;
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(x, y);
	}
}
void Tarjan(int u) {
	dfn[u] = low[u] = nindex++;
	sta.push(u);
	instack[u] = 1;
	for(int j = last[u]; j != -1; j = edge[j].next) {
		int v = edge[j].v;
		if(!dfn[v]) {
			Tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		} else if(instack[v] && dfn[v] < low[u])
			low[u] = low[v];
	}
	if(dfn[u] == low[u]) {
		int i;
		do {
			i = sta.top();
			instack[i] = 0;
			belong[i] = ncnt;
			sta.pop();
		} while(i != u);
		ncnt++;
	}
}
int fa[N];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
int out[N],cnt[N];
void solve() {
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, 0, sizeof(instack));
	memset(belong, 0, sizeof(belong));
	ncnt = 1;
	nindex = 1;
	for(int i = 1; i <= n; i++)
		if(0 == dfn[i]) {
			Tarjan(i);
		}
//	for(int i = 1; i <= n; i++)
//		printf("%d %d\n", i, belong[i]);
	int i;
	for(i=1;i<ncnt;i++)fa[i]=i,out[i]=0,cnt[i]=0;
	for(i=1;i<=n;i++)cnt[belong[i]]++;
	for(i=0;i<m;i++){
		int u=belong[edge[i].u];
		int v=belong[edge[i].v];
		if(u==v)continue;
		fa[getfa(u)]=getfa(v);
		out[u]++;
	}
	int fail=0;
	for(i=2;i<ncnt;i++)if(getfa(i)!=getfa(1))fail=1;
	int tmp=0,ans=-1;
	for(i=1;i<ncnt;i++)if(out[i]==0)tmp++,ans=cnt[i];
	fail|=tmp>1;
	if(fail)ans=0;
	printf("%d\n",ans);
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		solve();
	}
	return 0;
}
