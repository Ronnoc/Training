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

typedef long long LL;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
const double eps = 1e-8;
const LL MOD = 1000000007;
char s[111][111];
int vis[111][111];
int h,w;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
void FF( int x,int y ) {
	if ( x<0||x>=h )return;
	if ( y<0||y>=w )return;
	if ( s[x][y]!='.' )return;
	if ( vis[x][y] )return;
	vis[x][y]=1;
	for ( int k=0; k<4; k++ )FF( x+dx[k],y+dy[k] );
	if ( x+1<h&&y+1<w&&s[x][y+1]=='\\'&&s[x+1][y]=='\\' )FF( x+1,y+1 );
	if ( x>0&&y>0&&s[x-1][y]=='\\'&&s[x][y-1]=='\\' )FF( x-1,y-1 );
	if ( x+1<h&&y>0&&s[x][y-1]=='/'&&s[x+1][y]=='/' )FF( x+1,y-1 );
	if ( x>0&&y+1<w&&s[x][y+1]=='/'&&s[x-1][y]=='/' )FF( x-1,y+1 );
}
int main() {
	int i, j;
//	freopen( "ascii.in", "r", stdin );
//	freopen( "ascii.out", "w", stdout );
	while ( ~scanf( "%d%d",&h,&w ) ) {
		for ( i=0; i<h; i++ )scanf( "%s",s[i] );
		memset( vis,0,sizeof vis );
		for ( i=0,j=0; i<h; i++ )if ( !vis[i][j]&&s[i][j]=='.' )FF( i,j );
		for ( i=0,j=w-1; i<h; i++ )if ( !vis[i][j]&&s[i][j]=='.' )FF( i,j );
		for ( i=h-1,j=0; j<w; j++ )if ( !vis[i][j]&&s[i][j]=='.' )FF( i,j );
		for ( i=0,j=0; j<w; j++ )if ( !vis[i][j]&&s[i][j]=='.' )FF( i,j );
		int cnt=0,edge=0;
		for ( i=0; i<h; i++ )for ( j=0; j<w; j++ )if ( vis[i][j] )cnt++;
		for ( i=0; i<h; i++ )for ( j=0; j<w; j++ )if ( s[i][j]!='.' )edge++;
		int inner=h*w-cnt-edge;
		printf( "%d\n",edge/2+inner );
	}
	return 0;
}
