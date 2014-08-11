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
	int n;
	int w[32][32];
	mat( int _n=0 ):n( _n ) {memset( w,0,sizeof w );}
	void Unit( int _n ) {
		memset( w,0,sizeof w );
		n=_n;
		for ( int i=0; i<n; i++ )w[i][i]=1;
	}
	void Swap( int a,int b ) {
		for ( int i=0; i<n; i++ )swap( w[a][i],w[b][i] );
	}
	void kill( int a,int b ) {
		for ( int i=0; i<n; i++ )w[a][i]^=w[b][i];
	}
	void show( bool flag=1 ) {
		for ( int i=0; i<n; i++,printf( "\n" ) )
			for ( int j=0; j<n; j++ )printf( " %d",w[i][j] );
		if ( flag )printf( "\n" );
	}
};
mat matMul( mat A,mat B ) {
	mat ret( A.n );
	for ( int i=0; i<A.n; i++ )for ( int j=0; j<A.n; j++ )
			if ( A.w[i][j] )for ( int k=0; k<A.n; k++ )
					ret.w[i][k]^=B.w[j][k];
	return ret;
}
mat matPow( mat A,LL n ) {
	mat ret;
	ret.Unit( A.n );
	while ( n ) {
		if ( n&1 )ret=matMul( A,ret );
		A=matMul( A,A );
		n>>=1;
	}
	return ret;
}
mat matInv( mat A ) {
	mat ret;
	int i,j,n=A.n;
	ret.Unit( n );
	for ( i=0; i<n; i++ ) {
		for ( j=i; j<n; j++ )if ( A.w[j][i] )break;
		A.Swap( i,j );
		ret.Swap( i,j );
		for ( j=0; j<n; j++ )if ( j!=i&&A.w[j][i] ) {
				A.kill( j,i );
				ret.kill( j,i );
			}
	}
	return ret;
}
int M1[33],M2[33];
int S[33],T[33],X[33];
pair<LL,LL>L[50000],R[50000];
void gao( mat &A,int *S ) {
	int i,j,n=A.n;
	for ( i=0; i<n; i++ ) {
		X[i]=0;
		for ( j=0; j<n; j++ )
			X[i]^=A.w[i][j]&S[j];
	}
	for ( i=0; i<n; i++ )S[i]=X[i];
}
LL Hash( int *S,int n ) {
	LL ret=0;
	for ( int i=0; i<n; i++ )ret=ret<<1|S[i];
	return ret;
}
int main() {
	int n,m1,m2;
	int i,j;
	while ( ~scanf( "%d%d%d",&n,&m1,&m2 ) ) {
		mat per( n+1 );
		for ( i=1; i<n; i++ )per.w[i-1][i]=1;
		per.w[n][n]=1;
		for ( i=0; i<m1; i++ )scanf( "%d",&M1[i] );
		for ( i=0; i<m2; i++ )scanf( "%d",&M2[i] );
		for ( S[n]=1,i=0; i<n; i++ )scanf( "%d",&S[i] );
		for ( T[n]=1,i=0; i<n; i++ )scanf( "%d",&T[i] );
		for ( i=0; i<m1; i++ )per.w[n-1][ M1[i]-1 ]=1;
		for ( i=0; i<m2; i++ )per.w[M2[i]-1][n]=1;
		LL step=sqrt( 1.0*( 1LL<<n )+eps )+2;
		mat inv=matInv( per );
		mat temp=matMul( per,inv );
		per=matPow( per,step );
		for ( i=0; i<step; i++ ) {
			R[i]=MP( Hash( T,n ),i );
			L[i]=MP( Hash( S,n ),step*i );
			gao( inv,T );
			gao( per,S );
		}
		sort( R,R+step );
		LL ans=-1;
		for ( i=0; i<step; i++ ) {
			int id=lower_bound( R,R+step,MP( L[i].AA,-1LL ) )-R;
			if ( R[id].AA==L[i].AA ) {
				ans=R[id].BB+L[i].BB;
				break;
			}
		}
		if ( ans==-1 )printf( "poor sisyphus\n" );
		else printf( "%I64d\n",ans );
	}
	return 0;
}
