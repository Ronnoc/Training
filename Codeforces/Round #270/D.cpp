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

int G[2002][2002];
inline int read() {
	char ch;
	bool flag = false;
	int a = 0;
	while(!((((ch = getchar()) >= '0') && (ch <= '9')) | (ch == '-')));
	if(ch != '-')a = a*10+(ch-'0');
	else flag = true;
	while(((ch = getchar()) >= '0') && (ch <= '9'))
		a = a*10+(ch-'0');
	if(flag) a = -a;
	return a;
}
void write(int a) {
	if(a < 0) 
		putchar('-'),a = -a;
	if(a >= 10)
		write(a / 10);
	putchar(a % 10 + '0');
}
vector<pair<int,PII> >L,T;
int fa[3333];
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);}
vector<PII>g[2222];
LL z[2009][2009];
void dfs(int u,int f,LL w,int root){
	z[root][u]=w;
	for(int i=0;i<g[u].SZ;i++){
		int v=g[u][i].AA;
		int d=g[u][i].BB;
		if(v==f)continue;
		dfs(v,u,w+d,root);
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n;
	n=read();
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			G[i][j]=read();
	int fail=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j)
				if(G[i][j]==0)fail=1;
	if(fail){
		printf("NO\n");
		return 0;
	}
	L.clear();
	L.resize(n*n);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			L.PB(MP(G[i][j],MP(i,j)));
	sort(L.OP,L.ED);
	for(i=0;i<n;i++)fa[i]=i;
	T.clear();
	for(i=0;i<L.SZ;i++){
		int fu=getfa(L[i].BB.AA);
		int fv=getfa(L[i].BB.BB);
		if(fu!=fv){
			fa[fu]=fv;
			T.PB(L[i]);
		}
	}
	for(i=0;i<n;i++)g[i].clear();
	for(i=0;i<T.SZ;i++){
		int u=T[i].BB.AA;
		int v=T[i].BB.BB;
		int w=T[i].AA;
		g[u].PB(MP(v,w));
		g[v].PB(MP(u,w));
	}
	for(i=0;i<n;i++){
		dfs(i,-1,0,i);
		for(j=0;j<n;j++)if(z[i][j]!=G[i][j])fail=1;
	}
	if(fail)printf("NO\n");
	else printf("YES\n");
	return 0;
}
