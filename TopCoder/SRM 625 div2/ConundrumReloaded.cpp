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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(p) sort(p.OP,p.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos( -1 );
const LL MOD = 1000000007;
/*
*TarjanSCC_adj_list
*/
const int N=3010;
const int M=3010;

struct edgenode {
	int u, v, next;
} edge[2*M];
int tot, last[N];
int dfn[N], low[N], belong[N], instack[N], ncnt, nindex;
stack<int> sta;

void addedge( int x, int y ) {
//	cout<<x<<"~"<<y<<endl;
	edge[tot].u = x;
	edge[tot].v = y;
	edge[tot].next = last[x];
	last[x] = tot++;
}

void init() {   //输入数据
	memset( last, -1, sizeof( last ) );
	tot = 0;
}

void Tarjan( int u ) { //Tarjan
	dfn[u] = low[u] = nindex++;   //给dfn和low赋初始值
	sta.push( u );  //将节点压栈
	instack[u] = 1;
	for ( int j = last[u]; j != -1; j = edge[j].next ) {
		int v = edge[j].v;
		if ( !dfn[v] ) {   //未遍历，即未在栈内的节点
			Tarjan( v );
			if ( low[u] > low[v] )
				low[u] = low[v];
		} else if ( instack[v] && dfn[v] < low[u] ) //已经入栈的节点
			low[u] = low[v];
	}
	if ( dfn[u] == low[u] ) { //弹出root及之上的节点， 为一个强连通分量
		//并且标记或者染色
		int i;
		do {
			i = sta.top();
			instack[i] = 0;
			belong[i] = ncnt;
			sta.pop();
		} while ( i != u );
		ncnt++;
	}
}

void solve(int n) {
	memset( dfn, 0, sizeof( dfn ) );
	memset( low, 0, sizeof( low ) );
	memset( instack, 0, sizeof( instack ) );
	memset( belong, 0, sizeof( belong ) );
	ncnt = 1;
	nindex = 1;
	for ( int i = 1; i <= n; i++ )
		if ( 0 == dfn[i] ) {
			Tarjan( i );
		}
//	for ( int i = 1; i <= n; i++ )
//		printf( "%d %d\n", i, belong[i] );
}
int st[55];
int kv[111];
int getid(int x){return (x-1)/2;}
int dfsct(int u){
	kv[u]=1;
	int ret=0;
	if(u%2)ret++;
	for ( int j = last[u]; j != -1; j = edge[j].next ) {
		int v = edge[j].v;
		if(!kv[v])ret+=dfsct(v);
	}
	return ret;
}
void dfssv(int u){
	kv[u]=1;
	int uid=getid(u);
	if(u%2)st[uid]=1;else st[uid]=0;
	for ( int j = last[u]; j != -1; j = edge[j].next ) {
		int v = edge[j].v;
		if(!kv[v])dfssv(v);
	}
}
class ConundrumReloaded {
public:
	int minimumLiars( string a ) {
		int ret;
		int i,j;
		init();
		for(int u=0;u<a.SZ;u++){
			int v=(u+1)%a.SZ;
			int ut=u*2+1,uf=u*2+2;
			int vt=v*2+1,vf=v*2+2;
			if(a[u]=='L'){
				addedge(ut,vf);
				addedge(vt,uf);
				addedge(uf,vt);
				addedge(vf,ut);
			}else if(a[u]=='H'){
				addedge(ut,vt);
				addedge(vf,uf);
				addedge(uf,vf);
				addedge(vt,ut);
			}
		}
		solve(2*a.SZ);
		for(i=0;i<a.SZ;i++)
			if(belong[2*i+1]==belong[2*i+2])return -1;
		memset(st,-1,sizeof st);
		for(i=0;i<a.SZ;i++){
			memset(kv,0,sizeof kv);
			int ntl=dfsct(2*i+1);
			memset(kv,0,sizeof kv);
			int ntr=dfsct(2*i+2);
			memset(kv,0,sizeof kv);
			if(ntl>ntr)dfssv(2*i+1);
			else dfssv(2*i+2);
		}
		ret=0;
		for(i=0;i<a.SZ;i++)ret+=st[i];
		return a.SZ-ret;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
