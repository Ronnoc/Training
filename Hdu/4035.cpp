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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-10;
const LL MOD = 1000000007;
const int MXN=10000+10;
struct edgenode {
	int u, v, next;
} edge[2*MXN];
int tot, last[MXN];
void addedge( int x, int y ) {
	edge[tot].u = x;
	edge[tot].v = y;
	edge[tot].next = last[x];
	last[x] = tot++;
}
int E[MXN],K[MXN];
double C[MXN],F[MXN],P[MXN];
void solve( int u,int fa ) {
	int i,j;
	F[u]=1.0*K[u]/100;
	C[u]=1-( K[u]+E[u] )/100.0;
	P[u]=0;
	for ( j=last[u]; ~j; j=edge[j].next )P[u]+=1;
	P[u]=C[u]/P[u];
	double R=1;
	for ( j=last[u]; ~j; j=edge[j].next ) {
		int v=edge[j].v;
		if ( v==fa )continue;
		solve( v,u );
		F[u]+=P[u]*F[v];
		C[u]+=P[u]*C[v];
		R-=P[u]*P[v];
	}
	F[u]/=R;
	C[u]/=R;
	P[u]/=R;
}
int main() {
	int i,j,k;
	int T,n,u,v;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; CA++ ) {
		scanf( "%d",&n );
		for ( tot=0,i=0; i<=n; i++ )last[i]=-1;
		for ( i=1; i<n; i++ ) {
			scanf( "%d%d",&u,&v );
			addedge( u,v );
			addedge( v,u );
		}
		for ( i=1; i<=n; i++ )scanf( "%d%d",&K[i],&E[i] );
		solve( 1,-1 );
		printf( "Case %d: ",CA );
		if ( fabs( 1-F[1] )<=eps )puts( "impossible" );
		else printf( "%.6f\n",C[1]/( 1-F[1] ) );
	}
	return 0;
}
