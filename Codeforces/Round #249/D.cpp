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
char s[808][808];
int w[808][808];
int dx[]= {1,1,-1,-1,1,1,-1,-1};
int dy[]= {0,0,0,0,  1,1,-1,-1};
int n,m;
int dp[]= {0,0,0,0,   -1,1,-1,1};
int dq[]= {1,-1,1,-1, 1,-1,1,-1};
int sum[5][808][808];
bool valid( int x,int y ) {
	if ( x<0||y<0 )return 0;
	if ( x>=n||y>=m )return 0;
	return 1;
}
void init() {
	memset( sum,0,sizeof sum );
	memset( w,0,sizeof w );
	int i,j;
	for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )w[i][j]=s[i][j]-'0';
	for ( i=0; i<=n; i++ ) {
		sum[0][i][0]=w[i][0];
		for ( j=1; j<m; j++ )sum[0][i][j]=sum[0][i][j-1]+w[i][j];
	}
	for ( j=0; j<=m; j++ ) {
		sum[1][j][i]=w[i][j];
		for ( i=1; i<n; i++ )sum[1][j][i]=sum[1][j][i-1]+w[i][j];
	}
	for ( i=0; i<=n+m; i++ ) {
		sum[2][i][0]=w[i][0];
		for ( j=1; j<=i; j++ )sum[2][i][j]=sum[2][i][j-1]+w[i-j][j];
	}
	for ( i=400-m; i<=n+400; i++ ) {
		int x=0,y=400-i;
		while ( y<0 )x++,y++;
		sum[3][i][x]=w[x][y];
		while ( valid( x,y ) ) {
			x++,y++;
			sum[3][i][x]=sum[3][i][x-1]+w[x][y];
		}
	}
}
int what( int id,int x,int y ) {
	return sum[id][x][y];
}
int query( int x,int y,int p,int q ) {
	if ( x==p )return ( what( 0,x,max( y,q ) )-what( 0,x,min( y,q ) ) );
	if ( y==q )return ( what( 1,y,max( x,p ) )-what( 1,y,min( x,p ) ) );
	if ( x+y==p+q )return ( what( 2,x+y,max( y,q ) )-what( 2,x+y,min( y,q ) ) );
	if ( x-y==p-q )return ( what( 3,x-y+400,max( x,p ) )-what( 3,x-y+400,min( x,p ) ) );
}
int main() {
	int i,j;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		for(i=0;i<n;i++)for(j=0;j<m;j++)s[i][j]='0';
		init();
		int ans=0,k;
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if(!w[i][j])for ( k=0; k<8; k++ ) {
					int x=i,y=j,p=i,q=j;
					while ( 1 ) {
						x+=dx[k];
						y+=dy[k];
						p+=dp[k];
						q+=dq[k];
						if ( !valid( x,y ) )break;
						if ( !valid( p,q ) )break;
						if ( w[x][y] )break;
						if ( w[p][q] )break;
						if ( query( x,y,p,q )==0 ) {
							ans++;
						}
					}
				}
		printf( "%d\n",ans );
	}
	return 0;
}
/*
3 5
10000
10010
00001
3 5
00001
10010
10000
3 5
10000
01001
00001
3 5
00001
01001
10000
*/
