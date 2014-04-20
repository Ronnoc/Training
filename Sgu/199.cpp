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
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
//SGT
const int MXN = 100100;
struct SEG {
	int l,r;
	int m,id;
	SEG() {}
	SEG( int _l,int _r ) {l=_l,r=_r;}
} SGT[MXN<<2];
void create( SEG &T,int t ) {
	T.m=0;
	T.id=-1;
}
void fresh( SEG &T,SEG &L,SEG &R ) {
	if ( L.m>R.m )T.m=L.m,T.id=L.id;
	else T.m=R.m,T.id=R.id;
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
void update( int id,int l,int w,int k ) {
	SEG &T=SGT[id];
	int mid=( T.l+T.r )/2;
	if ( T.l==l&&T.r==l ) {
		if ( T.m<w )T.m=w,T.id=k;
		return;
	}
	if ( l<=mid )update( id<<1,l,w,k );
	else update( id<<1|1,l,w,k );
	fresh( T,SGT[id<<1],SGT[id<<1|1] );
}
void query( int id,int l,int r,SEG &A ) {
	SEG &T=SGT[id];
	int mid=( T.l+T.r )/2;
	if ( T.l==T.r ) {A=T; return;}
	if ( T.l==l&&T.r==r ) {A=T; return;}
	if ( r<=mid )query( id<<1,l,r,A );
	else if ( l>mid )query( id<<1|1,l,r,A );
	else {
		SEG L,R;
		query( id<<1,l,mid,L );
		query( id<<1|1,mid+1,r,R );
		fresh( A,L,R );
	}
}
int n;
int s[MXN];
int b[MXN];
int dp[MXN];
int pre[MXN];
int kk[MXN];
pair<PII,int> L[MXN];
int V[MXN];
int main() {
	int i,j;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=1; i<=n; i++ )pre[i]=-1;
		for ( i=1; i<=n; i++ )scanf( "%d%d",&s[i],&b[i] );
		for ( i=1; i<=n; i++ )V[i-1]=b[i];
		for ( i=1; i<=n; i++ )L[i-1]=MP( MP( s[i],b[i] ),i );
		sort( L,L+n );
		sort( V,V+n );
		int LSZ=n;
		int VSZ=unique( V,V+n )-V;
		build( 1,0,VSZ );
		for ( i=1; i<=n; i++ )kk[i]=lower_bound( V,V+VSZ,b[i] )-V;
		for ( int t=0; t<LSZ; ) {
			int l=t,r=t;
			while ( r<LSZ&&L[r].AA.AA==L[l].AA.AA )r++;
			for ( i=l; i<r; i++ ) {
				int id=L[i].BB;
				int k=kk[id];
				SEG A;
				query( 1,0,k,A );
				pre[id]=A.id;
				dp[id]=A.m+1;
			}
			for ( i=l; i<r; i++ ) {
				int k=kk[L[i].BB];
				update( 1,k+1,dp[L[i].BB],L[i].BB );
			}
			t=r;
		}
		int id=1,mx=dp[1];
		for ( i=2; i<=n; i++ )if ( dp[i]>mx )mx=dp[i],id=i;
		printf( "%d\n",mx );
		while ( pre[id]!=-1 ) {
			printf( "%d ",id );
			id=pre[id];
		}
		printf( "%d\n",id );
	}
	return 0;
}
