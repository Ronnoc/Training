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
#define SZ size()
deque<int>C[13];
int n;
int a[555];
int ans[44];
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CA=1; CA<=T; CA++ ) {
		scanf( "%d",&n );
		for ( i=0; i<n; i++ )C[i].clear();
		for ( i=0; i<52; i++ )scanf( "%d",&a[i] );
		for ( i=0; i<52; i++ )C[0].push_back( a[i] );
		int turn=0;
		memset( ans,0,sizeof ans );
		while ( turn<777 ) {
			int jump=1;
			for ( i=0; i<n; i++ )if ( !C[i].empty() )jump=0;
			if ( jump )break;
			int change=0;
			int pass[15];
			memset( pass,-1,sizeof pass );
			for ( i=0; i<n; i++ )if ( !C[i].empty() ) {
					ans[i]++;
					if ( ans[i]>13 )ans[i]=1;
					int top=C[i].front();
					C[i].pop_front();
					if ( ans[i]==top )pass[i+1]=top;
					else C[i].PB( top );
				}
			for ( i=0; i<n; i++ )if ( pass[i]!=-1 )C[i].PB( pass[i] ),change=1;
			if ( change )turn=0;
			else turn++;
		}
		printf( "Case %d:",CA );
		if ( turn>=777 )printf( " unwinnable\n" );
		else {
			for ( i=0; i<n; i++ )printf( " %d",ans[i] );
			printf( "\n" );
		}
	}
	return 0;
}
