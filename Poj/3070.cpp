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
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
typedef long long LL;
int w[505];
LL ans[505];
LL E[505][505];
LL T[505][505];
LL A[505][505];
int main() {
	int i,j,k;
	int n,m,d,K;
	while ( ~scanf( "%d%d%d%d",&n,&m,&d,&K ) ) {
		for ( i=1; i<=n; i++ )scanf( "%d",&w[i] );
		for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )E[i][j]=i==j?1:0;
		for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ ) {
				int t=min( fabs( i-j ),n-fabs( i-j ) );
				if ( t<=d )A[i][j]=1;
				else A[i][j]=0;
			}
		while ( K ) {
			if ( K&1 ) {
				for ( j=1; j<=n; j++ )T[1][j]=0;
				for ( j=1; j<=n; j++ )if ( E[1][j] )for ( k=1; k<=n; k++ )
							T[1][k]+=E[1][j]*A[j][k];
				for ( i=2; i<=n; i++ )for ( j=1; j<=n; j++ )T[i][j]=T[1][( j-1-( i-1 )+n )%n+1 ];
				for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )E[i][j]=T[i][j]%m;
			}
			for ( j=1; j<=n; j++ )T[1][j]=0;
			for ( j=1; j<=n; j++ )if ( A[1][j] )for ( k=1; k<=n; k++ )
						T[1][k]+=A[1][j]*A[j][k];
			for ( i=2; i<=n; i++ )for ( j=1; j<=n; j++ )T[i][j]=T[1][( j-1-( i-1 )+n )%n+1 ];
			for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )A[i][j]=T[i][j]%m;
			K/=2;
		}
		memset( ans,0,sizeof ans );
		for ( i=1; i<=n; i++ )for ( j=1; j<=n; j++ )
				ans[i]+=E[i][j]*w[j];
		vector<int>L;
		for ( i=1; i<=n; i++ )L.PB( ans[i]%m );
		printf( "%d",L[0] );
		for ( i=1; i<L.SZ; i++ )printf( " %d",L[i] );
		printf( "\n" );
	}
	return 0;
}

