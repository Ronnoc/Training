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
*TarjanPBCC
*/
const int N = 20005;
const int M = 2001005;
struct edge {
	int u, v, w, next;
} edge[2*M];
int last[N], tot,cnt;
int n, m, belong[2*M];
int dfn[N], low[N], ncnt, nindex, iscut[N];
stack<int> sta;
vector<int> ne[N * 3]; //ÐÂÍ¼
bool color[N * 3];

void init() {
	memset(last, -1,sizeof last);
	tot = 0;
}

void addedge(int u, int v) {
	cmax(n,u),cmax(n,v);
	edge[tot].u = u; edge[tot].v = v;
	edge[tot].next = last[u]; last[u] = tot ++ ;
}

void Tarjan(int u, int from) {
	int v, child = 0;
	dfn[u] = low[u] = ++ nindex;
	for(int j = last[u]; j != -1; j = edge[j].next) {
		if(j == from) continue;
		v = edge[j].v;
		if(dfn[v] < dfn[u]) {
			sta.push(j);
			if(!dfn[v]) {
				child ++ ;
				Tarjan(v, j ^ 1);
				low[u] = min(low[u], low[v]);
				if(low[v] >= dfn[u]) {  //¸îµãÅÐ¶Ï
					ncnt++;
					while(sta.top() != j) {
						belong[sta.top() / 2] = ncnt;
						sta.pop();
					}
					belong[j / 2] = ncnt;
					sta.pop();
					iscut[u] = 1;
				}
			}
			else low[u] = min(low[u], dfn[v]);
		}
	}
	if(from < 0 && child == 1) iscut[u] = -1;
}
int T,ans;
int fa[10005],rk[10005];
int getfa(int u) {return fa[u]==u?u:fa[u]=getfa(fa[u]);}
void solve() {
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	memset(iscut,-1,sizeof iscut);
	memset(color,0,sizeof color);
	ncnt = nindex = 0;
	T++;
	for(int i = 1; i <= n; i ++)
		if(!dfn[i]) {
			while(!sta.empty()) sta.pop();
			Tarjan(i, -1);
		}
	for(int u=1; u<=n; u++) {
		int tp;
		if(~iscut[u]) {
			set<int>S;
			for(int j = last[u]; j != -1; j = edge[j].next)
				S.insert(belong[j/2]);
			tp=cnt-1+S.SZ;
		}
		else tp=cnt-1+(rk[getfa(u-1)]>1?1:0);//,cout<<"@";
//		cout<<u<<" "<<tp<<endl;
		cmax(ans,tp);
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,m,u,v;
	T=0;
	while(~scanf("%d%d",&n,&m)&&(n||m)) {
		init();
		for(i=0; i<=n; i++)fa[i]=i,rk[i]=0;
		cnt=n;
		for(i=0; i<m; i++) {
			scanf("%d%d",&u,&v);
			addedge(u+1,v+1);
			addedge(v+1,u+1);
			int fu=getfa(u),fv=getfa(v);
			if(fu!=fv)cnt--,fa[fu]=fv;
		}
		for(i=0; i<n; i++)rk[getfa(i)]++;
		ans=0;
		solve();
		printf("%d\n",ans);
	}
	return 0;
}
