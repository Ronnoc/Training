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
#define AA first
#define BB second
#define MP make_pair
#define PB push_back
int n,m,k;
int vis[22222];
int isp[22222];
bool isprime( int x ) {
	if ( x<2 )return 0;
	for ( int i=2; i*i<=x; i++ )if ( x%i==0 )return 0;
	return 1;
}
bool GOT;
int sum[1111];
int a[1111];
bool check( int h ) {
	for ( int i=h-1; i>=0; i-- ) {
		if ( h-i>=k )break;
		int s;
		if ( i )s=sum[h]-sum[i-1];
		else s=sum[h];
		if ( isp[s] )return 0;
	}
	return 1;
}
void dfs( int h ) {
	if ( h>m-n ) {
		GOT=1;
		return;
	}
	if ( GOT )return;
	for ( int i=n; i<=m; i++ )if ( !vis[i] ) {
			a[h]=i;
			vis[i]=1;
			if ( h )sum[h]=sum[h-1]+a[h];
			else sum[h]=a[h];
			if ( check( h ) )dfs( h+1 );
			if ( GOT )return;
			vis[i]=0;
		}
}
int main() {
	int i,j;
	for ( i=1; i<=20000; i++ )isp[i]=isprime( i );
	while ( scanf( "%d%d%d",&n,&m,&k )!=EOF ) {
		if ( !n&&!m&&!k )break;
		memset( vis,0,sizeof vis );
		GOT=0;
		dfs( 0 );
		if ( GOT ) {
			printf( "%d",a[0] );
			for ( i=1; i<=m-n; i++ )printf( ",%d",a[i] );
			printf( "\n" );
		} else printf( "No anti-prime sequence exists.\n" );
	}
	return 0;
}
