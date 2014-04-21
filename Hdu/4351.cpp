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

int play( int x ) {
	if ( x<10 )return x;
	int ret=0;
	while ( x ) {
		ret+=x%10;
		x/=10;
	}
	return play( ret );
}
struct SEG {
	int l,r,w;
	int L,R,S;
	SEG() {}
	SEG( int _l,int _r ) {
		l=_l,r=_r,w=0;
		L=0,R=0,S=0;
	}
} SGT[500000];
int a[111111];
int roll( int msk,int w ) {
	w=play( w );
	int tp1=( msk>>1 )|( ( msk>>1 )<<9 );
	int tp2=tp1>>( 9-w );
	int tp3=tp2&( ( 1<<10 )-1 );
	int ret=( tp3<<1 )|( msk&1 );
	int i;
	return ret;
}
void fresh( SEG &L,SEG &R,SEG &T ) {
	T.w=L.w+R.w;
	int i,j;
	T.S=R.S|L.S;
	for ( i=0; i<=9; i++ )if ( !( T.S>>i&1 )&&i )for ( j=0; j<=9; j++ ) {
				int k=play( i+9-j );
				if ( ( L.R>>j&1 )&&( R.L>>k&1 ) ) {T.S|=1<<i; break;}
			}
	T.L=L.L|( roll( R.L,L.w ) );
	T.R=R.R|( roll( L.R,R.w ) );
}
void build( int id,int l,int r ) {
	SGT[id]=SEG( l,r );
	int mid=( l+r )/2;
	if ( l!=r ) {
		build( id*2,l,mid );
		build( id*2+1,mid+1,r );
		fresh( SGT[id*2],SGT[id*2+1],SGT[id] );
	} else {
		int w=a[l];
		SGT[id].L=1<<w;
		SGT[id].R=1<<w;
		SGT[id].S=1<<w;
		SGT[id].w=w;
	}
}
void query( int id,int p,int q,SEG &T ) {
	if ( SGT[id].l==p&&SGT[id].r==q ) {
		T=SGT[id];
		return;
	}
	int mid=( SGT[id].l+SGT[id].r )/2;
	if ( q<=mid )query( id*2,p,q,T );
	else if ( p>mid )query( id*2+1,p,q,T );
	else {
		SEG L,R;
		query( id*2,p,mid,L );
		query( id*2+1,mid+1,q,R );
		fresh( L,R,T );
	}
}
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	int CASE=0;
	while ( T-- ) {
		if ( CASE )printf( "\n" );
		printf( "Case #%d:\n",++CASE );
		int n,m;
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ ) {
			int x;
			scanf( "%d",&x );
			a[i]=play( x );
		}
		build( 1,1,n );
		scanf( "%d",&m );
		while ( m-- ) {
			int p,q,w;
			scanf( "%d%d",&p,&q );
			SEG T=SEG( p,q );
			query( 1,p,q,T );
			vector<int>Z;
			for ( i=9; i>=0; i-- )if ( T.S>>i&1 )Z.PB( i );
			while ( Z.SZ<5 )Z.PB( -1 );
			printf( "%d",Z[0] );
			for ( i=1; i<=4; i++ )printf( " %d",Z[i] );
			printf( "\n" );
		}
	}
	return 0;
}
