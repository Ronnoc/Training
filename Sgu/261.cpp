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
LL extGcd( LL a, LL b, LL &x, LL &y ) {
	LL ret = a;
	if ( b ) {
		ret = extGcd( b, a % b, y, x );
		y -= ( a / b ) * x;
	} else x = 1, y = 0;
	return ret;
}
LL modInv( LL a, LL m ) {
	LL x, y;
	extGcd( a,m,x,y );
	return ( m+x%m )%m;
}
LL powMod( LL a,LL b,LL m ) {
	LL ret=1;
	while ( b ) {
		if ( b&1 )ret=ret*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ret;
}
int find_root( int P ) { //P is prime
	if ( P==2 )return 1;
	int Q=P-1;
	vector<int>G;
	int i,j;
	for ( i=2; i*i<=Q; i++ )if ( Q%i==0 ) {
			G.PB( i );
			while ( Q%i==0 )Q/=i;
		}
	if ( Q>1 )G.PB( Q );
	for ( i=2;; i++ ) {
		int flag=1;
		for ( j=0; j<G.SZ; j++ )if ( powMod( i,( P-1 )/G[j],P )==1 ) {flag=0; break;}
		if ( flag )return i;
	}
}
int extBSGS( int A,int B,int C ) { //A^x==B mod C
	for ( int i=0,tmp=1%C; i<100; i++,tmp=1LL*tmp*A%C )if ( tmp==B )return i;
	int temp;
	LL D=1%C;
	int d=0;
	while ( ( temp=__gcd( A,C ) )!=1 ) {
		if ( B%temp )return -1;
		C/=temp,B/=temp;
		d++;
		D=1LL*A/temp*D%C;
	}
	int s=( int )ceil( sqrt( C+eps ) )+1;
	vector<PII>L;
	LL G=1%C;
	for ( int i=0; i<s; i++ ) {
		L.PB( MP( G,i ) );
		G=G*A%C;
	}
	SORT( L );
	for ( int i=0; i<=s; i++ ) {
		int tmp=modInv( D,C )*B%C;
		int id=lower_bound( L.OP,L.ED,MP( tmp,-1 ) )-L.OP;
		if ( id<L.SZ&&id>=0&&L[id].AA==tmp )
			return i*s+L[id].BB+d;
		D=D*G%C;
	}
	return -1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int P,K,A;
	while ( cin>>P>>K>>A ) {
		if ( !A ) {
			printf( "1\n0\n" );
			continue;
		}
		int g=find_root( P );
		int b=extBSGS( g,A,P );
		int f=P-1;
		int e=__gcd( f,K );
		if ( b%e ) {printf( "0\n" ); continue;}
		b/=e,f/=e,K/=e;
		LL x,y;
		extGcd( f,K,x,y );
		set<LL>S;
		y=( y*b%f+f )%f;
		while ( e-- ) {
			S.insert( powMod( g,y,P ) );
			y=( y+f )%( P-1 );
		}
		cout<<S.SZ<<endl;
		for ( set<LL>::iterator it=S.OP; it!=S.ED; ++it )
			cout<<( ( *it ) )<<endl;
	}
	return 0;
}
