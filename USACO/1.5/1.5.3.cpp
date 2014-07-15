/*
ID: kybconn1
PROG: pprime
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ size()
#define OP begin()
#define ED end()
vector<int>G;
bool isprime( int m ) {
	if ( m<=1 )return 0;
	for ( int i=2; i*i<=m; i++ )if ( m%i==0 )return 0;
	return 1;
}
int main() {
	freopen( "pprime.in", "r", stdin );
	freopen( "pprime.out", "w", stdout );
	int i,j,p,q;
	for ( i=1; i<10000; i++ ) {
		char ss[6];
		sprintf( ss,"%d",i );
		string s=ss;
		string d=s;
		reverse( d.OP,d.ED );
		string a=s+d;
		string b=s.substr( 0,s.SZ-1 )+d;
		istringstream ain( a ),bin( b );
		int A,B;
		ain>>A;
		bin>>B;
		if ( isprime( A ) )G.PB( A );
		if ( isprime( B ) )G.PB( B );
	}
	sort( G.OP,G.ED );
	while ( cin>>p>>q ) {
		int l=lower_bound( G.OP,G.ED,p )-G.OP;
		for ( i=l; G[i]<=q&&i<G.SZ; i++ )printf( "%d\n",G[i] );
	}
	return 0;
}
