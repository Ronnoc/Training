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
	int lazy;
	int w;
	SEG() {}
	SEG( int _l,int _r ) {l=_l,r=_r,lazy=0,w=0;}
} SGT[1000000];
void build( int l,int r,int id ) {
	SGT[id]=SEG( l,r );
	int mid=( l+r )/2;
	if ( l!=r )build( l,mid,id<<1 );
	if ( l!=r )build( mid+1,r,( id<<1 )+1 );
}
void pushup( int id ) {
	if ( !id )return;
	SGT[id].w=max( SGT[id<<1].w,SGT[id*2+1].w );
	pushup( id>>1 );
}
void pushdown( int id,int x,int w ) {
	if ( SGT[id].l==SGT[id].r ) {SGT[id].w=w; pushup( id>>1 ); return;}
	int mid=( SGT[id].l+SGT[id].r )/2;
	if ( x<=mid )pushdown( id*2,x,w );
	else pushdown( id*2+1,x,w );
}
int query( int p,int q,int id ) {
	if ( SGT[id].l==p&&SGT[id].r==q )return SGT[id].w;
	int mid=( SGT[id].l+SGT[id].r )/2;
	if ( q<=mid )return query( p,q,id*2 );
	else if ( p>mid )return query( p,q,id*2+1 );
	else {
		int al=query( p,mid,id*2 );
		int ar=query( mid+1,q,id*2+1 );
		return max( al,ar );
	}
}
int n,q,a[200010];
int main() {
	int i,j,l,r;
	while ( ~scanf( "%d%d",&n,&q ) ) {
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		build( 1,n,1 );
		for(i=1;i<=n;i++)pushdown( 1,i,a[i] );
		for ( j=1; j<=q; j++ ) {
			char s[2];
			scanf( "%s%d%d",s,&l,&r );
			if ( s[0]=='Q' )printf( "%d\n",query( l,r,1 ) );
			else pushdown( 1,l,r );
		}
	}
	return 0;
}
