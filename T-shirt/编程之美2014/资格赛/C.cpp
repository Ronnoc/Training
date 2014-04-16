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
const int MXN = 50;
const LL MOD = 1000000007;
#define rep(i,l,n) for(int i = l; i <= n; i++)
const int MAXR = 10010, MAXC = 210, inf = ( ~0U )>>2;
int n, m, a[MAXR][MAXC], next[MAXC], s, t, c;
inline void orz( int l, int e ) {
	a[l][e] = -1; t = MAXC - 1;
	rep( i,0,m ) if ( a[l][i] ) next[t] = i, t = i; next[t] = -1;
	rep( i,0,n ) if ( i != l && ( t = a[i][e] ) ) {
		a[i][e] = 0;
		for ( int j = next[MAXC - 1]; j != -1; j = next[j] ) a[i][j] += a[l][j] * t;
	}
}
int solve( void ) {
	for ( ;; ) {
		int min = inf, l = 0, e = 0;
		rep( i,1,m ) if ( a[0][i] > 0 ) {e = i; break;}
		if ( !e ) return a[0][0];
		rep( i,1,n ) if ( a[i][e] < 0 && a[i][0] < min ) min = a[i][0], l = i;
		orz( l,e );
	}
}
//	scanf( "%d%d", &m, &n );
//	rep( j,1,m ) scanf( "%d", &a[0][j] );
//	rep( i,1,n ) {
//		scanf( "%d%d%d", &s, &t, &c );
//		rep( j,s,t ) a[i][j] = -1; a[i][0] = c;
//	}
//	printf( "%d\n", solve() );
int w[MAXC][MAXC];
int mm,nn;
int play(int x,int y){
	return (x-1)*nn+y;
}
//Ax=b
//AÎªmÐÐnÁÐ¾ØÕó
//min z=f

int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		scanf( "%d%d",&mm,&nn );
		m=mm+nn;
		n=nn*mm;
		memset(a,0,sizeof a);
		memset(next,0,sizeof next);
		rep(j,1,m)a[0][j]=1;
		for ( i=1; i<=mm; i++ )for ( j=1; j<=nn; j++ ){
			scanf( "%d",&w[i][j] );
			int x=play(i,j);
			a[x][0]=w[i][j];
			a[x][j]=-1;
			a[x][nn+i]=-1;
		}
		printf( "Case %d: %d\n",CASE,solve() );
	}
	return 0;
}
