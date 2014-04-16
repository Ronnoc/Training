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
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
struct SEG {
	int l,r;
	bool same;
	int st;
	SEG() {}
	SEG( int _l,int _r ) {l=_l,r=_r,same=1,st=0;}
} SGT[44444];
set<PII>E;
set<int>Q;
void build( int id,int l,int r ) {
	SGT[id]=SEG( l,r );
	int mid=( l+r )/2;
	if ( l!=r )build( id*2,l,mid );
	if ( l!=r )build( id*2+1,mid+1,r );
}
void pushdown( int id,int l,int r,int st ) {
	if ( SGT[id].l==l&&SGT[id].r==r ) {SGT[id].same=1,SGT[id].st=st; return;}
	int mid=( SGT[id].l+SGT[id].r )/2;
	if ( SGT[id].same ) {
		pushdown( id*2,SGT[id].l,mid,SGT[id].st );
		pushdown( id*2+1,mid+1,SGT[id].r,SGT[id].st );
		SGT[id].same=0;
	}
	if ( l>mid ) pushdown( id*2+1,l,r,st );
	else if ( r<=mid ) 	pushdown( id*2,l,r,st );
	else {
		pushdown( id*2,l,mid,st );
		pushdown( id*2+1,mid+1,r,st );
	}
}
void query( int id,int l,int r ) {
	if ( SGT[id].same||SGT[id].r==SGT[id].l ) {Q.insert( SGT[id].st ); return;}
	int mid=( SGT[id].r+SGT[id].l )/2;
	if ( l>mid )query( id*2+1,l,r );
	else if ( r<=mid )query( id*2,l,r );
	else {
		query( id*2,l,mid );
		query( id*2+1,mid+1,r );
	}
}
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	while ( T-- ) {
		E.clear();
		int n;
		scanf( "%d",&n );
		vector<pair<int,PII> >event;
		int x,p,q;
		for ( i=1; i<=n; i++ ) {
			scanf( "%d%d%d",&p,&q,&x );
			event.PB( MP( x,MP( p,q ) ) );
		}
		SORT( event );
		int ans=0;
		build( 1,0,16000 );
		for ( int e=0; e<event.SZ; e++ ) {
			p=event[e].BB.AA*2;
			q=event[e].BB.BB*2;
			Q.clear();
			query( 1,p,q );
			vector<int>Z( Q.OP,Q.ED );
			for ( i=0; i<Z.SZ; i++ )if ( Z[i] )for ( j=i+1; j<Z.SZ; j++ )if ( E.count( MP( Z[i],Z[j] ) ) )
							ans++;
			for ( i=0; i<Z.SZ; i++ )E.insert( MP( Z[i],e+1 ) );
			pushdown( 1,p,q,e+1 );
		}
		printf( "%d\n",ans );
	}
	return 0;
}
