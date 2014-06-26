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
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T,CA;
	scanf( "%d",&T );
	while ( T-- ) {
		scanf( "%d",&CA );
		int n;
		scanf( "%d",&n );
		vector<PII>L,R;
		vector<pair<PII,int> >S;
		for ( i=1; i<=n; i++ ) {
			scanf( "%d",&j );
			L.PB( MP( j-1,i ) );
		}
		int flag=1;
		while ( L.SZ>3 ) {
			for ( i=0; i<L.SZ; i++ )
				if ( L[i].AA==0 )break;
			if ( i==L.SZ ) {flag=0; break;}
			int il=( ( i-1 )+L.SZ )%L.SZ;
			int ir=( i+1 )%L.SZ;
			if ( L[il].AA==0 ) {flag=0; break;}
			else L[il].AA--;
			if ( L[ir].AA==0 ) {flag=0; break;}
			else L[ir].AA--;
			R.clear();
			for ( j=0; j<L.SZ; j++ )
				if ( i!=j )R.PB( L[j] );
			int a=L[il].BB,b=L[ir].BB,c=L[i].BB;
			if ( a>b )swap( a,b );
			if ( a>c )swap( a,c );
			if ( b>c )swap( b,c );
			S.PB( MP( MP( a,b ),c ) );
			L=R;
		}
		if ( L.SZ==3 ) {
			int a=L[0].BB,b=L[1].BB,c=L[2].BB;
			if ( a>b )swap( a,b );
			if ( a>c )swap( a,c );
			if ( b>c )swap( b,c );
			S.PB( MP( MP( a,b ),c ) );
		}
		printf( "%d ",CA );
		if ( flag ) {
			printf( "Y\n" );
			SORT( S );
			for ( i=0; i<S.SZ; i++ )printf( "%d %d %d\n",S[i].AA.AA,S[i].AA.BB,S[i].BB );
		} else printf( "N\n" );
	}
	return 0;
}
