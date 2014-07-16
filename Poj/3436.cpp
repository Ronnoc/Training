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
/*Dinic*/
#define Maxm 500005
#define Maxn 5005
#define INF 0x3f3f3f3f
struct edge {
	int u, v, c, next;
} e[Maxm];
int head[Maxn], cnt;
void init() {
	memset( head, -1, sizeof( head ) );
	cnt = 0;
}
void addedge( int s, int t, int v ) {
	e[cnt].u = s, e[cnt].v = t, e[cnt].c = v;
	e[cnt].next = head[s], head[s] = cnt ++ ;
	e[cnt].u = t, e[cnt].v = s, e[cnt].c = 0;
	e[cnt].next = head[t], head[t] = cnt ++ ;
}
int dis[Maxn], cur[Maxn], sta[Maxn], que[Maxn], pre[Maxn];
bool bfs( int s, int t, int n ) {
	int front = 0, tail = 0;
	memset( dis, -1, sizeof( dis[0] ) * ( n + 1 ) );
	dis[s] = 0;
	que[tail ++ ] = s;
	while ( front < tail ) {
		for ( int i = head[que[front ++ ]]; i != -1; i = e[i].next )
			if ( e[i].c > 0 && dis[e[i].v] == -1 ) {
				dis[e[i].v] = dis[e[i].u] + 1;
				if ( e[i].v == t )
					return 1;
				que[tail ++ ] = e[i].v;
			}
	}
	return 0;
}
int dinic( int s, int t, int n ) {
	int maxflow = 0, tp;
	while ( bfs( s, t, n ) ) {
		for ( int i = 0; i < n; i ++ )
			cur[i] = head[i];
		int u = s, tail = 0;
		while ( cur[s] != -1 ) {
			if ( u == t ) {
				tp = INF;
				for ( int i = tail - 1; i >= 0; i -- )
					tp = min( tp, e[sta[i]].c );
				maxflow += tp;
				for ( int i = tail - 1; i >= 0; i -- ) {
					e[sta[i]].c -= tp;
					e[sta[i] ^ 1].c += tp;
					if ( e[sta[i]].c == 0 )
						tail = i;
				}
				u = e[sta[tail]].u;
			} else if ( cur[u] != -1 && e[cur[u]].c > 0
									&& dis[u] + 1 == dis[e[cur[u]].v] ) {
				sta[tail ++ ] = cur[u];
				u = e[cur[u]].v;
			} else {
				while ( u != s && cur[u] == -1 )
					u = e[sta[ -- tail]].u;
				cur[u] = e[cur[u]].next;
			}
		}
	}
	return maxflow;
}
int ff[55][11],tt[55][11],Q[55];
int fid[55],tid[55];
vector<int>F[1<<11],T[1<<11];
vector<PII>I[1<<11],O[1<<11];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int p,m;
	while ( ~scanf( "%d%d",&p,&m ) ) {
		memset( ff,0,sizeof ff );
		memset( tt,0,sizeof tt );
		memset( Q,0,sizeof Q );
		init();
		map<int,int>X;
		int S=1<<p;
		int n=S+1,TT=S-1;
		for ( i=0; i<S; i++ )F[i].clear();
		for ( i=0; i<S; i++ )T[i].clear();
		for ( i=0; i<S; i++ )I[i].clear();
		for ( i=0; i<S; i++ )O[i].clear();
		for ( i=1; i<=m; i++ ) {
			if ( scanf( "%d",&Q[i] )==EOF )break;
			for ( j=0; j<p; j++ )scanf( "%d",&ff[i][j] );
			for ( j=0; j<p; j++ )scanf( "%d",&tt[i][j] );
			fid[i]=n++;
			tid[i]=n++;
			X[fid[i]]=i;
			X[tid[i]]=i;
			addedge( fid[i],tid[i],Q[i] );
			for ( k=0; k<1<<p; k++ ) {
				int flag=1;
				for ( j=0; j<p; j++ )if ( ff[i][j]==0&&k>>j&1 )flag=0;
				for ( j=0; j<p; j++ )if ( ff[i][j]==1&&( ~k )>>j&1 )flag=0;
				if ( flag )addedge( k,fid[i],Q[i] );
			}
			int to=0;
			for ( j=0; j<p; j++ )if ( tt[i][j] )to|=1<<j;
			addedge( tid[i],to,Q[i] );
		}
		addedge( S,0,MOD );
		int mxf=dinic( S,TT,n );
		for ( i=1; i<cnt; i+=2 ) {
			int u=e[i].v,v=e[i].u,f=e[i].c;
			if ( !f )continue;
			if ( u&&u<TT )O[u].PB( MP( X[v],f ) );
			else if ( v&&v<TT )I[v].PB( MP( X[u],f ) );
		}
		vector<pair<PII,int> >ANS;
		for ( i=0; i<S; i++ ) {
			int l=0,r=0;
			while ( l<I[i].SZ&&r<O[i].SZ ) {
				int c=min( I[i][l].BB,O[i][r].BB );
				ANS.PB( MP( MP( I[i][l].AA,O[i][r].AA ),c ) );
				I[i][l].BB-=c;
				O[i][r].BB-=c;
				if ( !I[i][l].BB )l++;
				if ( !O[i][r].BB )r++;
			}
		}
		cout<<mxf<<" "<<ANS.SZ<<endl;
		for ( i=0; i<ANS.SZ; i++ )cout<<ANS[i].AA.AA<<" "<<ANS[i].AA.BB<<" "<<ANS[i].BB<<endl;
	}
	return 0;
}
