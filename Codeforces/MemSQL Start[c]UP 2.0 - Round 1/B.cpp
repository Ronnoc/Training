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
bool fitin( int x,int y,int n,int m ) {
	if ( x<0||x>n )return 0;
	if ( y<0||y>m )return 0;
	return 1;
}
double gao( double a,double b,double c,double d ) {
	return sqrt( SQ( a-c )+SQ( b-d ) );
}
double gao( PII A,PII B ) {
	return gao( A.AA,A.BB,B.AA,B.BB );
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,l;
	int n,m;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		vector<PII>L;
		for ( i=0; i<=4; i++ )for ( j=0; i+j<=4; j++ )
				if ( fitin( i,j,n,m ) )L.PB( MP( i,j ) );
		for ( i=0; i<=4; i++ )for ( j=0; i+j<=4; j++ )
				if ( fitin( n-i,j,n,m ) )L.PB( MP( n-i,j ) );
		for ( i=0; i<=4; i++ )for ( j=0; i+j<=4; j++ )
				if ( fitin( i,m-j,n,m ) )L.PB( MP( i,m-j ) );
		for ( i=0; i<=4; i++ )for ( j=0; i+j<=4; j++ )
				if ( fitin( n-i,m-j,n,m ) )L.PB( MP( n-i,m-j ) );
		SORT( L );
		L.erase( unique( L.OP,L.ED ),L.ED );
//		cout<<L.SZ<<endl;
		double ans=0;
		vector<PII>A;
		for ( i=0; i<L.SZ; i++ )for ( j=0; j<L.SZ; j++ )if ( j!=i )for ( k=0; k<L.SZ; k++ )if ( k!=i&&k!=j )
							for ( l=0; l<L.SZ; l++ )if ( i!=l&&j!=l&&k!=l ) {
									double dis=0;
									dis+=gao( L[i],L[j] );
									dis+=gao( L[j],L[k] );
									dis+=gao( L[k],L[l] );
									if ( dis>ans ) {
										ans=dis;
										A.clear();
										A.PB( L[i] );
										A.PB( L[j] );
										A.PB( L[k] );
										A.PB( L[l] );
									}
								}
		for ( i=0; i<A.SZ; i++ )cout<<A[i].AA<<" "<<A[i].BB<<endl;
	}
	return 0;
}
