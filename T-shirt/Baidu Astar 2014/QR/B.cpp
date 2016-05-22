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
int a[1111],b[1111];
int cal( int x,int y ) {
	int f1=x-y;
	int f2=y-x;
	while ( f1<0 )f1+=360;
	while ( f2<0 )f2+=360;
	return min( f1,f2 );
}
int dl[3][366];
int dr[3][366];
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n;
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ )scanf( "%d%d",&a[i],&b[i] );
		for ( j=0; j<360; j++ )dl[n%2][j]=MOD;
		for ( j=0; j<360; j++ )dr[n%2][j]=MOD;
		dl[n%2][b[n]]=0;
		dr[n%2][b[n]]=0;
		for ( i=n; i>1; i-- ) {
			int x=i%2;
			int y=1-x;
			for ( j=0; j<360; j++ )dl[y][j]=MOD;
			for ( j=0; j<360; j++ )dr[y][j]=MOD;
			for ( j=0; j<360; j++ )if ( dl[x][j]!=MOD ) {
					int le=b[i];
					int re=j;
					int w=dl[x][j];
					cmin( dl[y][re],w+cal( le,b[i-1] ) );
					cmin( dr[y][le],w+cal( re,b[i-1] ) );
				}
			for ( j=0; j<360; j++ )if ( dr[x][j]!=MOD ) {
					int re=b[i];
					int le=j;
					int w=dl[x][j];
					cmin( dl[y][re],w+cal( le,b[i-1] ) );
					cmin( dr[y][le],w+cal( re,b[i-1] ) );
				}
		}
		int ans=MOD;
		for(j=0;j<360;j++)cmin(ans,dl[1][j]+cal(b[i],0)+cal(j,0));
		for(j=0;j<360;j++)cmin(ans,dr[1][j]+cal(b[i],0)+cal(j,0));
		printf( "%d\n",ans+a[n]*2*400+n*10 );
	}
	return 0;
}
