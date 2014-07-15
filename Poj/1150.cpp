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
int llpow( int a,int x ) {
	int ret=1;
	while ( x ) {
		if ( x&1 )ret=ret*a%10;
		a=a*a%10;
		x/=2;
	}
	return ret;
}
int play3( int L,int R ) {
	while ( ( L%10+10 )%10!=3 )L++;
	while ( ( R%10+10 )%10!=3 )R--;
	if ( L>R )return 0;
	return ( R-L )/10+1;
}
int play7( int L,int R ) {
	while ( ( L%10+10 )%10!=7 )L++;
	while ( ( R%10+10 )%10!=7 )R--;
	if ( L>R )return 0;
	return ( R-L )/10+1;
}
int play9( int L,int R ) {
	while ( ( L%10+10 )%10!=9 )L++;
	while ( ( R%10+10 )%10!=9 )R--;
	if ( L>R )return 0;
	return ( R-L )/10+1;
}
int gao( int L,int R,int &F ) {
	while ( L%10!=5 )L++;
	while ( ( R%10+10 )%10!=5 )R--;
	int ret=1,f;
	F=0;
	if ( L>R )return ret;
	L/=5,R/=5;
	ret*=gao( L,R,F );
	F+=( R-L )/2+1;
	ret=( ret*llpow( 3,play3( L,R ) ) )%10;
	ret=( ret*llpow( 7,play7( L,R ) ) )%10;
	ret=( ret*llpow( 9,play9( L,R ) ) )%10;
//	cout<<L<<" "<<R<<" "<<F<<" "<<ret<<endl;
	return ret%10;
}
int solve( int L,int R,int &T,int &F ) {
//	cout<<"solve "<<L<<" "<<R<<endl;
	assert( L<=R&&L>0 );
	if ( L==R ) {
		T=0,F=0;
		while ( L%2==0 )L/=2,T++;
		while ( L%5==0 )L/=5,F++;
		return L;
	}
	int l=( L+1 )/2,r=R/2;
	int ret=solve( l,r,T,F );
	T+=( r-l )+1;
	ret=( ret*llpow( 3,play3( L,R ) ) )%10;
	ret=( ret*llpow( 7,play7( L,R ) ) )%10;
	ret=( ret*llpow( 9,play9( L,R ) ) )%10;
	int ff;
	ret=ret*gao( L,R,ff )%10;
	F+=ff;
	return ret%10;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int n,m,t,f;
	while ( ~scanf( "%d%d",&n,&m ) ) {
		if ( m==0 ) {printf( "%d\n",1 ); continue;}
		int ret=solve( n-m+1,n,t,f );
		int x=min( t,f );
		t-=x;
		f-=x;
		ret=( ret*llpow( 2,t ) )%10;
		ret=( ret*llpow( 5,f ) )%10;
		printf( "%d\n",ret%10 );
	}
	return 0;
}

