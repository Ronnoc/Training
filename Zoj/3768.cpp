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
vector<int>L,S;
int solve( int n,int cnt ) {
	if ( cnt==0 )return n==0;
	if ( n<0 )return 0;
	int id=lower_bound( L.OP,L.ED,-n )-L.OP;
	for ( int i=id; n+2*L[i]<=0; i++ )
		if ( solve( n+L[i],cnt-1 ) ) {
			S.PB( L.SZ-i );
			return 1;
		}
	return 0;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( i=1;; i++ ) {
		int tp=1LL*( 1+i )*i/2;
		if ( tp>123456789 )break;
		else L.PB( -tp );
	}
	SORT( L );
	int ii=1,jj=1;
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n;
		scanf( "%d",&n );
		int m=n,cnt=0;
		while ( n ) {
			int id=lower_bound( L.OP,L.ED,-n )-L.OP;
			n+=L[id];
			cnt++;
		}
		for ( int i=1; i<=cnt; i++ ) {
			S.clear();
			if ( solve( m,i ) )break;
		}
		printf( "%d",S[0] );
		for ( i=1; i<S.SZ; i++ )printf( " %d",S[i] );
		printf( "\n" );
	}
	return 0;
}
