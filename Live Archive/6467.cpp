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
vector<int>S[1010],G[1010];
int rk[1010];
int dfs( int g ) {
	if(rk[g]!=-1)return rk[g];
	rk[g]=1;
	int i;
	int cnt=0;
	for ( i=0; i<S[g].SZ; i++ ) {
		int w=S[g][i];
		int r=dfs(w);
		if ( r>rk[g] )rk[g]=r,cnt=1;
		else if ( r==rk[g] )cnt++;
	}
	if ( cnt>1 )rk[g]++;
	return rk[g];
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,u,v;
	int T,CA;
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d",&CA );
		int M,P;
		scanf( "%d%d",&M,&P );
		for ( i=1; i<=M; i++ )rk[i]=-1;
		for ( i=1; i<=M; i++ )S[i].clear();
		for ( i=1; i<=M; i++ )G[i].clear();
		for ( i=1; i<=P; i++ ) {
			scanf( "%d%d",&u,&v );
			G[u].PB( v );
			S[v].PB( u );
		}
		int ans=0;
		for ( i=1; i<=M; i++ )cmax( ans,dfs( i ) );
		printf( "%d %d\n",CA,ans );
	}
	return 0;
}
