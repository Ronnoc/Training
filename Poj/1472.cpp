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
vector<string>L;
void solve( int l,int r,int *A ) {
//	for ( int i=l; i<=r; i++ )cout<<L[i]<<" "; cout<<endl;
	int i=l,next=0;
	memset( A,0,sizeof( int )*20 );
	while ( i<=r ) {
		if ( L[i]=="OP" ) {
			istringstream sin( L[i+1] );
			int x;
			sin>>x;
			A[0]+=x;
			i+=2;
			continue;
		}
		if ( L[i]=="LOOP" ) {
			int totend=1;
			int j=i;
			while ( totend ) {
				j++;
				if ( L[j]=="LOOP" )totend++;
				if ( L[j]=="END" )totend--;
			}
			int B[20];
			solve( i+2,j-1,B );
			if ( L[i+1]=="n" ) {
				for ( int k=1; k<20; k++ )A[k]+=B[k-1];
			} else {
				istringstream sin( L[i+1] );
				int x;
				sin>>x;
				for ( int k=0; k<20; k++ )A[k]+=B[k]*x;
			}
			i=j+1;
			continue;
		}
	}
}
void play( int *A ) {
	int i,j;
	bool allzero=1;
	for ( i=0; i<20; i++ )if ( A[i] )allzero=0;
	if ( allzero ) {
		printf( "0\n" );
		return;
	}
	for ( i=19; i>=0; i-- )if ( A[i] ) {
			bool hasnext=0;
			for ( j=0; j<i; j++ )if ( A[j] )hasnext=1;
			if ( A[i]!=1 ||i==0 )printf( "%d",A[i] );
			if ( A[i]!=1&&i )printf( "*" );
			if ( i>1 )printf( "n^%d",i );
			else if ( i )printf( "n" );
			if ( hasnext )printf( "+" );
		}
	printf( "\n" );
}
int main() {
	int i,j;
	int T;
//	int a[20];
//	while ( 1 ) {
//		memset( a,0,sizeof a );
//		for ( i=0; i<3; i++ )scanf( "%d",&a[i] );
//		play( a );
//	}
	cin>>T;
	for ( int CASE=1; CASE<=T; ++CASE ) {
		L.clear();
		string s;
		cin>>s;
		int totend=1;
		while ( totend ) {
			cin>>s;
			L.PB( s );
			if ( s=="LOOP" )totend++;
			if ( s=="END" )totend--;
		}
		int ans[20];
		solve( 0,L.SZ-2,ans );
//		for(i=0;i<20;i++)cout<<ans[i]<<" ";cout<<endl;
		printf( "Program #%d\nRuntime = " ,CASE);
		play( ans );
		printf( "\n" );
	}
	return 0;
}
/*
0 0 0
0 0 1
0 0 2
0 1 0
0 1 1
0 1 2
0 2 0
0 2 1
0 2 2
1 0 0
1 0 1
1 0 2
1 1 0
1 1 1
1 1 2
1 2 0
1 2 1
1 2 2
2 0 0
2 0 1
2 0 2
2 1 0
2 1 1
2 1 2
2 2 0
2 2 1
2 2 2
*/
