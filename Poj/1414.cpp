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
int n,m;
bool inside( int x,int y ) {
	if ( x<=0||x>n )return 0;
	if ( y<=0||y>x )return 0;
	return 1;
}
int dx[]= {-1,-1, 0,0,1,1};
int dy[]= {-1, 0,-1,1,0,1};
int mp[22][22];
int qi[22][22];
int clr[22][22],CLR;
int main() {
	int i,j,k;
	while ( ~scanf( "%d%d",&n,&m )&&n&&m ) {
		memset( mp,0,sizeof mp );
		for ( i=1; i<=n; i++ )for ( j=1; j<=i; j++ )
				scanf( "%d",&mp[i][j] );
		memset( qi,0,sizeof qi );
		memset( clr,0,sizeof clr );
		CLR=0;
		map<int,int>M;
		map<int,int>P;
		M.clear(),P.clear();
		for ( i=1; i<=n; i++ )for ( j=1; j<=i; j++ )if ( mp[i][j] ) {
					if ( !clr[i][j] )clr[i][j]=++CLR;
					else continue;
					P[CLR]=mp[i][j]==m?-1:1;
					int vis[22][22];
					memset( vis,0,sizeof vis );
					queue<PII>Q;
					Q.push( MP( i,j ) );
					while ( !Q.empty() ) {
						int x=Q.front().AA;
						int y=Q.front().BB;
						Q.pop();
						if ( vis[x][y] )continue;
						else vis[x][y]=1,clr[x][y]=CLR,M[CLR]++;
						for ( k=0; k<6; k++ ) {
							int p=x+dx[k];
							int q=y+dy[k];
							if ( !inside( p,q ) )continue;
							if ( mp[p][q]==mp[i][j] )Q.push( MP( p,q ) );
							else if ( mp[p][q] );
							else vis[p][q]=-1;
						}
					}
					qi[i][j]=0;
					for ( int ii=1; ii<=n; ii++ )for ( int jj=1; jj<=ii; jj++ )
							if ( vis[ii][jj]<0 )qi[i][j]++;
					for ( int ii=1; ii<=n; ii++ )for ( int jj=1; jj<=ii; jj++ )
							if ( clr[ii][jj]==CLR )qi[ii][jj]=qi[i][j];
				}
		int ans=-MOD;
		vector<int>S;
		for ( i=1; i<=n; i++ )for ( j=1; j<=i; j++ ) {
				if ( mp[i][j] )continue;
				S.clear();
				int alive=0;
				for ( k=0; k<6; k++ ) {
					int p=i+dx[k];
					int q=j+dy[k];
					if ( !inside( p,q ) )continue;
					if ( mp[p][q]==m&&qi[p][q]>=2 )alive=1;
					if ( mp[p][q]==0 )alive=1;
					if ( qi[p][q]==1 )S.PB( clr[p][q] );
				}
				SORT( S );
				S.erase( unique( S.OP,S.ED ),S.ED );
				int now=0;
				if ( !alive )now--;
				for ( k=0; k<S.SZ; k++ ) {
					if ( P[S[k]]>0 )now+=M[S[k]];
					else if ( !alive )now-=M[S[k]];
				}
				cmax( ans,now );
			}
		printf( "%d\n",ans );
	}
	return 0;
}
