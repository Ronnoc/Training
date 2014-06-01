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
/*Dinic*/
#define M 5000000
#define N 100005
#define INF 0x3f3f3f3f
struct edge {
	int u, v, c, next;
} edge[M];
int last[N], tot;
void init() {
	memset( last, -1, sizeof( last ) );
	tot = 0;
}
void addedge( int s, int t, int v ) {
	edge[tot].u = s, edge[tot].v = t, edge[tot].c = v;
	edge[tot].next = last[s], last[s] = tot ++ ;
	edge[tot].u = t, edge[tot].v = s, edge[tot].c = 0;
	edge[tot].next = last[t], last[t] = tot ++ ;
}
int dist[N], cur[N], sta[N], que[N], pre[N];
bool bfs( int s, int t, int n ) {
	int front = 0, tail = 0;
	memset( dist, -1, sizeof( dist[0] ) * ( n + 1 ) );
	dist[s] = 0;
	que[tail ++ ] = s;
	while ( front < tail ) {
		for ( int i = last[que[front ++ ]]; i != -1; i = edge[i].next )
			if ( edge[i].c > 0 && dist[edge[i].v] == -1 ) {
				dist[edge[i].v] = dist[edge[i].u] + 1;
				if ( edge[i].v == t )
					return 1;
				que[tail ++ ] = edge[i].v;
			}
	}
	return 0;
}
int dinic( int s, int t, int n ) {
	int maxflow = 0, tp;
	while ( bfs( s, t, n ) ) {
		for ( int i = 0; i < n; i ++ )
			cur[i] = last[i];
		int u = s, tail = 0;
		while ( cur[s] != -1 ) {
			if ( u == t ) {
				tp = INF;
				for ( int i = tail - 1; i >= 0; i -- )
					tp = min( tp, edge[sta[i]].c );
				maxflow += tp;
				for ( int i = tail - 1; i >= 0; i -- ) {
					edge[sta[i]].c -= tp;
					edge[sta[i] ^ 1].c += tp;
					if ( edge[sta[i]].c == 0 )
						tail = i;
				}
				u = edge[sta[tail]].u;
			} else if ( cur[u] != -1 && edge[cur[u]].c > 0
									&& dist[u] + 1 == dist[edge[cur[u]].v] ) {
				sta[tail ++ ] = cur[u];
				u = edge[cur[u]].v;
			} else {
				while ( u != s && cur[u] == -1 )
					u = edge[sta[ -- tail]].u;
				cur[u] = edge[cur[u]].next;
			}
		}
	}
	return maxflow;
}
int p[105][505];
int q[105][505];
int can[105][505];
int nid;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main() {
	freopen( "C-small-attempt0.in","r",stdin );
	freopen( "C-small-attempt0.out","w",stdout );
	int i,j,k;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		init();
		int w,h,b;
		scanf("%d%d%d",&w,&h,&b);
		int S=0,T=1;
		int nid=1;
		memset(can,0,sizeof can);
		for(int B=0;B<b;B++){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(i=x1;i<=x2;i++)for(j=y1;j<=y2;j++)
				can[i][j]=1;
		}
		for(i=0;i<w;i++)for(j=0;j<h;j++)if(!can[i][j])
			p[i][j]=++nid;
		for(i=0;i<w;i++)for(j=0;j<h;j++)if(!can[i][j])
			q[i][j]=++nid;
		for(i=0;i<w;i++)for(j=0;j<h;j++)if(!can[i][j])
			addedge(p[i][j],q[i][j],1);
		for(i=0;i<w;i++)if(!can[i][0])addedge(S,p[i][0],1);
		for(i=0;i<w;i++)if(!can[i][h-1])addedge(q[i][h-1],T,1);
		for(i=0;i<w;i++)for(j=0;j<h;j++)if(!can[i][j]){
			for(k=0;k<4;k++){
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<0||x>=w)continue;
				if(y<0||y>=h)continue;
				if(can[x][y])continue;
				addedge(q[i][j],p[x][y],1);
			}
		}
		printf("Case #%d: %d\n",CASE,dinic(S,T,nid+2));
	}
	return 0;
}
