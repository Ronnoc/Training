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
const int MXN = 100005;
const LL MOD = 1000000007;
//SGT
struct SEG {
	int l,r;
	LL m;
	LL x;
	SEG() {}
	SEG( int _l,int _r ) {l=_l,r=_r;}
} SGT[MXN<<2];
int a[100005];
void create( SEG &T,int t ) {
	T.m=a[t];
	T.x=a[t];
}
void fresh( SEG &T,SEG &L,SEG &R ) {
	T.x=max( L.x,R.x );
	T.m=L.m+R.m;
}
void build( int id,int l,int r ) {
	SGT[id]=SEG( l,r );
	int mid=( l+r )/2;
	if ( l!=r ) {
		build( id*2,l,mid );
		build( id*2+1,mid+1,r );
		fresh( SGT[id],SGT[id<<1],SGT[id<<1|1] );
	} else create( SGT[id],l );
}
void modulo( int id,int l,int r,int w ) {
	SEG &T=SGT[id];
	int mid=( T.l+T.r )/2;
//	cout<<id<<" "<<l<<"~"<<T.l<<" "<<r<<"~"<<T.r<<" "<<w<<endl;
	if ( T.l==l&&T.r==r ) {
		if ( l==r ) {T.m%=w; T.x%=w; return;}
		else {
			if ( SGT[id<<1].x>=w )modulo( id<<1,l,mid,w );
			if ( SGT[id<<1|1].x>=w )modulo( id<<1|1,mid+1,r,w );
		}
	} else if ( r<=mid )modulo( id<<1,l,r,w );
	else if ( l>mid )modulo( id<<1|1,l,r,w );
	else {
		modulo( id<<1,l,mid,w );
		modulo( id<<1|1,mid+1,r,w );
	}
	fresh( T,SGT[id<<1],SGT[id<<1|1] );
}
LL query( int id,int l,int r ) {
	SEG &T=SGT[id];
	int mid=( T.l+T.r )/2;
	if ( l==T.l&&r==T.r )return T.m;
	if ( r<=mid )return query( id<<1,l,r );
	else if ( l>mid )return query( id<<1|1,l,r );
	else return query( id<<1,l,mid )+query( id<<1|1,mid+1,r );
}
void update( int id,int k,int x ) {
	SEG &T=SGT[id];
	int mid=( T.l+T.r )/2;
	if ( T.l==T.r ) {T.m=T.x=x; return;}
	if ( k>mid )update( id<<1|1,k,x );
	else update( id<<1,k,x );
	fresh( T,SGT[id<<1],SGT[id<<1|1] );
}
int main() {
	int i,j,l,r,x;
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		build(1,1,n);
		while ( m-- ) {
			int Q;
			scanf( "%d",&Q );
			if ( Q==1 ) {
				scanf( "%d%d",&l,&r );
				printf( "%I64d\n",query( 1,l,r ) );
			} else if ( Q==2 ) {
				scanf( "%d%d%d",&l,&r,&x );
				modulo( 1,l,r,x );
			} else if ( Q==3 ) {
				scanf( "%d%d",&l,&x );
				update( 1,l,x );
			}
		}
	}
	return 0;
}
