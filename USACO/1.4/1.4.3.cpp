/*
ID: kybconn1
PROG: clocks
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
char s[11][11]= {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int st[11];
int main() {
	freopen( "clocks.in", "r", stdin );
	freopen( "clocks.out", "w", stdout );
	while ( cin>>st[0] ) {
		int i,j;
		for ( i=1; i<9; i++ )cin>>st[i];
		for ( i=0; i<9; i++ )st[i]/=3;
		int sv[11],nsv=1<<25;
		memset( sv,0,sizeof sv );
		for ( int mask=0;; mask++ ) {
			int gao[11],now[11];
			memset( gao,0,sizeof gao );
			memcpy( now,st,sizeof st );
			int tp=mask,itp=0,cnt=0;
			while ( tp ) {
				gao[itp]+=tp%4,cnt+=tp%4;
				tp/=4;
				itp++;
			}
			if ( gao[9] )break;
			for ( i=0; i<9; i++ )for ( j=0; s[i][j]; j++ )
					now[ s[i][j]-'A' ]+=gao[i];
			int ok=1;
			for ( i=0; i<9; i++ )if ( now[i]%4 ) {ok=0; break;}
			if ( ok ) {
				if ( nsv>cnt ) {
					memcpy( sv,gao,sizeof gao );
					nsv=cnt;
				}
			}
		}
		for ( i=0; i<9; i++ )if ( sv[i] ) {sv[i]--; printf( "%d",i+1 ); break;}
		for ( i=0; i<9; i++ )while ( sv[i]-- )printf( " %d",i+1 );
		printf( "\n" );
	}
	return 0;
}
