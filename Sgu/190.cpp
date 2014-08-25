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
const double PI=acos ( -1. );
const LL MOD = 1000000007;

int lm[1666],rm[1666],vis[1666];
vector<int>G[1666];
int dfs ( int u ) {
	int i;
	if ( vis[u] ) return 0;
	vis[u]=1;
	for ( i=0; i<G[u].SZ; i++ ) {
		int v=G[u][i];
		if ( rm[v]==-1||dfs ( rm[v] ) ) {
			lm[u]=v;
			rm[v]=u;
			return 1;
		}
	}
	return 0;
}
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int ID[44][44];
int lx[1666],rx[1666];
int ly[1666],ry[1666];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,u,v;
	int n,m;
	while ( ~scanf ( "%d%d",&n,&m ) ) {
		memset ( ID,0,sizeof ID );
		for ( i=1; i<=m; i++ ) {
			scanf ( "%d%d",&u,&v );
			ID[u][v]=-1;
		}
		int lid=0,rid=0;
		for ( i=1; i<=n; i++ )
			for ( j=2-i%2; j<=n; j+=2 ) if ( ~ID[i][j] ) {
					ID[i][j]=++lid;
					lx[lid]=i,ly[lid]=j;
				}
		for ( i=1; i<=n; i++ )
			for ( j=2- ( i+1 ) %2; j<=n; j+=2 ) if ( ~ID[i][j] ) {
					ID[i][j]=++rid;
					rx[rid]=i,ry[rid]=j;
				}
		for ( i=1; i<=lid; i++ ) G[i].clear();
		for ( i=1; i<=n; i++ )
			for ( j=2-i%2; j<=n; j+=2 ) if ( ~ID[i][j] ) {
					for ( k=0; k<4; k++ ) {
						int x=i+dx[k],y=j+dy[k];
						if ( x<1||x>n ) continue;
						if ( y<1||y>n ) continue;
						if ( ~ID[x][y] ) G[ID[i][j]].PB ( ID[x][y] );
					}
				}
		memset ( lm,-1,sizeof lm );
		memset ( rm,-1,sizeof rm );
		int match=0;
		for ( i=1; i<=lid; i++ ) if ( lm[i]==-1 ) {
				memset ( vis,0,sizeof vis );
				match+=dfs ( i );
			}
		if ( match*2!=lid+rid ) puts ( "No" );
		else {
			puts ( "Yes" );
			vector<PII>A,B;
			for(i=1;i<=lid;i++){
				if(lx[i]==rx[lm[i]])A.PB(MP(lx[i],min(ly[i],ry[lm[i]])));
				else B.PB(MP(min(lx[i],rx[lm[i]]),ly[i]));
			}
			SORT(A),SORT(B);
			printf("%d\n",B.SZ);
			for(i=0;i<B.SZ;i++)printf("%d %d\n",B[i].AA,B[i].BB);
			printf("%d\n",A.SZ);
			for(i=0;i<A.SZ;i++)printf("%d %d\n",A[i].AA,A[i].BB);
		}
	}
	return 0;
}
