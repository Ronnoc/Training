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
deque<int>rope[333];
int MA[320][100005];
int cnt;
PII get( int w ) {
	int i,sum=0;
	for ( i=0; i<=cnt+1; i++ ) {
		if ( sum+rope[i].SZ>w ) {
			return MP( i,w-sum );
		}
		sum+=rope[i].SZ;
	}
	assert( 0 );
}
int play( int w,int k,PII iw ) {
	int ret=0,i;
	for ( i=0; i<iw.AA; i++ )ret+=MA[i][k];
	for ( i=0; i<=iw.BB; i++ )ret+=rope[iw.AA][i]==k;
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,m;
	while ( ~scanf( "%d",&n ) ) {
		cnt=sqrt( n+eps )+eps+1;
		for ( i=0; i<=cnt; i++ )rope[i].clear();
		rope[0].PB( 0 );
		for ( i=1; i<=n; i++ ) {
			scanf( "%d",&j );
			rope[i/cnt].PB( j );
			MA[i/cnt][j]++;
		}
		scanf( "%d",&m );
		int lastans=0;
		while ( m-- ) {
			int q,u,v,w;
			scanf( "%d%d%d",&q,&u,&v );
			if ( q==2 )scanf( "%d",&w );
			u=( u+lastans-1+n )%n+1;
			v=( v+lastans-1+n )%n+1;
			w=( w+lastans-1+n )%n+1;
			if ( u>v )swap( u,v );
			if ( q==1 ) {
				PII iu=get( u );
				PII iv=get( v );
				int what=rope[iv.AA][iv.BB];
				rope[iv.AA].erase( rope[iv.AA].OP+iv.BB );
				MA[iv.AA][what]--;
				rope[iu.AA].insert( rope[iu.AA].OP+iu.BB,what );
				MA[iu.AA][what]++;
			} else {
				lastans=play( v,w,get( v ) )-play( u-1,w,get( u-1 ) );
				printf( "%d\n",lastans );
			}
		}
	}
	return 0;
}
