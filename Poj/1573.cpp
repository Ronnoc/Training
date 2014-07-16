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

char s[22][22];
int d[22][22];
int dx[]= {0,-1, 0,1};
int dy[]= {1, 0,-1,0};
// E  N  W S
int v[22][22];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int n,m,o;
	while ( ~scanf( "%d%d%d",&n,&m,&o ) ) {
		if(!n&&!m&&!o)break;
		for ( i=0; i<n; i++ )scanf( "%s",s[i] );
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if ( s[i][j]=='E' )d[i][j]=0;
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if ( s[i][j]=='N' )d[i][j]=1;
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if ( s[i][j]=='W' )d[i][j]=2;
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )if ( s[i][j]=='S' )d[i][j]=3;
		memset( v,-1,sizeof v );
		int x=0,y=o-1;
		int t=0;
		while ( ++t ) {
			int &D=d[x][y];
			if ( v[x][y]==-1 )v[x][y]=t;
			else {
				printf( "%d step(s) before a loop of %d step(s)\n",v[x][y]-1,t-v[x][y] );
				break;
			}
			x+=dx[D];
			y+=dy[D];
			if ( x<0||x>=n||y<0||y>=m ) {
				printf( "%d step(s) to exit\n",t );
				break;
			}
		}
	}
	return 0;
}
