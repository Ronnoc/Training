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
#include <assert.h>
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
const int MXN = 200000+5;
const LL MOD = 1000000007;
int w[MXN],y[MXN],aa[MXN],bb[MXN];
int s[22][MXN];
int ct[22][MXN];
int solve( int l,int r,int k,int *x,int *y ) {
	if ( l==r )return x[l];
	int i,w=x[l],p=l,q=r;
	for ( i=l+1; i<=r; i++ ) {
		if ( x[i]<w )y[p++]=x[i];
		else y[q--]=x[i];
	}
	y[p]=w;
	int sml=p-l;
	if ( sml==k )return w;
	if ( sml<k )return solve( p+1,r,k-sml-1,y,x );
	return solve( l,p-1,k,y,x );
}
void build( int l,int r,int h ) {
	int i;
	if ( l==r ) return;
	int mid=( l+r )/2;
	for ( i=l; i<=r; i++ )aa[i]=s[h][i];
	int fm=solve( l,r,mid-l,aa,bb );
	int cnt=0,L=l,R=mid+1;
	for ( i=l; i<=r; i++ ) {
		if ( s[h][i]<=fm )
			cnt++,s[h+1][L++]=s[h][i];
		else s[h+1][R++]=s[h][i];
		ct[h][i]=cnt;
	}
	build( l,mid,h+1 );
	build( mid+1,r,h+1 );
}
int query( int L,int R,int l,int r,int k,int h ) {
	if ( L==R )return w[L];
	int mid=( L+R )/2;
	int a,b,c,d;
	if ( l>L )a=ct[h][l-1],b=l-L-ct[h][l-1];
	else a=0,b=0;
	c=ct[h][r];
	d=r-L+1-c;
	int tl=c-a;
	if ( k<=tl )return query( L,mid,L+a,L+c-1,k,h+1 );
	else return query( mid+1,R,mid+1+b,mid+d,k-tl,h+1 );
}
int main() {
	int i,j;
	int n,m;
	scanf( "%d%d",&n,&m );
	for ( i=0; i<n; i++ ) {
		scanf( "%d",&s[0][i] );
		w[i]=s[0][i];
	}
	build( 0,n-1,0 );
	sort( w,w+n );
	while ( m-- ) {
		int l,r,k;
		scanf( "%d%d%d",&l,&r,&k );
		printf( "%d\n",query( 0,n-1,l-1,r-1,k,0 ) );
	}
	return 0;
}
/*
7 100
7 3 2 4 6 5 1
1 1 1 2 2 1 3 3 1 4 4 1 5 5 1 6 6 1 7 7 1
1 7 1 1 7 2 1 7 3 1 7 4 1 7 5 1 7 6 1 7 7
2 6 1 2 6 2 2 6 3 2 6 4 2 6 5
*/
