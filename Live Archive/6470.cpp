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
int sg[101][101][101];
int dfs( int p,int q,int r ) {
	int &tp=sg[p][q][r];
	if ( tp!=-1 )return tp;
	tp=0;
	int i;
	for ( i=2; i<=p; i++ )if ( !dfs( i-1,min( i-1,q ),min( i-1,r ) ) )return tp=1;
	for ( i=1; i<=q; i++ )if ( !dfs( p,i-1,min( i-1,r ) ) )return tp=1;
	for ( i=1; i<=r; i++ )if ( !dfs( p,q,i-1 ) )return tp=1;
	return tp;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	memset( sg,-1,sizeof sg );
	for ( i=0; i<=100; i++ )for ( j=0; j<=i; j++ )for ( k=0; k<=j; k++ )
				if ( sg[i][j][k]==-1 )dfs( i,j,k );
	int T=0,CA;
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d",&CA );
		int p,q,r;
		scanf( "%d%d%d",&p,&q,&r );
		int flag=0,u,v;
		for ( i=2; !flag&&i<=p; i++ )if ( !dfs( i-1,min( i-1,q ),min( i-1,r ) ) )flag=1,u=1,v=i;
		for ( i=1; !flag&&i<=q; i++ )if ( !dfs( p,i-1,min( i-1,r ) ) )flag=1,u=2,v=i;
		for ( i=1; !flag&&i<=r; i++ )if ( !dfs( p,q,i-1 ) )flag=1,u=3,v=i;
		if(flag)printf("%d W %d %d\n",CA,v,u);
		else printf("%d L\n",CA);
	}
	return 0;
}
