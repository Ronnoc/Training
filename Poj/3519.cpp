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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
int sign( double x ) {return x<-eps?-1:x>eps;}
struct mat {
	double w[205][205];
	int n;
	mat( int _n=0 ):n( _n ) {memset( w,0,sizeof w );}
	void unit( int _n ) {
		n=_n;
		memset( w,0,sizeof w );
		for ( int i=0; i<n; i++ )w[i][i]=1;
	}
	friend mat operator *( mat A,mat B ) {
		mat ret( A.n );
		for ( int i=0; i<A.n; i++ )for ( int j=0; j<A.n; j++ )if ( sign( A.w[i][j] ) )
					for ( int k=0; k<A.n; k++ )ret.w[i][k]+=A.w[i][j]*B.w[j][k];
		return ret;
	}
	friend mat operator +( mat A,mat B ) {
		mat ret( A.n );
		for ( int i=0; i<A.n; i++ )for ( int j=0; j<A.n; j++ )
				ret.w[i][j]=A.w[i][j]+B.w[i][j];
		return ret;
	}
	void output() {
		for ( int i=0; i<n; i++,puts( "" ) ) {
			printf( "%.3f",( int )w[i][0] );
			for ( int j=1; j<n; j++ )printf( " %.3f",( int )w[i][j] );
		}
	}
};
mat matPow( mat A,int B ) {
	mat ret;
	ret.unit( A.n );
	while ( B ) {
		if ( B&1 )ret=ret*A;
		A=A*A;
		B>>=1;
	}
	return ret;
}
double dp[105][205];
int L[205],nl,next;
int B[205],nb;
int N,T;
int main() {
	int i,j,k;
	while ( ~scanf( "%d%d%d%d",&N,&T,&nl,&nb ) ) {
		if ( !N&&!T&&!nl&&!nb )break;
		memset( dp,0,sizeof dp );
		memset( L,0,sizeof L );
		memset( B,0,sizeof B );
		next=N+1;
		dp[0][0]=1;
		for ( i=0; i<nl; i++ ) {
			scanf( "%d",&j );
			L[j]=next;
			L[next]=j;
			next++;
		}
		for ( i=0; i<nb; i++ ) {
			scanf( "%d",&j );
			B[j]=1;
		}
		for ( i=0; i<T; i++ ) {
			for ( j=0; j<N; j++ )if ( sign( dp[i][j] ) ) {
					if ( L[j] )dp[i+1][L[j]]+=dp[i][j];
					else {
						for ( k=1; k<=6; k++ ) {
							int to=j+k;
							if ( to>N )to=N*2-to;
							if ( B[to] )to=0;
							dp[i+1][to]+=dp[i][j]/6.0;
						}
					}
				}
			dp[i+1][N]+=dp[i][N];
			for ( j=N+1; j<next; j++ ) {
				for ( k=1; k<=6; k++ ) {
					int to=L[j]+k;
					if ( to>N )to=N*2-to;
					if ( B[to] )to=0;
					dp[i+1][to]+=dp[i][j]/6.0;
				}
			}
		}
//		for ( i=0; i<=T; i++,printf( "\n" ) )
//			for ( j=0; j<next; j++ )printf( "%.3f\t",dp[i][j] );
		printf( "%.6f\n",dp[T][N] );
	}
	return 0;
}
