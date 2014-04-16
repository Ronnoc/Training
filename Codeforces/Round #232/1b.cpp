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
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
LL llpro( LL a, LL b, LL m ) {
	LL ret = 0LL;
	if ( b > a ) swap( a, b );
	while ( b ) {
		if ( b & 1 ) ret = ( a + ret ) % m;
		a = ( a + a ) % m;
		b /= 2;
	}
	return ret;
}
LL power( LL a, LL x, LL m ) {
	LL ret = 1LL;
	while ( x ) {
		if ( x & 1 ) ret = llpro( a, ret, m );
		a = llpro( a, a, m );
		x /= 2;
	}
	return ret;
}
const int S=20;
bool check( LL a,LL n,LL x,LL t ) {
	LL ret=power( a,x,n );
	LL last=ret;
	for ( int i=1; i<=t; i++ ) {
		ret=llpro( ret,ret,n );
		if ( ret==1&&last!=1&&last!=n-1 ) return true;
		last=ret;
	}
	if ( ret!=1 ) return true;
	return false;
}
bool Miller_Rabin( LL n ) {
	if ( n<2 ) return false;
	if ( n==2 ) return true;
	if ( ( n&1 ) ==0 ) return false;
	LL x=n-1, t=0;
	while ( ( x&1 ) ==0 ) {x>>=1; t++;}
	for ( int i=0; i<S; i++ ) {
		LL a=rand() % ( n-1 ) +1;
		if ( check( a,n,x,t ) )return false;
	}
	return true;
}
int main() {
	int i,j;
	int t;
	cin>>t;
	while ( t-- ) {
		LL n;
		cin>>n;
		LL l=n,r=n+1;
		while ( !Miller_Rabin( l ) )l--;
		while ( !Miller_Rabin( r ) )r++;
		LL a=l-2,b=2*l;
		LL p=n-l+1,q=l*r;
		LL g=__gcd(b,q);
		LL qq=q/g*a+b/g*p;
		LL ww=b/g*q;
		g=__gcd(qq,ww);
		qq/=g,ww/=g;
		cout<<qq<<"/"<<ww<<endl;
	}
	return 0;
}
