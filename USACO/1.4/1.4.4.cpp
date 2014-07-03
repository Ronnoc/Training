/*
ID: kybconn1
PROG: ariprog
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int inS[225000];
int main() {
	freopen( "ariprog.in", "r", stdin );
	freopen( "ariprog.out", "w", stdout );
	int n,m,i,j,k;
	while ( cin>>n>>m ) {
		set<int>S;
		for ( i=0; i<=m; i++ )for ( j=i; j<=m; j++ )
				S.insert( i*i+j*j );
		vector<int>L( S.begin(),S.end() );
		for ( i=0; i<L.size(); i++ )inS[L[i]]=1;
		int got=0;
		int mxd=( L[L.size()-1]-L[0] )/( n-1 );
		for ( int d=1; d<=mxd; d++ ) {
			for ( i=0; L[i]+( n-1 )*d<=L[L.size()-1]; i++ ) if ( inS[L[i]+( n-1 )*d] ) {
					for ( k=1; k<n; k++ )if ( inS[L[i]+k*d]==0 )break;
					if ( k==n )printf( "%d %d\n",L[i],d ),got=1;
				}
		}
		if ( !got )printf( "NONE\n" );
	}
	return 0;
}
