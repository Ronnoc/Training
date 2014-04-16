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
int dp[155][155*155];
int prv[155][155*155];
int find( int x,int y ) {
	while ( x>2 ) {
		y-=dp[x][y];
		x--;
	}
	return dp[x][y];
}
int main() {
//	freopen("C-large.in","r",stdin);
//	freopen("C-large.out","w",stdout);
	int i,j,k;
	memset( dp,0,sizeof dp );
	for ( i=2; i<=150; i++ )dp[2][i*2]=i;
	for ( i=2; i<=150; i++ )for ( j=4; j<=i*150; j++ )if ( dp[i][j] ) {
				int mx=dp[i][j];
				int know=prv[i][j];
				for ( k=2; k<=mx; k++ ) {
					if ( dp[i+1][j+k] ) {
						int pre=prv[i][j+k-dp[i+1][j+k]];
						if ( pre>know )dp[i+1][j+k]=k,prv[i+1][j+k]=know;
					} else dp[i+1][j+k]=k,prv[i+1][j+k]=know;
				}
			}
	int x[9][9];
	int T;
	scanf( "%d",&T );
	char s[166];
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int r,c,m;
		scanf( "%d%d%d",&r,&c,&m );
		printf( "Case #%d:\n",CASE );
		int remain=r*c-m;
		if ( r==1 ) {
			for ( i=0; i<m; i++ )s[i]='*';
			for ( ; i+1<c; i++ )s[i]='.';
			s[i]='c';
			s[++i]='\0';
			printf( "%s\n",s );
			continue;
		}
		if ( c==1 ) {
			for ( i=0; i<m; i++ )printf( "*\n" );
			for ( i=m; i+1<r; i++ )printf( ".\n" );
			printf( "c\n" );
			continue;
		}
		if ( remain==1 ) {
			char x[155][155];
			for ( i=0; i<r; i++ )for ( j=0; j<c; j++ )x[i][j]='*';
			for ( i=0; i<r; i++ )x[i][c]='\0';
			x[0][0]='c';
			for ( i=0; i<r; i++ )printf( "%s\n",x[i] );
			continue;
		}
		if ( remain==2||remain==3 ) {
			printf( "Impossible\n" );
			continue;
		}
		char p[155][155];
		for ( i=0; i<r; i++ )for ( j=0; j<c; j++ )p[i][j]='*';
		for ( i=0; i<r; i++ )p[i][c]='\0';
		int flag=1;
		for ( i=2; i<=r; i++ )if ( dp[i][remain]&&find( i,remain )<=c ) {
				flag=0;
				vector<int>L;
				int x=i,y=remain;
				while ( x>2 ) {
					L.PB( dp[x][y] );
					y-=dp[x][y];
					x--;
				}
				L.PB( dp[x][y] );
				L.PB( dp[x][y] );
				reverse( L.OP,L.ED );
//				for ( j=0; j<L.SZ; j++ )cout<<L[j]<<" "; cout<<endl;
				for(j=0;j<L.SZ;j++)while(L[j]){
					p[j][L[j]-1]='.';
					L[j]--;
				}
				p[0][0]='c';
				for ( j=0; j<r; j++ )printf( "%s\n",p[j] );
				break;
			}
		if ( flag )printf( "Impossible\n" );
	}
	return 0;
}
