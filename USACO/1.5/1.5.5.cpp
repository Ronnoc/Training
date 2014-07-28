/*
ID: kybconn1
PROG: checker
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int put[15];
int next[15];
int le[33],re[33];
int n;
int cnt;
vector<vector<int> >ANS;
inline int mabs( int x ) {return x<0?-x:x;}
inline bool check( int h ) {
	for ( int i=1; i<h; i++ )if ( mabs( i-h )==mabs( put[i]-put[h] ) )return 0;
	return 1;
}
void dfs( int h ) {
	if ( h==n+1 ) {
		if ( cnt<3 ) {
			printf( "%d",put[1] );
			for ( int i=2; i<h; i++ )printf( " %d",put[i] );
			printf( "\n" );
		}
		cnt++;
		return;
	}
	for ( int i=next[0],pre=0; i<=n; i=next[i] ) {
		put[h]=i;
		if ( !le[h+i]&&!re[h-i+15] ) {
			le[h+i]=1;
			re[h-i+15]=1;
			next[pre]=next[i];
			dfs( h+1 );
			next[pre]=i;
			le[h+i]=0;
			re[h-i+15]=0;
		}
		pre=i;
	}
}
int main() {
	freopen( "checker.in", "r", stdin );
	freopen( "checker.out", "w", stdout );
	int i,j;
	cnt=0;
	while ( ~scanf( "%d",&n ) ) {
		for ( i=0; i<=n; i++ )next[i]=i+1;
		memset( le,0,sizeof le );
		memset( re,0,sizeof re );
		cnt=0;
		dfs( 1 );
		printf( "%d\n",cnt );
	}
	return 0;
}
