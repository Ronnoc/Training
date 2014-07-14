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
//SGT
const int MXN = 100000 + 10;
int n,m,a[MXN];
struct SEG {
	int l,r;
	LL w[2][2];
	int lazy;
	SEG() {}
	SEG( int _l,int _r ) {l=_l,r=_r;}
} SGT[MXN<<2];
void create( SEG &T,int t ) {
	T.w[0][0]=T.w[1][0]=1;
	T.w[0][1]=a[t];
	T.w[1][1]=0;
	T.lazy=0;
}
void fresh( SEG &T,SEG &R,SEG &L ) {
	memset( T.w,0,sizeof T.w );
	int i,j,k;
	for ( i=0; i<2; i++ )for ( j=0; j<2; j++ )for ( k=0; k<2; k++ )
				T.w[i][j]+=L.w[i][k]*R.w[k][j]%MOD;
	for ( i=0; i<2; i++ )for ( j=0; j<2; j++ )T.w[i][j]%=MOD;
}
void build( int id,int l,int r ) {
	SGT[id]=SEG( l,r );
	int mid=( l+r )/2;
	if ( l!=r ) {
		build( id<<1,l,mid );
		build( id<<1|1,mid+1,r );
		fresh( SGT[id],SGT[id<<1],SGT[id<<1|1] );
	} else create( SGT[id],l );
}
void update( int id,int l,int r,int w ) {
	SEG &T=SGT[id];
	int mid=( T.l+T.r )/2;
	if ( T.l==l&&T.r==r ) {
	
		return;
	}
	if ( T.lazy ) {
		update( id<<1,l,mid,T.lazy );
		update( id<<1|1,mid+1,r,T.lazy );
		T.lazy=0;
	}
	if ( r<=mid )update( id<<1,l,r,w );
	else if ( l>mid )update( id<<1|1,l,r,w );
	else {
		update( id<<1,l,mid,w );
		update( id<<1|1,mid+1,r,w );
	}
	fresh( T,SGT[id<<1],SGT[id<<1|1] );
}
void query( int id,SEG &A ) {
	SEG &T=SGT[id];
	if ( T.l==A.l&&T.r==A.r ) {A=T; return;}
	int mid=( T.l+T.r )/2;
	if ( A.r<=mid )query( id<<1,A );
	else if ( A.l>mid )query( id<<1|1,A );
	else {
		SEG L( A.l,mid ),R( mid+1,A.r );
		query( id<<1,L );
		query( id<<1|1,R );
		fresh( A,L,R );
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; ++CA ) {
		scanf( "%d%d",&n,&m );
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		build( 1,1,n );
		while ( m-- ) {
			int p,q;
			scanf( "%d%d",&p,&q );
			if ( q<=p+1 )printf( "%d\n",a[q]%MOD );
			else {
				SEG A( p+2,q );
				query( 1,A );
				printf( "%d\n",( A.w[0][0]*a[p+1]+A.w[0][1]*a[p] )%MOD );
			}
		}
		//printf("Case #%d:",CA);
	}
	return 0;
}
