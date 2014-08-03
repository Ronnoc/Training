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
#define SQ ((x)*(x))
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int,int> PII;

int atk[1010][1010];
vector<PII>Q,K,P;		//1,2,3
int nq,nk,np,n,m;
int dx[]= {0,0,1,-1,1,1,-1,-1};
int dy[]= {1,-1,0,0,1,-1,1,-1};
int kx[]= {1,2,2,1,-1,-2,-2,-1};
int ky[]= {2,1,-1,-2,-2,-1,1,2};
bool valid( int x,int y ) {
	if ( x<1||x>n )return 0;
	if ( y<1||y>m )return 0;
	return 1;
}
int main() {
	int i,j,x,y;
	int CA=0;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		++CA;
		if ( !n&&!m )break;
		for ( i=1; i<=n; i++ )for ( j=1; j<=m; j++ )atk[i][j]=-1;
		Q.clear(),K.clear(),P.clear();
		scanf( "%d",&nq );
		for ( i=0; i<nq; i++ ) {
			scanf( "%d%d",&x,&y );
			Q.PB( MP( x,y ) );
			atk[x][y]=1;
		}
		scanf( "%d",&nk );
		for ( i=0; i<nk; i++ ) {
			scanf( "%d%d",&x,&y );
			K.PB( MP( x,y ) );
			atk[x][y]=2;
		}
		scanf( "%d",&np );
		for ( i=0; i<np; i++ ) {
			scanf( "%d%d",&x,&y );
			P.PB( MP( x,y ) );
			atk[x][y]=3;
		}
		for ( i=0; i<nq; i++ ) {
			int x=Q[i].AA,y=Q[i].BB;
			for ( j=0; j<8; j++ ) {
				int xx=x,yy=y;
				while ( 1 ) {
					xx+=dx[j];
					yy+=dy[j];
					if ( !valid( xx,yy ) )break;
					if ( atk[xx][yy]>0 )break;
					atk[xx][yy]=0;
				}
			}
		}
		for ( i=0; i<nk; i++ ) {
			int x=K[i].AA,y=K[i].BB;
			for ( j=0; j<8; j++ ) {
				int xx=x+kx[j];
				int yy=y+ky[j];
				if ( !valid( xx,yy ) )continue;
				if ( atk[xx][yy]>0 )continue;
				atk[xx][yy]=0;
			}
		}
		int ans=n*m;
		for ( i=1; i<=n; i++ )for ( j=1; j<=m; j++ )if ( ~atk[i][j] )ans--;
		printf( "Board %d has %d safe squares.\n",CA,ans );
	}
	return 0;
}
