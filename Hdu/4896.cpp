#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <bitset>
#include <cmath>
using namespace std;

#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define BG begin()
#define ED end()
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define SQ(x) ((x)*(x))

typedef long long LL;
typedef pair<int, int> PII;
int N,seed;
int fa[333333];
int getfa( int u ) {return fa[u]==u?u:fa[u]=getfa( fa[u] );}
LL bruteF() {
	int i,j;
	for ( i=1; i<=N; i++ )fa[i]=i;
	vector<pair<int,PII> >L;
	LL x=seed;
	for ( int i=2; i<=N; i++ ) {
		x=x*907%2333333;
		int T=x;
		for ( int j=max( 1,i-5 ); j<=i-1; j++ ) {
			x=x*907%2333333;
			L.PB( MP( T^x,MP( i,j ) ) );
		}
	}
	sort( L.OP,L.ED );
	LL ans=0;
	for ( i=0; i<L.SZ; i++ ) {
		int u=L[i].BB.AA,v=L[i].BB.BB;
		int fu=getfa( u ),fv=getfa( v );
		if ( fu!=fv ) {
			ans+=L[i].AA,fa[fu]=fv;
		}
	}
	return ans;
}
int cnt[66];
int main() {
	int i, j;
	while ( ~scanf( "%d%d",&N,&seed ) ) {
		if ( N<=1000 ) {
			LL ans=bruteF();
			printf( "%I64d\n",ans );
		} else {
			int k=N%14;
			int n=N;
			vector<LL>G,L,F;
			N=k+42;
			LL last=bruteF();
			set<LL>D;
			G.PB( last );
			L.PB( k+40 );
			int cntwhile=28;
			while ( cntwhile-- ) {
				N+=14;
				LL now=bruteF();
				F.PB( now-last );
				last=now;
				G.PB( now );
				L.PB( N );
			}
			for ( i=1; i<G.SZ; i++ )F.PB( G[i]-G[i-1] );
			int turn;
			for ( i=2; i<F.SZ; i++ )if ( F[i]==F[1]&&F[i-1]==F[0] ) {
					turn=i-1;
					break;
				}
			int T=( n-L[0] )/14;
			int cntturn=T/turn;
			LL ret=G[0];
			LL sum=0;
			for ( i=0; i<turn; i++ )sum+=F[i];
			ret+=sum*cntturn;
			N=L[0]+14*turn*cntturn;
			for ( i=0; i<T%turn; i++ ) {
				ret+=F[i];
				N+=14;
			}
			printf( "%I64d\n",ret );
		}
	}
	return 0;
}
