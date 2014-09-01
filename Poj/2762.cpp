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
const int N = 2005;
const int M = 12005;
struct edgenode {
	int u, v, next;
} edge[2*M];
int tot, last[N],n,m;
int dfn[N], low[N], belong[N], instack[N], ncnt, nindex;
stack<int> sta;

void addedge(int x, int y) {
	edge[tot].u = x;
	edge[tot].v = y;
	edge[tot].next = last[x];
	last[x] = tot++;
}

void init() {   //输入数据
	memset(last, -1, sizeof(last));
	tot = 0;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(x, y);
	}
}

void Tarjan(int u) { //Tarjan
	dfn[u] = low[u] = nindex++;   //给dfn和low赋初始值
	sta.push(u);    //将节点压栈
	instack[u] = 1;
	for(int j = last[u]; j != -1; j = edge[j].next) {
		int v = edge[j].v;
		if(!dfn[v]) {      //未遍历，即未在栈内的节点
			Tarjan(v);
			if(low[u] > low[v])
				low[u] = low[v];
		}
		else if(instack[v] && dfn[v] < low[u]) //已经入栈的节点
			low[u] = low[v];
	}
	if(dfn[u] == low[u]) {    //弹出root及之上的节点， 为一个强连通分量
		//并且标记或者染色
		int i;
		do {
			i = sta.top();
			instack[i] = 0;
			belong[i] = ncnt;
			sta.pop();
		}
		while(i != u);
		ncnt++;
	}
}
int I[1005],O[1005];
vector<int>G[1005];
void solve() {
	init();
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
	memset(I,0,sizeof I);
	memset(O,0,sizeof O);
	for(int i=1;i<=n;i++)G[i].clear();
	for(int u=1;u<=n;u++){
		for(int j = last[u]; j != -1; j = edge[j].next){
			int v=edge[j].v;
			int fu=belong[u],fv=belong[v];
			if(fu!=fv)I[fv]++,G[fu].PB(fv);
		}
	}
	int dph=0,cnt=0;
	ncnt--;
	while(cnt<ncnt){
		++dph;
		queue<int>Q;
		for(int i=1;i<=ncnt;i++)if(!O[i]&&!I[i])Q.push(i);
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			O[u]=1;
			cnt++;
			for(int j=0;j<G[u].SZ;j++){
				int v=G[u][j];
				I[v]--;
			}
		}
	}
	if(dph==ncnt)puts("Yes");
	else puts("No");
}

int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
