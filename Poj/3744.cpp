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
struct mat {
	long double w[5][5];
	int n;
	mat( int _n=0 ):n( _n ) {memset( w,0,sizeof w );}
	friend mat operator * ( mat &A,mat &B ) {
		mat ret( A.n );
		int i,j,k;
		for ( i=0; i<A.n; i++ )for ( j=0; j<A.n; j++ )
				for ( k=0; k<A.n; k++ )ret.w[i][j]+=A.w[i][k]*B.w[k][j];
		return ret;
	}
	void unit( int _n=0 ) {
		n=_n;
		memset( w,0,sizeof w );
		for ( int i=0; i<n; i++ )w[i][i]=1;
	}
};
long double gao( int L,double p ) {
	mat E( 2 ),A( 2 );
	E.unit( 2 );
	L--;
	A.w[0][0]=p;
	A.w[0][1]=1-p;
	A.w[1][0]=1;
	while ( L ) {
		if ( L&1 )E=A*E;
		A=A*A;
		L>>=1;
	}
	return 1-E.w[0][0];
}
int main() {
	int i,j;
	int n;
	double p;
	while ( ~scanf( "%d%lf",&n,&p ) ) {
		vector<int>L;
		while ( n-- ) {
			scanf( "%d",&j );
			L.PB( j );
		}
		SORT( L );
		for ( i=L.SZ-1; i>=1; i-- )
			L[i]=L[i]-L[i-1];
		long double ans=1;
		for ( i=0; i<L.SZ; i++ )ans*=gao( L[i],p );
		printf( "%.7f\n",( double )ans );
	}
	return 0;
}
