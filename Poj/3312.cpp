#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define cmin(x,y) x=min(x,y)
#define PB push_back
#define MP make_pair
#define AA first
#define SZ size()
#define BB second
char s[99];
vector<int>L;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,n,k;
	int CA=0;
	while ( ~scanf( "%d%d",&n,&k ) ) {
		if ( !n&&!k )break;
		L.clear();
		for ( i=1; i<=n; i++ ) {
			scanf( "%s",s );
			int len=strlen( s );
			L.PB( len );
		}
		sort( L.begin(),L.end() );
		int flag=0;
		for ( i=0; i<n; i+=k )
			if ( L[i+k-1]-L[i]>4 )flag=1;
		if ( CA )printf( "\n" );
		CA++;
		printf( "Case %d: ",CA );
		if ( flag )printf( "no\n" );
		else printf( "yes\n" );
	}
	return 0;
}
