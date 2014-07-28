#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define PB push_back
#define MP make_pair
#define AA first
#define SZ size()
#define BB second
char s[99];
vector<int>L;
int v[135][12];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,l,n,w,b;
	int CA=0;
	while ( ~scanf( "%d%d%d",&n,&w,&b ) ) {
		if ( !n&&!w&&!b )break;
		memset( v,0,sizeof v );
		int fi=0;
		vector<int>ANS;
		while ( n-- ) {
			int h;
			scanf( "%d",&h );
			char s[12][12];
			for ( i=0; i<h; i++ )scanf( "%s",s[h-1-i] );
			int a[12][12];
			for ( i=0; i<h; i++ )for ( j=0; j<w; j++ )
					a[i][j]=s[i][j]=='X';
			for ( k=0; k<b+h; k++ ) {
				int fail=0;
				for ( i=0; !fail&&i<h; i++ )for ( j=0; j<w; j++ )if ( a[i][j] )for ( l=i+k; l<b; l++ )
								if ( v[l][j] )fail=1;
				if ( !fail ) {
					int now=0;
					for ( i=0; i<b; i++ )for ( j=0; j<w; j++ )if ( v[i][j] ) {cmax( now,i+1 ); break;}
					for ( i=0; i<h; i++ )for ( j=0; j<w; j++ )
							if ( a[i][j] )v[i+k][j]=1;
					int to=0;
					for ( i=0; i<b; i++ )for ( j=0; j<w; j++ )if ( v[i][j] ) {cmax( to,i+1 ); break;}
//					for ( i=0; i<b; i++,printf( "\n" ) )for ( j=0; j<w; j++ )
//							if ( v[i][j] )putchar( '1' );
//							else putchar( '0' );
					int anew=to>b;
					for ( i=b; i<b+2*h; i++ )for ( j=0; j<w; j++ )if ( v[i][j] )anew=1;
					if ( anew ) {
						ANS.PB( now );
						memset( v,0,sizeof v );
						for ( i=0; i<h; i++ )for ( j=0; j<w; j++ )
								v[i][j]=a[i][j];
					}
					break;
				}
			}
		}
		int now=0;
		for ( i=0; i<b; i++ )for ( j=0; j<w; j++ )if ( v[i][j] ) {cmax( now,i+1 ); break;}
		if ( now!=0 ) ANS.PB( now );
		if ( !ANS.empty() )printf( "%d",ANS[0] );
		for ( i=1; i<ANS.SZ; i++ )printf( " %d",ANS[i] );
		printf( "\n" );
	}
	return 0;
}
/*
2 3 3
3
XX.
.XX
XX.
1
X..
*/
