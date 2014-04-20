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
const int MXN = 100050;
const LL MOD = 1000000007;

int fa[111111];
int dph[111111];
int BIT[MXN+10];
vector<PII>G[111111];
vector<int>son[111111];
int ans[MXN];

int LB( int w ) {return w&( -w );}
int query( int w ) {
	int ret=0;
	for ( w+=5; w>0; w-=LB( w ) )ret=(ret+BIT[w])%MOD;
	return ret;
}
void update( int w,int d ) {
	for ( w+=5; w<MXN; w+=LB( w ) )BIT[w]=(BIT[w]+d)%MOD;
}
int dfsdph( int u ) {
	if ( dph[u]!=-1 )return dph[u];
	return dph[u]=dfsdph( fa[u] )+1;
}
void dfs(int u){
	int i,j;
	for(i=0;i<G[u].SZ;i++)update(G[u][i].AA,G[u][i].BB);
	ans[u]=query(dph[u]);
	for(i=0;i<son[u].SZ;i++)dfs(son[u][i]);
	for(i=0;i<G[u].SZ;i++)update(G[u][i].AA,MOD-G[u][i].BB);
}
int main() {
	int i,j;
	int u,l,r,w;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n;
		scanf( "%d",&n );
		fa[1]=-1;
		for ( i=2; i<=n; i++ )scanf( "%d",&fa[i] );
		memset( dph,-1,sizeof dph );
		memset(BIT,0,sizeof BIT);
		memset(ans,0,sizeof ans);
		dph[1]=1;
		for ( i=2; i<=n; i++ )if ( dph[i]==-1 )dfsdph( i );
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<=n;i++)son[i].clear();
		for(i=2;i<=n;i++)son[fa[i]].PB(i);
		int Q;
		scanf( "%d",&Q );
		while ( Q-- ) {
			scanf( "%d%d%d%d",&u,&l,&r,&w );
			w%=MOD;
			w+=MOD;
			w%=MOD;
			G[u].PB(MP(l,w));
			G[u].PB(MP(r+1,MOD-w));
		}
		dfs(1);
		int ret=0;
		for(i=1;i<=n;i++)ret=(12347LL*ret+ans[i])%MOD;
		printf( "Case %d: %d\n",CASE ,ret);
	}
	return 0;
}
