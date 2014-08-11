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
	double w[105][105];
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
int main() {
	int i,j;
	int C,N,M;
	while ( scanf( "%d%d%d",&C,&N,&M )==3 ) {
		if ( M>C ) {
			puts( "0.000" );
			continue;
		}
		mat A( C+1 );
		for ( i=0; i<=C; i++ ) {
			if ( i )A.w[i-1][i]=1.0*i/C;
			if ( i<C )A.w[i+1][i]=1-1.0*i/C;
		}
		A=matPow( A,N );
		printf( "%.3f\n",A.w[M][0] );
	}
	return 0;
}
