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
/*
*TarjanEBCC
*/
const int M =4444;
const int N = 1111;
struct edgenode {
	int v, next, n;
} edge[2*M];
int last[N], tot;
int n, m;
int dfn[N], low[N], belong[N], instack[N], nindex, ncnt;
stack<int> sta;
void addedge(int x, int y) {
	edge[tot].v = y;
	edge[tot].next = last[x];
	last[x] = tot++;
}
void init() {
	tot = 0;
	memset(last, -1, sizeof(last));
	scanf("%d%d", &n, &m);
	int x, y;
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
}
void Tarjan(int u, int from) {
	dfn[u] = low[u] = nindex++;
	instack[u] = 1;
	sta.push(u);
	int v;
	for(int j = last[u]; -1 != j; j = edge[j].next) {
		if(j == from) continue;
		v = edge[j].v;
		if(0 == dfn[v]) {
			Tarjan(v, j ^ 1);
			if(low[u] > low[v])
				low[u] = low[v];
		}
		else if(instack[v]) {
			if(low[u] > dfn[v])
				low[u] = dfn[v];
		}
	}
	if(dfn[u] == low[u]) {
		ncnt++;
		do {
			v = sta.top();
			instack[v] = 0;
			sta.pop();
			belong[v] = ncnt;
		}
		while(v != u);
	}
}

int deg[N];
void solve() {
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, 0, sizeof(instack));
	memset(belong, 0, sizeof(belong));
	ncnt = 0;
	nindex = 0;
	int flag = 0;
	for(int i = 1; i <= n; i++)
		if(0 == belong[i]) {
			Tarjan(i, -1);
			flag++;
		}
	memset(deg,0,sizeof deg);
	///*
	int u;
	vector<PII>L;
	for(u=1;u<=n;u++){
		int bu=belong[u],bv;
		for(int j = last[u]; -1 != j; j = edge[j].next){
			int v=edge[j].v;
			bv=belong[v];
			if(bu!=bv)L.PB(MP(min(bu,bv),max(bu,bv)));
		}
	}
	sort(L.OP,L.ED);
	L.erase(unique(L.OP,L.ED),L.ED);
	for(int i=0;i<L.SZ;i++)
		deg[L[i].AA]++;
	for(int i=0;i<L.SZ;i++)
		deg[L[i].BB]++;
	int cnt=0;
	for(int i=1;i<=n;i++)if(deg[i]){
		if(deg[i]==1)cnt++;
	}
	printf("%d\n",(cnt+1)/2);
	//*/
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,T;
	init();
	solve();
	return 0;
}
